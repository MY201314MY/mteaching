#include <Wire.h>
#include <ACROBOTIC_SSD1306.h>

String longitude,latitude;
unsigned char location_flag = 2;
unsigned short sendCommand(char *Command, char *Response, unsigned char Retry)
{
  for (unsigned char n = 0; n < Retry; n++)
  {
    Serial.print("\r\n---------send AT Command:---------\r\n");
    Serial.println(Command);

    Serial2.write(Command);
    delay(500);
    unsigned char i = 0;
    char message[256];
    while (Serial2.available()) {
      message[i++] = char(Serial2.read());
    }
    message[i]='\0';
    if (strstr(message, Response) != NULL)
    {
      Serial.print("\r\n==========receive AT Command:==========\r\n");
      Serial.print(message);
      return 0;
    }
    else{
      Serial.print("\r\n=========== unknown errors ============\r\n");
      Serial.print(message);
    }
    delay(1000);
  }
  return 1;
}
unsigned char GPS(){
  int i = 0;
  char message[1024] = "";
  static unsigned int grade = 0;
  Serial2.write("AT+QGNSSRD=\"NMEA/RMC\"\r\n");
  delay(500);
  while (Serial2.available()) {
    message[i++] = char(Serial2.read());
  }
  Serial.println(message);
  String m = String(message);
  if((m.indexOf(",N,") != -1) && (m.indexOf(",E,") != -1)){
    int p = m.indexOf("+QGNSSRD: $GNRMC");
    int o = m.indexOf("\r\n\r\nOK");
      
    unsigned char buff[16];
    grade++;
    sprintf((char*)buff,"%06d", grade);
    oled.setTextXY(2,7);              
    oled.putString((char*)buff);
          
    String y = m.substring(p, o);
    int po = y.indexOf("$GNRMC");
    String result = y.substring(po, y.length());

    int m = result.indexOf('A');
    result = result.substring((m+2), result.length());
    m = result.indexOf(',');
    latitude = result.substring(0, m);
    Serial.println("****************");
    Serial.print("latitude:");
    Serial.print(latitude);
    Serial.print("  ----  ");

    m = result.indexOf('N');
    result = result.substring((m+2), result.length());
    m = result.indexOf(',');
    longitude = result.substring(0, m);
    Serial.print("longitude:");
    Serial.println(longitude);
    Serial.println("****************");

    oled.setTextXY(3,3);              
    oled.putString(longitude);
    oled.setTextXY(4,4);              
    oled.putString(latitude);
    location_flag=0;   
  }
  else{
    Serial.println("Can't get GPS signal...");
    location_flag=1;
  }
}
unsigned short MQTT_CMD(char *Command, char *Response, bool Publish)
{
  Serial.print("\r\n---------send AT Command:---------\r\n");
  Serial.println(Command);

  Serial2.write(Command);
  if(Publish == true){
    delay(200);
    Serial2.write(0x1A);
  }
  bool flag = false;
  unsigned char i = 0;
  char message[256]={0};

  while(1){
    while (Serial2.available()) {
      char character = char(Serial2.read());
      message[i++] = character;
      if(strstr(message, Response) != NULL){
        Serial.println("ACK");
        flag = true;
        Serial.print("\r\n==========receive AT Command:==========\r\n");
        Serial.print(message);
        return 0;
      }
      if(flag){
        message[i]='\0';
        break;
      }
    }
    if(flag){
      break;
    }
  }
  while(Serial2.available()){
    Serial2.read();
  }
}
void setup() {
  Wire.begin();  
  oled.init();  
  Serial.begin(115200);
  Serial2.begin(115200);
  Serial.println("NB-IOT & GPS Example.\r\nLet's go!");
                  
  oled.clearDisplay();             
  oled.setTextXY(0,0);              
  oled.putString("    MC20E&GPS");
  oled.setTextXY(2,0);              
  oled.putString("Upload:");
  oled.setTextXY(3,0);              
  oled.putString("Lo:00.00");
  oled.setTextXY(4,0);              
  oled.putString("La:00.00");
               
  if (sendCommand("AT\r\n", "OK\r\n", 10) == 0){
    Serial.println("MC20E get ready. . .");
  }
  if (sendCommand("AT+CGREG?\r\n", "+CGREG: 0,1\r\n\r\nOK", 30) == 0){
    Serial.println("MC20E has connect to Network successfully. . .");
  }
  if (sendCommand("AT+QGNSSC?\r\n", "+QGNSSC: 1\r\n\r\nOK", 1) == 0){
    Serial.println("MC20E's GPS has been opened already. . .");
  }
  else if (sendCommand("AT+QGNSSC=1\r\n", "OK\r\n", 1) == 0){
    Serial.println("MC20E's GPS was opened successfully. . .");
  }
  else{
    
  }
  if (MQTT_CMD("AT+QMTCFG=\"VERSION\",0,1\r\n", "OK", false) == 0){
    Serial.println("Set MC20E's protocol. . .");
  }
  if (MQTT_CMD("AT+QMTOPEN=0,\"183.230.40.39\",6002\r\n", "+QMTOPEN: 0,0",false) == 0){
    Serial.println("Try to connect OneNET");
  }
  if (MQTT_CMD("AT+QMTCONN=0,\"47975479\",\"179383\",\"\"\r\n", "+QMTCONN: 0,0,0", false) == 0){
    Serial.println("MC20E connect to ONENET Successfully.");
  }
  delay(2000);
}
bool flag=true;
void loop() {
  if(flag){
    flag = false;
    for(int i=0;i<128;i++){
      GPS();
      if (MQTT_CMD("AT+QMTPUB=0,0,0,0,\"mteaching\"\r\n", ">", false) == 0){
        Serial.println("Open the topic successfully.");
      }
      if(location_flag == 0){
        String location = longitude+"-"+latitude+"\r\n";
        char cArr[location.length() + 1];
        location.toCharArray(cArr,location.length() + 1);
        if (MQTT_CMD(cArr, "+QMTPUB: 0,0,0", true) == 0){
          Serial.println("Send the data successfully.");
        }
      }
      else{
        if (MQTT_CMD("Tring get GPS . . .", "+QMTPUB: 0,0,0", true) == 0){
          Serial.println("Send the data successfully.");
        }
      }
      delay(5000);
    }
    if(MQTT_CMD("AT+QMTDISC=0\r\n", "+QMTDISC: 0,0", false) == 0){
        Serial.println("Disconnect with OneNET");
      }
  }
}

