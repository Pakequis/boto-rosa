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

/* GFX Adafruit libs */
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <Fonts/FreeSansBold12pt7b.h>
#include <Fonts/FreeSansBold24pt7b.h>

#include "hardware_def.h"

/* Images */
#include "boto-img.h"

/* Menus */
#include "LCD_menu.h"

#define TFT_CS    LCD_CS
#define TFT_RST   LCD_RES
#define TFT_DC    LCD_DC

SPIClass *spi = new SPIClass(HSPI);
Adafruit_ST7789 tft = Adafruit_ST7789(spi, TFT_CS, TFT_DC, TFT_RST);

int test_sw = 0;
int menu_n = 0;
int menu_i = 0;

void setup(void) {
  Serial.begin(9600);
  Serial.print(F("Boto rosa test..."));

  pinMode(LCD_BACKLIGHT, OUTPUT);
  digitalWrite(LCD_BACKLIGHT, HIGH);  /* Turn on LCD backlight */

  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(SW4, INPUT_PULLUP);
  pinMode(SW5, INPUT_PULLUP);
  pinMode(SW6, INPUT_PULLUP);

  spi->begin(LCD_SCL, -1, LCD_SDA, TFT_CS);

  tft.init(170, 320);           // Init ST7789 170x320

  // SPI speed
  //tft.setSPISpeed(10000000);

  Serial.println(F("Initialized"));
  
  /* LCD start */
  tft.setRotation(3);
  tft.fillScreen(WHITE);

  tft.setFont(&FreeSansBold12pt7b);
}

void loop() 
{

  switch (menu_n)
  {

    case 0:
       /************************** */
      int i;
      int j;

      tft.fillScreen(WHITE);
      for (i = 0; i < 133; i++)
      {
        for (j = 0; j < 99; j++)
        {
          tft.drawPixel((j + 195),(i + 35),boto2[j + (i * 99)]);
        }
      }

      tft.setFont(&FreeSansBold24pt7b);
      tft.setCursor(20, 35);
      tft.setTextColor(MAGENTA);
      delay(1);
      tft.setTextSize(1);
      tft.println("BOTO ROSA");

      tft.setFont(&FreeSansBold12pt7b);
      tft.setCursor(20, 80);
      tft.setTextColor(BLACK);
      delay(1);
      tft.setTextSize(1);
      tft.println("Geek device");

      tft.setCursor(20, 110);
      tft.println("@pakequis");

      tft.setCursor(20, 140);
      tft.println("16/06/2024 Test");

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
    tft.fillScreen(BLACK);
    tft.setFont(&FreeSansBold12pt7b);
    tft.setCursor(20, 35);
    tft.setTextColor(GREEN);
    delay(1);
    tft.setTextSize(1);
    tft.println("Bad USB");
    tft.setCursor(20, 60);
    tft.println("Radio");
    tft.setCursor(20, 85);
    tft.println("Bluetooth");
    tft.setCursor(20, 110);
    tft.println("Chaos Papagali");
    tft.setCursor(20, 135);
    tft.println("RFID 125 kHz");
    tft.setCursor(20, 160);
    tft.println("NFC");

    tft.setCursor(0,35);
    tft.print(">");

    while(test_sw != 6)
    {
      tft.setTextColor(GREEN);
      if(digitalRead(SW1) == 0) test_sw = 1;
      if(digitalRead(SW2) == 0) test_sw = 2;
      if(digitalRead(SW3) == 0) test_sw = 3;
      if(digitalRead(SW4) == 0) test_sw = 4;
      if(digitalRead(SW5) == 0) test_sw = 5;
      if(digitalRead(SW6) == 0) test_sw = 6;

      if(test_sw == 6)
      {
        menu_n = 0;
      }

      if(test_sw == 1)
      {
        if (menu_i > 0)
        {          
          tft.setCursor(0,(35 + menu_i * 25));
          tft.print(">");          
          tft.setCursor(0,(60 + menu_i * 25));
          tft.setTextColor(BLACK);
          tft.print(">");
          menu_i--;
          
          delay(500);
        }
        test_sw = 0;
      }

      if (test_sw == 5)
      {
        if(menu_i < 5)
        {          
          tft.setCursor(0,(60 + menu_i * 25));
          tft.print(">");
          
          tft.setCursor(0,(35 + menu_i * 25));
          tft.setTextColor(BLACK);
          tft.print(">");
          menu_i++;
          
          delay(500);
        }
        test_sw = 0;
      }
    }
    test_sw = 0;
    menu_i = 0;
    break;

    default:
      
    break;
  }
}