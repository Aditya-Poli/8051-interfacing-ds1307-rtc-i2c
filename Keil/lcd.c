#include <reg51.h>
#include "lcd.h"
#include "delay.h"


// initialising function
void lcd_Init()
{
	lcd_Command(Bit8Mode);						// initializing in 8 bit mode
	lcd_Command(Bit8Mode_1);
	lcd_Command(DispOnCursorOff);
	lcd_Command(AutoIncCursor);
	lcd_Command(Clear);
	lcd_Command(RowOne);							// place the cursor at the beginning
	//rw = 0;														// to make sure we are always writing to the LCD
}


void lcd_Command(char cmd)
{
	Data = cmd;
	rs = 0;														// operating in command mode
	en = 1;
	delay_us(1);
	en = 0;
	delay_us(1);
}


void lcd_WriteData(char dta)
{
	Data = dta;
	rs = 1;														// operating in writing mode
	en = 1;
	delay_us(1);
	en = 0;
	delay_us(1);
}


void lcd_WriteString(char *string_ptr)
{
	while(*string_ptr)
	{
		lcd_WriteData(*string_ptr++);		// writes String to LCD char by char
	}
}

void lcd_CursorPosn(char row, char col)
{
	char pos;
 
    if(row<LCDMaxRows)
      {
         pos= RowOne | (row << 6);  	// row value 0x80 or 0xC0                        
        if(col<LCDMaxColumns)
           pos= pos+col;          		//  position on LCD  
         lcd_Command(pos);        		// place cursor at posn on LCD
       }
}

void lcd_DisplayTime(char hour,char min,char sec)
{
	// hour, min, sec are in packed BCD form
	// weneed only two digits of each
	
	lcd_WriteData(((hour>>4)&0x0F) | 0x30);	// tens place
	lcd_WriteData((hour & 0x0F) | 0x30);		// units place		
	lcd_WriteData(':');											
	
	lcd_WriteData(((min>>4)&0x0F) | 0x30);	// tens place
	lcd_WriteData((min & 0x0F) | 0x30);			// units place		
	lcd_WriteData(':');											
	
	lcd_WriteData(((sec>>4)&0x0F) | 0x30);	// tens place
	lcd_WriteData((sec & 0x0F) | 0x30);			// units place										
}

void lcd_DisplayDate(char day, char month, char year)
{
	lcd_WriteData(((day>>4)&0x0F) | 0x30);		// tens place
	lcd_WriteData((day & 0x0F) | 0x30);				// units place		
	lcd_WriteData('/');											
	
	lcd_WriteData(((month>>4)&0x0F) | 0x30);	// tens place
	lcd_WriteData((month & 0x0F) | 0x30);			// units place		
	lcd_WriteData('/');											
	
	lcd_WriteData(((year>>4)&0x0F) | 0x30);		// tens place
	lcd_WriteData((year & 0x0F) | 0x30);			// units place
}
