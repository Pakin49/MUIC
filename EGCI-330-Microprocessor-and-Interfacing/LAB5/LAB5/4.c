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
				CS = PINC;
				_delay_ms(50);
				if(CS==1 && PS==0){
					toggle = !toggle;
				}		
			}while(toggle == 0 );
			PORTB &= ~(1<<i);
		}
	}
}