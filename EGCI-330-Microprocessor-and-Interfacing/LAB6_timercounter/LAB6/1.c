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
	TCNT0 = 131;
	TCCR0A = 0;
	TCCR0B = (1<<CS01)|(1<<CS00);
	while ((TIFR0&(1<<TOV0)) == 0)
	{ }
	TIFR0 = (1<<TOV0);
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