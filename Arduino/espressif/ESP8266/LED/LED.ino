long lastMsg=0;
void setup() {
    pinMode(LED_BUILTIN, OUTPUT);  
}
char flag = 0;
void loop() {
  long now = millis();
  if (now - lastMsg > 200) {
    lastMsg = now;
    if(flag){
      flag = 0;
      digitalWrite(LED_BUILTIN, HIGH);
    } 
    else{
      flag = 1;
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}
