#include <SoftwareSerial.h>

SoftwareSerial mongoose(14, 12);

void setup() {
    Serial.begin(9600);
    mongoose.begin(9600);
    Serial.println("hello,mongoose.\r\n");
}

void loop() {
    while (mongoose.available() > 0) {
        Serial.print(char(mongoose.read()));
    }
    while (Serial.available() > 0) {
      //Serial.print(char(Serial.read()));
      mongoose.write(Serial.read());
    }

}
