/*
 * LAB5.c
 *
 * Created: 15/11/2567 10:32:45
 * Author : User
 */ 

#define F_CPU 20000000 // AVR clock frequency in Hz, used by util/delay.h
#include <avr/io.h>
#include <util/delay.h>
int main() {
	DDRB = 0xff;
	while(1){
		for(int i=0 ;i<8;i++)
		{
			PORTB |= (1<<i);
			_delay_ms(500);
			PORTB &= ~(1<<i);
		}
	}
}