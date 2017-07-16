#include <stdint.h>
#include <LCD.h>
#include <SPI.h>
#define __AVR_ATmega32U4__

void setup()
{  
    SPI.setDataMode(SPI_MODE3);
    SPI.setBitOrder(MSBFIRST);
    SPI.setClockDivider(SPI_CLOCK_DIV4);
    SPI.begin();
    
    Tft.lcd_init();                                      // init TFT library
    Tft.lcd_display_string(60, 120, (const uint8_t *)"Hello, world !", FONT_1608, RED);
    Tft.lcd_display_string(30, 152, (const uint8_t *)"2.8' TFT Touch Shield", FONT_1608, RED);
}

void loop()
{
  
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

