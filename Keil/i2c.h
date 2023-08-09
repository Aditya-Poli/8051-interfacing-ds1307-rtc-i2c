// ifndef prevents file from being imported more than once
#ifndef __I2C_H__
#define __I2C_H__

// defining SCL and SDA pins
sbit SCL=P3^0;      //SCL Connected to P2.6
sbit SDA=P3^1;      //SDA Connected to P2.7

void i2c_Clock();
void i2c_Start();
void i2c_Stop();
void i2c_Write(unsigned char);
unsigned char i2c_Read();
void i2c_Ack();
void i2c_NoAck();


#endif