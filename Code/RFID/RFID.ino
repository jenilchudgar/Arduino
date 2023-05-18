#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create an instance of the MFRC522 class

void setup() {
  Serial.begin(9600);  // Initialize serial communication

  while (!Serial) {
    ; // Wait for serial port to connect
  }

  SPI.begin();  // Initialize SPI bus
  mfrc522.PCD_Init();  // Initialize MFRC522

  Serial.println("Ready to read RFID tags!");
}

void loop() {
  // Check for new cards
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    Serial.print("Card UID: ");
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
      Serial.print(" ");
    }
    Serial.println();

    // Dump debug info
    mfrc522.PICC_DumpToSerial(&(mfrc522.uid));

    mfrc522.PICC_HaltA();  // Halt PICC (card)
    mfrc522.PCD_StopCrypto1();  // Stop encryption on PCD (reader)
  }
}
