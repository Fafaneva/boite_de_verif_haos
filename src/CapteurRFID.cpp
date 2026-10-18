#include "CapteurRFID.h"
#include <SPI.h>
#include <MFRC522.h>
#include "Config.h"
#include <Arduino.h>
#include "Signal.h"

static MFRC522 mfrc522(SS_PIN, RST_PIN);
static const byte authorizedCards[3][4] = {
  {0xA3, 0xD2, 0x44, 0x2B}, // Carte 1
  {0xD3, 0x25, 0x4F, 0xA9}, // Carte 2
  {0x13, 0xB9, 0xAA, 0xA5}  // Carte 3
};
static const uint8_t nbrAuthorizedCards = 3;

static bool uidAuthorized(const byte uid[4]) {
    Serial.print("Vérification de l'UID : ");
    bool match = true;
  for (uint8_t c = 0; c < nbrAuthorizedCards; c++) {
    bool match = true;
    for (uint8_t j = 0; j < 4; j++) {
      if (authorizedCards[c][j] != uid[j]) {
        match = false;
        break;
      }
    }
    if (match){
        return true;
    }
  }
  return false;
}

// afficharge de l'UID sur le moniteur série
static void printUID(const byte uid[4]) {
  Serial.print("UID : ");
  for (byte i = 0; i < 4; i++) {

    Serial.print(uid[i], HEX);
    if (i < 3) {
      Serial.print(":");
    }
  }
  Serial.println();
}

void setupRFID() {

    SPI.begin();         
    mfrc522.PCD_Init();
    delay(100);
    Serial.print("Version RC522 : ");
    mfrc522.PCD_DumpVersionToSerial();


}

void verificationRFID(){

  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) return;


  if (mfrc522.uid.size !=4) {
    signalRefuse();
    mfrc522.PICC_HaltA();
    return;
  }

  byte uid[4];
    for (byte i = 0; i < 4; i++) {
        uid[i] = mfrc522.uid.uidByte[i];
    }
    printUID(uid);
    mfrc522.PICC_HaltA(); 


    if (uidAuthorized(uid)) {
        Serial.println("Carte autorisée");
        signalAccepte();
    } else {
        Serial.println("Carte non autorisée");
        signalRefuse();
    }


}