case HX8347D:
	LCD_Write_Register(0x02,x1>>8);
	LCD_Write_Register(0x03,x1);
	LCD_Write_Register(0x04,x2>>8);
	LCD_Write_Register(0x05,x2);
	LCD_Write_Register(0x06,y1>>8);
	LCD_Write_Register(0x07,y1);
	LCD_Write_Register(0x08,y2>>8);
	LCD_Write_Register(0x09,y2);
	LCD_Write_COM(0x22);      
	break;
