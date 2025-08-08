/*
 * LAB6.c
 *
 * Created: 30/11/2567 15:56:17
 * Author : User
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
void delay ( )
{
	TCCR0A = (1<<WGM01);
	TCCR0B = (1<<CS01)|(1<<CS02);
	OCR0A = 249;
	while ((TIFR0&(1<<OCF0A)) == 0)
	{ }
	TIFR0 = (1<<OCF0A);
}
int main ( )
{
	DDRC |= (1<<DDD2);
	while(1)
	{
		PORTC |= (1<<PORTC2);
		delay ( );
		PORTC &= ~(1<<PORTC2);
		delay ( );
	}
	return 0;
}