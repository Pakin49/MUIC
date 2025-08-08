/*
 * LAB8.c
 *
 * Created: 30/11/2567 15:56:17
 * Author : User
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include "USART.h"
#include <util/delay.h> 

int main()
{	
	_delay_ms(100); //start up delay
	USART_Init(MYUBRR);
	DDRD &= ~(1<<DDD2); // SET PORTD2 to be input
	uint8_t switch_pin = PIND & (1<<PIND2);
	uint8_t previous = switch_pin;
	while(1)
	{
		switch_pin = PIND & (1<<PIND2);
		if (switch_pin != previous)
		{
			if(switch_pin)
				USART_Print("Bye\r\n");
			else
				USART_Print("Hello\r\n");
			previous = switch_pin;
		}
		_delay_ms(10);		
	}	
}