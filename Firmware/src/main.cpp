/*
  Boto-Rosa Project
  By Rodrigo Feliciano
  https://www.github.com/pakequis
  https://www.youtube.com/pakequis
  02/06/2024

*/

/* Arduino libs */
#include <Arduino.h>
#include <SPI.h>

/* Project includes */
#include <hardware.h>

/* Project libs */
#include "menus.h"

int test_sw = 0;
int menu_n = 0;
int menu_i = 0;

void setup(void) {
  Serial.begin(9600);
  Serial.print(F("Boto rosa test..."));

  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(SW4, INPUT_PULLUP);
  pinMode(SW5, INPUT_PULLUP);
  pinMode(SW6, INPUT_PULLUP);

  (void)LCD_init();
  Serial.println(F("Initialized"));

}

void loop() 
{

  switch (menu_n)
  {

    case 0:
      (void)show_splash_screen();

    delay(100);

    while(test_sw == 0)
    {
      if(digitalRead(SW1) == 0) test_sw = 1;
      if(digitalRead(SW2) == 0) test_sw = 2;
      if(digitalRead(SW3) == 0) test_sw = 3;
      if(digitalRead(SW4) == 0) test_sw = 4;
      if(digitalRead(SW5) == 0) test_sw = 5;
      if(digitalRead(SW6) == 0) test_sw = 6;
    }
    menu_n = 1;
    test_sw = 0;
  break;


  case 1:
  
    break;

    default:
      
    break;
  }
}