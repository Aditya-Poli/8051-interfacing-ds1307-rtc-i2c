#include<reg51.h> 
#include "ds1307.h"
#include "i2c.h"
#include "delay.h"

// important addresses
#define DS1307_ID 0xD0     // ds1307 ID 68 with write bit
#define DS1307_ID_1 0xD1	 // ds1307 ID 68 with read bit
#define SEC_ADDRESS   0x00 // address to access ds1307 SEC register
#define DATE_ADDRESS  0x04 // address to access ds1307 DATE register
#define control       0x07 // address to access ds1307 CONTROL register


//ds1307 initilization
void ds1307_Init()
{
    i2c_Start();            	// Start of i2c communication
 
   ds1307_Write(DS1307_ID);   // write address of DS1307 with write bit
   ds1307_Write(control);     // control register of DS1307 RTC
 
    ds1307_Write(0x00);       
 
    i2c_Stop();              // stop i2c communication
 
 }
 void ds1307_Write(unsigned char dat)
{
    i2c_Write(dat);   			// write data on SDA line
    i2c_Clock();						
 }
 
unsigned char ds1307_Read()
{
    unsigned char dat;			// read data bit by bit
    dat = i2c_Read();   
    return(dat);
 }
void ds1307_SetTime(unsigned char hh, unsigned char mm, unsigned char ss)
{
    i2c_Start();            // Start the i2c communication
 
    ds1307_Write(DS1307_ID);    
    ds1307_Write(SEC_ADDRESS);	// write address of seconds register
    ds1307_Write(ss);           // set the desired time by sending ss
    ds1307_Write(mm);           // mm and hh
    ds1307_Write(hh);           
    i2c_Stop();             // Stop the i2c communication after Setting the Time
}

void ds1307_SetDate(unsigned char dd, unsigned char mm, unsigned char yy)
{
    i2c_Start();            // Start the i2c communication
 
    ds1307_Write(DS1307_ID);    
    ds1307_Write(DATE_ADDRESS);  // address of date register   
	
    ds1307_Write(dd);            // set the desired date 
    ds1307_Write(mm);           
    ds1307_Write(yy);           
 
    i2c_Stop();             // Stop the i2c communication after Setting the Date
}

void ds1307_GetTime(unsigned char *h_ptr,unsigned char *m_ptr,unsigned char *s_ptr)
{
     i2c_Start();           // Start the i2c communication
 
    ds1307_Write(DS1307_ID);    
    ds1307_Write(SEC_ADDRESS);  // write the address of seconds register        
 
     i2c_Stop();            
 
    i2c_Start();               
    ds1307_Write(0xD1);         // start the i2c with read bit
                               
 
  *s_ptr = ds1307_Read();  i2c_Ack();     // read ss:mm:hh into the variable
  *m_ptr = ds1307_Read();  i2c_Ack();     // one by one
  *h_ptr = ds1307_Read();  i2c_NoAck();   
 
  i2c_Stop();               // stop the i2c communication after reading the Time
 }
 
void ds1307_GetDate(unsigned char *d_ptr,unsigned char *m_ptr,unsigned char *y_ptr)
{
    i2c_Start();            // start the i2c communication
 
    ds1307_Write(DS1307_ID);    
    ds1307_Write(DATE_ADDRESS);    // write the address of date address 
 
    i2c_Stop();             
 
 
   i2c_Start();             
   ds1307_Write(0xD1);          
                            
 
  *d_ptr = ds1307_Read(); i2c_Ack();     // load date dd:mm:yy into the
  *m_ptr = ds1307_Read(); i2c_Ack();     // variables onr by one
  *y_ptr = ds1307_Read(); i2c_NoAck();   
 
  i2c_Stop();         // stop the i2c communication after reading the Time
 }

