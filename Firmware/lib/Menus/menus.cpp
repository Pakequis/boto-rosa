/*
        LCD menus control

 */
#include <menus.h>

SPIClass *spi = new SPIClass(HSPI);
Adafruit_ST7789 tft = Adafruit_ST7789(spi, TFT_CS, TFT_DC, TFT_RST);

/* Menu messages */
/*const char *messages[] = {
    "Bad USB        ",
    "Radio          ",
    "Bluetooth      ",
    "Chaos Papagali ",
    "RFID 125 kHz   ",
    "NFC            "
};*/

/* LCD config */
int LCD_init(void)
{  
    pinMode(LCD_BACKLIGHT, OUTPUT);
    digitalWrite(LCD_BACKLIGHT, HIGH);  /* Turn on LCD backlight */
    spi->begin(LCD_SCL, -1, LCD_SDA, TFT_CS);

    tft.init(LCD_H, LCD_W);           // Init ST7789 170x320

    /* LCD start */
    tft.setRotation(3);
    tft.fillScreen(WHITE);

    tft.setFont(&FreeSansBold12pt7b);

    return 0;
}

/* Show splash screen with text and image */
int show_splash_screen(void)
{
    tft.fillScreen(WHITE);

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
    tft.println("05/10/2024 Test");

    /************************** */
    /* Show the boto image      */
    int i;
    int j;
    uint16_t color;

    for (i = 0; i < 127; i++)   /* 127 h */
    {
        for (j = 0; j < 91; j++)    /* 91 w */
        {
            color = pixel_color[boto[j + (i * 91)]];
            if(color != WHITE)    /* Ignore white pixels */
            {
                tft.drawPixel((j + 220),(i + 40),color); /* 220 = horizontal position 40 = vertical position */
            }
        }
    }

    return 0;
}