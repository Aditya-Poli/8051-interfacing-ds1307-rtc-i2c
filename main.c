#include <reg51.h> 
#include "lcd.h"  	 
#include "ds1307.h" 
#include "i2c.h"
#include "delay.h"
/* main program */
void main() 
{
   unsigned char sec,min,hour,day,month,year;
    lcd_Init();
    ds1307_Init();
    ds1307_SetTime(0x23,0x59,0x30);  
    ds1307_SetDate(0x31,0x12,0x20); 
    lcd_DisplayString(" MICRODIGISOFT ");
    lcd_Line_posnY();
    lcd_DisplayString("REAL-TIME-CLOCK");
	  delay_ms(1000);
	 lcd_Clear();
    lcd_DisplayString(" Time:");
	  lcd_Line_posnY();
    lcd_DisplayString(" Date:");
	  delay_ms(1000);
    while(1)
    {
	  ds1307_GetTime(&hour,&min,&sec);        
	  lcd_curser_posn(0,6); 		 
    lcd_DisplayRtcTime(hour,min,sec);
    ds1307_GetDate(&day,&month,&year);        
    lcd_curser_posn(1,6); 		 
    lcd_DisplayRtcDate(day,month,year);
     delay_ms(1000);
     }
}
