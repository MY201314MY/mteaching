#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>
SoftwareSerial mongoose(14, 12);

const char* ssid = "Linux";                
const char* password = "Google'S";
const char* mqtt_server = "183.230.40.39";

WiFiClient espClient;
PubSubClient client(espClient);

long lastMsg = 0;
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
void callback(char* topic, byte* payload, unsigned int length) {
  String message=""; 
  char rxbuffer[128];
  char index=0;
  
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("]");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    message+=(char)payload[i];
    rxbuffer[index++] = payload[i];
  }
  rxbuffer[index] = '\0';
  strcat(rxbuffer, "\r\n");
  if(!message.compareTo("ON")){
    digitalWrite(16, LOW);
    Serial.println("\r\nTURN ON THE LED");
    mongoose.write("led 0 on\r\n");
  }else if(!message.compareTo("OFF")){
    digitalWrite(16, HIGH);
    Serial.println("\nTURN OFF THE LED");
    mongoose.write("led 0 off\r\n");
  }else{
    mongoose.write(rxbuffer);
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("509109399","179383","r6VsaTGQVMeYmOujP4xkHFVCXvo=")) {
      Serial.println("connected");
      client.subscribe("espressif");
      client.subscribe("raspberrypi");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
void setup() {
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  pinMode(16, OUTPUT);    
  digitalWrite(16, HIGH);
  mongoose.begin(9600);
  while (mongoose.available() > 0) {
    mongoose.read();
  }
  Serial.begin(115200);
  
  setup_wifi();
  client.setServer(mqtt_server, 6002);
  client.connect("509109399","179383","r6VsaTGQVMeYmOujP4xkHFVCXvo=");
  client.setCallback(callback);
  client.subscribe("espressif");
  client.setCallback(callback);
  digitalWrite(2, HIGH);
  Serial.println("Welcome to muyuan.");
}
bool flag = false;
char cloud_index = 0;
char cloudbuffer[128]={0};
void loop() {
  if (!client.connected()) {
    digitalWrite(2, LOW);
    reconnect();
  }
  else{
    digitalWrite(2, HIGH);
  }
  client.loop();
  if(mongoose.available() > 0){
    while (mongoose.available() > 0) {
      char character = mongoose.read();
      Serial.print(character);
      cloudbuffer[cloud_index++] = character;
      delay(5);
    }
    flag = true;
  }
  if(flag == true){
    flag = false;
    cloudbuffer[cloud_index] = '\0';
    cloud_index = 0;
    client.publish("terminal", cloudbuffer);
  }
}
