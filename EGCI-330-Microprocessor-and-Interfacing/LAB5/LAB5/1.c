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
	DDRD |= (1<<DDD1); // set LED pin PD1 to output
	
	while (1) {
		PORTD |= (1<<PORTD1); // drive PD1 high
		_delay_ms(100); // delay 100 ms
		PORTD &= ~(1<<PORTD1); // drive PD1 low
		_delay_ms(900); // delay 900 ms
	}
}
