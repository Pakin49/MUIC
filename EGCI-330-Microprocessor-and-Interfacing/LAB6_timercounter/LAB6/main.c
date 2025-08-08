/*
 * LAB6.c
 *
 * Created: 30/11/2567 15:56:17
 * Author : User
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL

void delay()
{
	TCCR0A = (1<<WGM01);
	TCCR0B = (1<<CS02)|(1<<CS00);
	OCR0A = 155;
	TCNT0 = 0;
	while((TIFR0&(1<<OCF0A))==0){}
	TIFR0 |= (1<<OCF1A);
}

int main()
{	
	uint8_t CS = 0;
	uint8_t PS = 1;
	uint8_t count = 0;
	DDRD &= ~(1<<DDB4);
	DDRB |= (1<<DDB2);
	while(1)
	{	
		PS = CS;
		CS = PIND& (1<<PIND4);
		if(CS && !PS)
			count++;
		delay();
		if(count == 10)
		{
			count = 0;
			PORTB ^= (1<<PORTB2);
		}
	}
}