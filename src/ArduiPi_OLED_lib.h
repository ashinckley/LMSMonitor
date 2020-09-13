/******************************************************************
 This is the common ArduiPi include file for ArduiPi board
 
02/18/2013  Charles-Henri Hallard (http://hallard.me)
            Modified for compiling and use on Raspberry ArduiPi Board
            LCD size and connection are now passed as arguments on 
            the command line (no more #define on compilation needed)
            ArduiPi project documentation http://hallard.me/arduipi

07/26/2013  Charles-Henri Hallard (http://hallard.me)
            Done generic library for different OLED type

09/08/2020  Stuart Hunter (https://github.com/shunte88)
            NHD1322 support

 Written by Charles-Henri Hallard for Fun .
 All text above must be included in any redistribution.
            
 ******************************************************************/

#ifndef _ArduiPi_OLED_lib_H
#define _ArduiPi_OLED_lib_H

#include <stdio.h>
#include <stdarg.h>  
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <stdbool.h>
#include "bcm2835.h"

// Configuration Pin for ArduiPi board
#define OLED_SPI_RESET RPI_V2_GPIO_P1_22 /* GPIO 25 pin 22  */
#define OLED_SPI_DC    RPI_V2_GPIO_P1_18 /* GPIO 24 pin 18  */
#define OLED_SPI_CS0   BCM2835_SPI_CS0   /* Chip Select CE0 */
#define OLED_SPI_CS1   BCM2835_SPI_CS1   /* Chip Select CE1 */
#define OLED_SPI_CS    BCM2835_SPI_CS1   /* Default Chip Select */
#define OLED_I2C_RESET RPI_V2_GPIO_P1_22 /* GPIO 25 pin 12  */

// OLED type I2C Address
#define ADAFRUIT_I2C_ADDRESS   0x3C /* 011110+SA0+RW - 0x3C or 0x3D */
// Address for 128x32 is 0x3C
// Address for 128x32 is 0x3D (default) or 0x3C (if SA0 is grounded)

#define SEEED_I2C_ADDRESS   0x3C /* 011110+SA0+RW - 0x3C or 0x3D */

#define SH1106_I2C_ADDRESS   0x3C 

// Oled supported display
#define OLED_ADAFRUIT_SPI_128x32 0
#define OLED_ADAFRUIT_SPI_128x64 1
#define OLED_ADAFRUIT_I2C_128x32 2
#define OLED_ADAFRUIT_I2C_128x64 3
#define OLED_SEEED_I2C_128x64 4
#define OLED_SEEED_I2C_96x96 5
#define OLED_SH1106_I2C_128x64 6
#define OLED_SH1106_SPI_128x64 7
#define OLED_NHD1322_GS_SPI_256x64 8
#define OLED_NHD1322_MONO_SPI_256x64 9

#define OLED_LAST_OLED 10 /* always last type, used in code to end array */

static const char * oled_type_str[] = {
    "Adafruit SPI 128x32",
    "Adafruit SPI 128x64",
    "Adafruit I2C 128x32",
    "Adafruit I2C 128x64",
    "Seeed I2C 128x64",
    "Seeed I2C 96x96",
    "SH1106 I2C 128x64",
    "SH1106 SPI 128x64"
    "NHD1322 Grayscale SPI 256x64"
    "NHD1322 Monochrome SPI 256x64"
};

// Arduino Compatible type
typedef bool boolean;
typedef uint8_t byte;

// Arduino Compatible Macro
#define _BV(bit) (1 << (bit))

// GCC Missing
//#define max(a,b) (a>b?a:b)
//#define min(a,b) (a<b?a:b)

#endif
