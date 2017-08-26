case HX8347D:

  #if  defined(__AVR_ATmega32U4__)
    // pin 9
      #define __LCD_BKL_OUT()   DDRB |= 0x20
      #define __LCD_BKL_OFF()   PORTB &=~ 0x20
      #define __LCD_BKL_ON()    PORTB |=  0x20

  #elif defined(__AVR_ATmega328__)
      //pin 9
      #define __LCD_BKL_OUT()   DDRB |= 0x02
      #define __LCD_BKL_OFF()   PORTB &=~ 0x02
      #define __LCD_BKL_ON()    PORTB |=  0x02

  #elif defined(ESP8266)

    #define LCD_BKL_PIN        6

    #define __LCD_BKL_OUT()   pinMode(LCD_BKL_PIN, OUTPUT)
    #define __LCD_BKL_OFF()   digitalWrite(LCD_BKL_PIN, LOW)
    #define __LCD_BKL_ON()    digitalWrite(LCD_BKL_PIN, HIGH)

  #else

    #define LCD_BKL_PIN        9

    #define __LCD_BKL_OUT()   pinMode(LCD_BKL_PIN, OUTPUT)
    #define __LCD_BKL_OFF()   digitalWrite(LCD_BKL_PIN, LOW)
    #define __LCD_BKL_ON()    digitalWrite(LCD_BKL_PIN, HIGH)

  #endif



    sbi(P_RS,B_RS);

    __LCD_BKL_OUT();
    __LCD_BKL_OFF();


    //Driving ability Setting
	LCD_Write_Register(0xEA,0x00); //PTBA[15:8]
	LCD_Write_Register(0xEB,0x20); //PTBA[7:0]
	LCD_Write_Register(0xEC,0x0C); //STBA[15:8]
	LCD_Write_Register(0xED,0xC4); //STBA[7:0]
	LCD_Write_Register(0xE8,0x38); //OPON[7:0]
	LCD_Write_Register(0xE9,0x10); //OPON1[7:0]
	LCD_Write_Register(0xF1,0x01); //OTPS1B
	LCD_Write_Register(0xF2,0x10); //GEN
	//Gamma 2.2 Setting
	LCD_Write_Register(0x40,0x01); //
	LCD_Write_Register(0x41,0x00); //
	LCD_Write_Register(0x42,0x00); //
	LCD_Write_Register(0x43,0x10); //
	LCD_Write_Register(0x44,0x0E); //
	LCD_Write_Register(0x45,0x24); //
	LCD_Write_Register(0x46,0x04); //
	LCD_Write_Register(0x47,0x50); //
	LCD_Write_Register(0x48,0x02); //
	LCD_Write_Register(0x49,0x13); //
	LCD_Write_Register(0x4A,0x19); //
	LCD_Write_Register(0x4B,0x19); //
	LCD_Write_Register(0x4C,0x16); //
	LCD_Write_Register(0x50,0x1B); //
	LCD_Write_Register(0x51,0x31); //
	LCD_Write_Register(0x52,0x2F); //
	LCD_Write_Register(0x53,0x3F); //
	LCD_Write_Register(0x54,0x3F); //
	LCD_Write_Register(0x55,0x3E); //
	LCD_Write_Register(0x56,0x2F); //
	LCD_Write_Register(0x57,0x7B); //
	LCD_Write_Register(0x58,0x09); //
	LCD_Write_Register(0x59,0x06); //
	LCD_Write_Register(0x5A,0x06); //
	LCD_Write_Register(0x5B,0x0C); //
	LCD_Write_Register(0x5C,0x1D); //
	LCD_Write_Register(0x5D,0xCC); //
	//Power Voltage Setting
	LCD_Write_Register(0x1B,0x1B); //VRH=4.65V
	LCD_Write_Register(0x1A,0x01); //BT (VGH~15V,VGL~-10V,DDVDH~5V)
	LCD_Write_Register(0x24,0x2F); //VMH(VCOM High voltage ~3.2V)
	LCD_Write_Register(0x25,0x57); //VML(VCOM Low voltage -1.2V)
	//****VCOM offset**///
	LCD_Write_Register(0x23,0x88); //for Flicker adjust //can reload from OTP
	//Power on Setting
	LCD_Write_Register(0x18,0x34); //I/P_RADJ,N/P_RADJ, Normal mode 60Hz
	LCD_Write_Register(0x19,0x01); //OSC_EN='1', start Osc
	LCD_Write_Register(0x01,0x00); //DP_STB='0', out deep sleep
	LCD_Write_Register(0x1F,0x88);// GAS=1, VOMG=00, PON=0, DK=1, XDK=0, DVDH_TRI=0, STB=0
	delay(5);
	LCD_Write_Register(0x1F,0x80);// GAS=1, VOMG=00, PON=0, DK=0, XDK=0, DVDH_TRI=0, STB=0
	delay(5);
	LCD_Write_Register(0x1F,0x90);// GAS=1, VOMG=00, PON=1, DK=0, XDK=0, DVDH_TRI=0, STB=0
	delay(5);
	LCD_Write_Register(0x1F,0xD0);// GAS=1, VOMG=10, PON=1, DK=0, XDK=0, DDVDH_TRI=0, STB=0
	delay(5);
	//262k/65k color selection
	LCD_Write_Register(0x17,0x05); //default 0x06 262k color // 0x05 65k color
	//SET PANEL
	LCD_Write_Register(0x36,0x00); //SS_P, GS_P,REV_P,BGR_P
	//Display ON Setting
	LCD_Write_Register(0x28,0x38); //GON=1, DTE=1, D=1000
	delay(40);
	LCD_Write_Register(0x28,0x3F); //GON=1, DTE=1, D=1100

	LCD_Write_Register(0x16,0x18);
  LCD_Write_Register(0x02,0x00);
	LCD_Write_Register(0x03,0x00); //Column Start
	LCD_Write_Register(0x04,0x00);
	LCD_Write_Register(0x05,0xEF); //Column End
	LCD_Write_Register(0x06,0x00);
	LCD_Write_Register(0x07,0x00); //Row Start
	LCD_Write_Register(0x08,0x01);
	LCD_Write_Register(0x09,0x3F); //Row End

  __LCD_BKL_ON();
  clrScr();
  break;
