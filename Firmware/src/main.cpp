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

void setup(void) {
  Serial.begin(9600);
  Serial.print(F("Boto rosa test..."));

  pinMode(LCD_BACKLIGHT, OUTPUT);
  digitalWrite(LCD_BACKLIGHT, HIGH);  /* Turn on LCD backlight */

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
  tft.println("09/06/2024 Test");

  delay(5000);

  while(1);

}