/*
 * LAB6.c
 *
 * Created: 30/11/2567 15:56:17
 * Author : User
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL

void press ( )
{	
    TCCR1A = 0; 
    TCCR1B = (1<<CS12)|(1<<CS10)|(1<<WGM12);
	OCR1A = 46875-1; // SET output compare register
	TIFR1 |= (1<<OCF1A); // CLR
    TCNT1H = 0x00;
    TCNT1L = 0x00;
	while((TIFR1&(1<<OCF1A))==0)
	{}
}

int main ( )
{    
    DDRB &= ~(1<<DDB2);
    DDRB |= (1<<DDB3);
    while(1)
    {   
        if((PINB & (1<<PINB2)))//Check the moment button press
		{	
			press();
			PORTB ^= (1<<PORTB3);
		}
    }
    return 0;
}