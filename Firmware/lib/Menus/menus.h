#ifndef __menus_H__
#define __menus_H__

#include <Arduino.h>
#include <SPI.h>

#include "hardware.h"
#include "boto-img.h"

/* GFX Adafruit libs */
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <Fonts/FreeSansBold12pt7b.h>
#include <Fonts/FreeSansBold24pt7b.h>

/* LCD Pins */
#define TFT_CS    LCD_CS
#define TFT_RST   LCD_RES
#define TFT_DC    LCD_DC

/* LCD size */
#define LCD_H   170
#define LCD_W   320

/* Colors */
#define BLACK   0x0000
#define WHITE   0xFFFF
#define RED     0xF800
#define GREEN   0x07E0
#define BLUE    0x001F
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define ORANGE  0xFC00

/* Protos */
int LCD_init(void);
int show_splash_screen(void);

#endif /* __menus_H__ */