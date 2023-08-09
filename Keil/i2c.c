#include <reg51.h>
#include "i2c.h"
#include "delay.h"


// i2c clock function
void i2c_Clock()
{
    delay_us(50);
    SCL = 1;        
 
    delay_us(50);        
    SCL = 0;        
}


void i2c_Start()
{
    SCL = 0;        // pull SCL to low
 
    SDA = 1;        // pull SDA to High
    delay_us(50);
 
    SCL = 1;        //pull SCL to high
    delay_us(50);
 
    SDA = 0;        //Now pull SDA to LOW, to generate the Start Condition
    delay_us(50);
 
    SCL = 0;        //Finally Clear the SCL to complete the cycle
}

 
void i2c_Stop(void)
{
    SCL = 0;            // pull SCL low
    delay_us(50);
 
    SDA = 0;            // pull SDA  low
    delay_us(50);
 
    SCL = 1;            // pull SCL High
    delay_us(50);
 
    SDA = 1;            // Now pull SDA High, to generate the Stop Condition
}

void i2c_Write(unsigned char dta)
{
    unsigned char i;
 
    for(i=0;i<8;i++)         
     {
        SDA = dta & 0x80;    // write bit by bit
        i2c_Clock();         // clock
        dta = dta<<1;				
      }
        SDA = 1;   					              
}

unsigned char i2c_Read()
{
    unsigned char i, dat=0x00;
 
       SDA=1;               
    for(i=0;i<8;i++)       
     {
       delay_us(50);
        SCL = 1;           
        delay_us(50);
 
        dat = dat<<1;       
        dat = dat | SDA;    
 
        SCL = 0;            
       }
   return dat;             
}

void i2c_Ack()
{
		// acknowledgement
    SDA = 0;        
    i2c_Clock();    
    SDA = 1;        
}

void i2c_NoAck()
{
		// no acknowledgement
    SDA = 1;        
   i2c_Clock();     
    SCL = 1;     
}

