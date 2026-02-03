#include <SoftwareSerial.h>

// RX=10, TX=11
SoftwareSerial mySerial(10, 11);

void setup() {
  Serial.begin(9600);
  // RN42のデフォルトボーレートは115200の場合が多いです
  mySerial.begin(9600); 
  Serial.println("Bluetooth AT Command Mode");
}

void loop() {
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}

//slave:MAC ID 000666B87DE4