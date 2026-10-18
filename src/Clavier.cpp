#pragma once 

#include <Arduino.h>
#include "Clavier.h"
#include "Config.h"
#include "Signal.h"
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};
byte rowPins[ROWS] = {ROW1, ROW2, ROW3, ROW4};
byte colPins[COLS] = {COL1, COL2, COL3, COL4};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void clavierinit() {
    pinMode(ROW1, INPUT_PULLUP);
    pinMode(ROW2, INPUT_PULLUP);
    pinMode(ROW3, INPUT_PULLUP);
    pinMode(ROW4, INPUT_PULLUP);
    pinMode(COL1, OUTPUT);
    pinMode(COL2, OUTPUT);
    pinMode(COL3, OUTPUT); 
    pinMode(COL4, OUTPUT); 
  // Implementation for keyboard initialization
}

int codedeverrification(const int code) {
  // Lecture du code saisi sur le clavier
    String inputCode = "";  
    while (inputCode.length() < 4) {
        char key = customKeypad.getKey();
        if (key) {
            inputCode += key;
            Serial.print(key); // Affiche le caractère saisi sur le moniteur série
            signalAccepte(); // Appel de la fonction pour signaler l'acceptation
        }
    }
    Serial.println(); // Affiche une ligne vide sur le moniteur série   
  return 0;
}