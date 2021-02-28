String inputString = "";  
boolean stringComplete = false;  

void setup() {
  Serial.begin(115200);
  Serial.println("This is a message from Arduino mini pro. . .");
  inputString.reserve(256);
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {            
  if (stringComplete) {
    Serial.print("iMessage:");
    Serial.println(inputString);
    if (inputString == "ON\r\n"){
       digitalWrite(LED_BUILTIN, HIGH);  
    }
    else if(inputString == "OFF\r\n"){
       digitalWrite(LED_BUILTIN, LOW);  
    }
    else{
      ;
    }
    inputString = "";
    stringComplete = false;
  }
}
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}


