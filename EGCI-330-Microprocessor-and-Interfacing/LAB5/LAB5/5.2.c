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
	__asm__ volatile(
		"SBI %0, %1"
		:
		:"I" (_SFR_IO_ADDR(DDRB)),
		"I" (DDD1)
	);
	while(1){
	__asm__ volatile(
		"SBI %0, %1 "
		:
		:"I" (_SFR_IO_ADDR(PORTB)),
		"I"(PORTB1)
	);
	_delay_ms(100);
	__asm__ volatile(
		"CBI %0, %1 "
		:
		:"I" (_SFR_IO_ADDR(PORTB)),
		"I"(PORTB1)
	);
	_delay_ms(900);
	}
}

