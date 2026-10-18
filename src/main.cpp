#include "CapteurRFID.h"
#include <SPI.h>
#include <MFRC522.h>
#include "Config.h"
#include <Arduino.h>
#include "Signal.h"
#include "Clavier.h"




void setup() {
  Serial.begin(115200);
  setupRFID();
  signalInit();
  clavierinit();
}

void loop() {
  // Double tache pas de verification blocante ou prioritaire, on verifie le code du clavier et le code du RFID en meme temps
  verificationRFID();
  //int code = codedeverrification(1234);

}