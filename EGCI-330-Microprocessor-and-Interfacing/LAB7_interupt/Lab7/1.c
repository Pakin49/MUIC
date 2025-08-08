/*
 * Lab7.c
 *
 * Created: 3/12/2567 18:47:47
 * Author : User
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
//every second toggle LED at port PD5 -> 1sec = 16 M CLK =>  160000000/1024 
//= 15625-> SET 15624 
int main(void)
{
	TCCR1A = 0; // nothing
	TCCR1B = (1<<WGM12)|(1<<CS12)|(1<<CS10); //CTC MODE and PRESCALE 1024
	OCR1A = 15624; // set output compare register 1A = 1SEC
	DDRD = (1<<DDD5); // directional portD
	TIMSK1 =(1<<OCIE1A); // enable timer interupt flag for output compare register 1A
	sei (); // SET global interupts flag in SREG;
	while(1){ } // do nothing
	return 0;
}

ISR(TIMER1_COMPA_vect)
{
	PORTD ^= PORTD|(1<<PORTD5);//toggle port5
	TIFR1 |= (1<<OCF1A);
}