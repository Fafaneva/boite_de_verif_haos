#pragma once 

//RF522
#define RST_PIN 22
#define SS_PIN 5


//Signale
#define LED_VERT 2
#define LED_ROUGE 4
#define BUZZER_PIN 16


//CLAVIER   
#define ROW1 32
#define ROW2 33
#define ROW3 25
#define ROW4 14

#define COL1 26
#define COL2 27
#define COL3 12
#define COL4 13

//LCD
//#define LCD_SDA 21
//#define LCD_SCL 22

// Liste des cartes RFID autorisées (UID)
/*const byte authorizedCards[][4] = {
  {0xA3, 0xD2, 0x44, 0x2B}, // Carte 1
  {0xD3, 0x25, 0x4F, 0xA9}, // Carte 2
  {0x13, 0xB9, 0xAA, 0xA5}  // Carte 3
};*/
const byte authorizedCard1[4] = {0xA3, 0xD2, 0x44, 0x2B}; 
const byte authorizedCard2[4] = {0xD3, 0x25, 0x4F, 0xA9}; 
const byte authorizedCard3[4] = {0x13, 0xB9, 0xAA, 0xA5}; 