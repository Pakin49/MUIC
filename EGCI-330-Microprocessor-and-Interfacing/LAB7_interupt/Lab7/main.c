/*
 * Lab7.c
 *
 * Created: 3/12/2567 18:47:47
 * Author : User
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "stack.h"
uint8_t status = 0; // 0 OFF 1 ON
uint8_t POP = 0;
int main()
{
	DDRD = ~(1<<DDD3);
	DDRD |= (1<<DDD6);
	EIMSK = (1<<INT1);
	EICRA = (1<<ISC11)|(1<<ISC10); // detect rising edge initially LED turn OFF;
	
	//Timer/Counter Compare match A for 3 seconds delays
	TCCR1A = 0; // nothing
	TCCR1B = (1<<WGM12)|(1<<CS12)|(1<<CS10); //CTC MODE and PRESCALE 1024
	OCR1A = 46874; // set output compare register 1A = 3SEC 46875-1
	Stack time;
	initialize(&time);
	sei ();
	while(1){ }
	return 0;
}

ISR(INT1_vect)
{	
	if(status == 0)
	{
		// SET INTERUPT TO DETECT FALLING EDGE
		EICRA |= (1<<ISC11);
		EICRA &= ~(1<<ISC10);
		status = 1;
	}
	else
	{
		EICRA |= (1<<ISC11)|(1<<ISC10); // set interrupt to detect rising edge
		status = 0;
	}
	TCNT1 = 0;
	TIMSK1 |=  (1<<OCIE1A); // turn on the timer;
}

ISR(TIMER1_COMPA_vect)
{
	if(status == 1)
		PORTD = (1<<PORTD6); // TURN ON LED
	else
		PORTD &= ~(1<<PORTD6);//turn off LED
	TIMSK1 &= ~(1<<OCIE1A); // write 1 to clear timer interrupt flag for output compare register 1A
}