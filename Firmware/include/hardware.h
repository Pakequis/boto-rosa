/* Hardware definitions

    02/06/2024
 */
#ifndef __HARDWARE_DEF_H__
#define __HARDWARE_DEF_H__

/* LCD Pins */
#define LCD_BACKLIGHT   1
#define LCD_CS          2
#define LCD_DC          42
#define LCD_RES         41
#define LCD_SDA         40
#define LCD_SCL         39

/* Keyboard pins */
#define SW1 37
#define SW2 36
#define SW3 35
#define SW4 0
#define SW5 45
#define SW6 48

/* Buzzer Pin */
#define BUZZER  47

/* IR LED Pin */
#define IR_LED  21

/* IR Receiver Pin */
#define IR_RX   38

/* Vib. motor Pin */
#define VIBRA_MOTOR 6

/* PN532 Pins */
#define PN532_IRQ   14
#define PN532_RTSO  15

/* Radio Pins */
#define RADIO_GDO0  17
#define RADIO_GDO2  5

/* RFID 125 kHz Pins */
/* Hardware to be defined... */

/* SPI for ESP32-S3 */
//#define SPI0  /* for internal use only */
#define SPI1        SPI1_HOST   /* For internal use only... */
#define SPI2        SPI2_HOST
#define SPI3        SPI3_HOST

/* SPI 2 Pins */
#define SPI2_MOSI   11
#define SPI2_CLK    12
#define SPI_MISO    13

/* Chip selects Pins */
#define SD_CS       16
#define PN532_CS    7
#define RADIO_CS    4

#endif /* __HARDWARE_DEF_H__ */