#include <stdint.h>
#include <LCD.h>
#include <SPI.h>
#include <XPT2046.h>
#include <Touch.h>

void setup()
{ 
   __SD_CS_DISABLE();
   
    SPI.setDataMode(SPI_MODE3);
    SPI.setBitOrder(MSBFIRST);
    SPI.setClockDivider(SPI_CLOCK_DIV4);
    SPI.begin();

    Tft.lcd_init();                                      // init TFT library
    Tp.tp_init();
    Tp.tp_adjust();
    Tp.tp_dialog();
}


void loop()
{
    Tp.tp_draw_board();
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
