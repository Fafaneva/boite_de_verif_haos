#pragma once

#include <Arduino.h>
#include "Signal.h"
#include "Config.h"

void signalInit() {
  pinMode(LED_VERT, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_ROUGE, OUTPUT);
  digitalWrite(LED_VERT, LOW);
  digitalWrite(BUZZER_PIN, LOW);
}

void signalAccepte() {
  digitalWrite(LED_VERT, HIGH);
  digitalWrite(BUZZER_PIN, HIGH);
  delay(100);
  digitalWrite(BUZZER_PIN, LOW);
  delay(50);
  digitalWrite(LED_VERT, LOW);
}

void signalRefuse() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_ROUGE, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(150);
    digitalWrite(LED_ROUGE, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    delay(150);
  }
}