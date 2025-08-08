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
	uint8_t reg;
	__asm__ volatile(
		"LDI %0, 0xFF \n\t"
		"OUT %1, %0 \n\t"
		:"=r"(reg)
		:"I"(_SFR_IO_ADDR(DDRB))
	);
	
	uint8_t pin;
	while(1)
	{		
		__asm__ volatile(
			"LDI r16, 0x01 \n\t"
			"CLR r17 \n\t"
			:::"r16","r17"
		);
		for (pin = 0; pin < 8; pin++)
		{
			__asm__ volatile(
				"OUT %0,r16 \n\t"
				"LSL r16 \n\t"
				:
				:"I"(_SFR_IO_ADDR(PORTB))
				:"r16"
			);
			_delay_ms(100);
			__asm__ volatile(
				"OUT %0,r17"
				:
				:"I"(_SFR_IO_ADDR(PORTB))
				:"r17"
			);
			_delay_ms(900);
		}
	}
}