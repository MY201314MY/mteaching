#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(10, 11); // RX, TX  

void setup() {
  DebugSerial.begin(115200);
  DebugSerial.println("This is an example to test MC20E Moudle.");
}

void loop() {
  DebugSerial.println("Thank you.");
  delay(100);
}
