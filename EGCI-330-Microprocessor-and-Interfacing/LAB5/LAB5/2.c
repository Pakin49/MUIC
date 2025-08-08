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
	DDRB |= (1<<DDD5); // set LED pin PD1 to output
	
	while (1) {
	PORTB |= (1<<PORTB5); // drive PD1 high
	_delay_ms(1000); // delay 100 ms
	PORTB &= ~(1<<PORTB5); // drive PD1 low
	_delay_ms(1000); // delay 900 ms
	}
}