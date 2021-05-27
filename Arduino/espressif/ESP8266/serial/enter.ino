int inByte;
void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; 
  }
}
int i=0;
char buff[16]={0};
void loop() {
  while (Serial.available() > 0) {
    inByte = Serial.read();
    if(inByte != '\n')
      buff[i++] = (char)inByte;
    else{
      Serial.print("length:%d");
      buff[i] = '\0';
      i=0;
      Serial.println(buff);
    }
  }
}
