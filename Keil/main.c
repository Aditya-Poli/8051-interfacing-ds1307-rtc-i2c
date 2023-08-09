#include <reg51.h>
#include "lcd.h"
#include "delay.h"
#include "i2c.h"
#include "ds1307.h"


void main(void)
{
	unsigned char hours, mins, secs, year, month, day;
	lcd_Init();
	ds1307_Init();
	ds1307_SetTime(0x16,0x02,0x10);
	ds1307_SetDate(0x12,0x12,0x22);
	delay_ms(10);
	lcd_WriteString("Welcome to NITAP");
	delay_ns(1);
	lcd_Command(RowTwo);
	delay_us(10);
	lcd_WriteString("I2C RTC DS1307");
	delay_ns(1);
	
	lcd_Command(Clear);
	delay_us(10);
	lcd_Command(RowOne);
	delay_ms(10);
	lcd_WriteString("Time: ");
	delay_us(10);
	lcd_Command(RowTwo);
	delay_us(10);
	lcd_WriteString("Date: ");
	delay_us(10);
	while(1)
   {
	  ds1307_GetTime(&hours,&mins,&secs);     // load time to the variables   
	  lcd_CursorPosn(0,6); 		 								// place cursor at the Time
    lcd_DisplayTime(hours,mins,secs);				// display time on the LCD
    ds1307_GetDate(&day,&month,&year);      // load date to the variables
    lcd_CursorPosn(1,6); 		 							  // place cursor at the Date
    lcd_DisplayDate(day,month,year);				// display date on the LCD
    delay_ms(800);
   }
	
}

