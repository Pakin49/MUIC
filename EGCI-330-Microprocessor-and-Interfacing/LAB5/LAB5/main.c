/*
 * LAB5.c
 *
 * Created: 15/11/2567 10:32:45
 * Author : User
 */ 

#define F_CPU 20000000	 // AVR clock frequency in Hz, used by util/delay.h
#include <avr/io.h>
#include <util/delay.h>

uint8_t PS,CS; 
uint8_t toggle = 1;// toggle 0 =OFF toggle 1 == ON
/*
int main() {
	DDRB = 0xff;
	DDRC &= 0; 
	while(1){
		for(uint8_t i=0 ;i<8;i++)
		{	
			PORTB |= (1<<i);
			_delay_ms(500);
			do{
				PS = CS;
				CS = PINC0;
				_delay_ms(50);
				if(CS==1 && PS==0){
					toggle = !toggle;
				}		
			}while(toggle == 0 );
			PORTB &= ~(1<<i);
		}
	}
}*/

#include <avr/io.h>

int main() {
	uint8_t a;

	__asm__ volatile(
	"LDI %[reg], 0xFF \n\t"
	"OUT %[ddrb], %[reg] \n\t"
	"OUT %[ddrc], %[reg] \n\t"
	:[reg] "=&r"(a)
	:[ddrb] "I"(_SFR_IO_ADDR(DDRB)),
	[ddrc] "I" (_SFR_IO_ADDR(DDRC))
	);
	
	__asm__ volatile(
	"LOP: CLR r16"
	:
	:
	:
	);
	
	return 0;
}