#include <Arduino.h>
#include <SoftwareSerial.h>

const byte rxPin = 9;
const byte txPin = 8;

SoftwareSerial BTSerial(rxPin, txPin);

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);

  BTSerial.begin(9600);
  Serial.begin(9600);
}

String msgBuffer = "";
String msg = "";

void loop() {
  while (BTSerial.available() > 0) {
    char data = (char)BTSerial.read();
    msgBuffer += data;

    if (data == ';') {
      msg = msgBuffer;
      msgBuffer = "";

      Serial.print(msg);

      msg = "You Sent " + msg;
      BTSerial.print(msg);
    }
  }
}