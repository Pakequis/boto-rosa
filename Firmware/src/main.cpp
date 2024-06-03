/*
  Boto-Rosa Project
  By Rodrigo Feliciano
  https://www.github.com/pakequis
  https://www.youtube.com/pakequis
  02/06/2024

*/

#include <Arduino.h>

#include "hardware_def.h"

// First test 02/06/2024
void setup() {
  /* LCD Backlight pin */
  pinMode(LCD_BACKLIGHT, OUTPUT);
}

/* Blink the LCD backlight */
void loop() {
  digitalWrite(LCD_BACKLIGHT, HIGH);
  delay(1000);
  digitalWrite(LCD_BACKLIGHT, LOW); 
  delay(1000);
}