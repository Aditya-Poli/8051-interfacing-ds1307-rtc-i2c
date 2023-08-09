#include <reg51.h>

#include "delay.h"


// function for generating us delay
void delay_us(unsigned int us)
{
	for(;us>0;us--);
}

// function for generating ms delay
void delay_ms(unsigned int ms)
{
	unsigned char i;
	TMOD=0X02;										// Timer0 in mode 2
	TH0=0x00;											// 255 us for one time
	while(ms!=0)
	{
		for(i=0;i<4;i++){						// 4 times 255us ~ 1 ms
		TR0=1;		
		while(!TF0);
		TF0=0;}
		ms--;												// ms times = ms milliseconds
	}
}


// function for generating n seconds delay
void delay_ns(unsigned int ns)
{
	while(ns!=0)
	{
		delay_ms(1000);							// 1 second delay
		ns--;												// n seconds
	}
}