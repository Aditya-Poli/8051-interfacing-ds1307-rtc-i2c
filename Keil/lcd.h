// the #ifndef prevents the file from being included more than once
#ifndef __LCD_H__   
#define __LCD_H__

#define Data P1																		// lcd data port

// controls pins of LCD
sbit rs = P2^0;																		// write or command pin of LCD
//sbit rw = P3^1;																		// read write pin of LCD
sbit en = P2^1;																		// enable pin of LCD

// LCD important params
#define LCDMaxRows 2
#define LCDMaxColumns 16
#define RowOne 0x80
#define RowTwo 0xC0


// LCD commands necessary for this project
#define	Bit8Mode	0x38
#define Bit8Mode_1 0xE0
#define	Bit4Mode	0x02														// not required if used in 8 bit mode
#define Bit4Mode_1 0x28														//  					""""
#define DispOnCursorOff 0x0C
#define AutoIncCursor 0x06
#define Clear 0x01



// defining macros 
void lcd_Init();																		// LCD initialization function
void lcd_Command(char cmd);													// to write command to the LCd
void lcd_Writedata(char dta);												// to write data
void lcd_WriteString(char *string_ptr);							// write the string to the LCD
void lcd_CursorPosn(char row, char col);						// jump to the specified position on the LCD
void lcd_DisplayTime(char hour,char min,char sec);	// display time on LCD
void lcd_DisplayDate(char day,char month,char year);// display date on LCD

 
#endif 