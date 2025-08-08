/*
 * final_6580043.c
 *
 * Created: 13/12/2567 8:02:39
 * Author : User
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include "keypad2x2.h"
#include <stdlib.h>
#include <util/delay.h>
#include <time.h>

//***** Function Prototypes
void setup(void);
void counter_1sec(void);
void sevenseg_put(int key);

#define LED_PORT PORTB
#define LED_DDR DDRB
#define LED0 0
#define LED1 1
#define LED2 2
#define LED3 3
#define LED4 4
#define green 5
#define red 6

#define SEVENSEG_PORT PORTC
#define SEVENSEG_DDR DDRC

// PORTB : LED
// PORTC : 7Segments
// PORTD : KEYPAD

uint8_t score = 0;
int main(void)
{	
	setup();
	int random_value[5];
	while(1)
	{	
		sevenseg_put(score);
		_delay_ms(1000);//Time to prepare yourself
		LED_PORT = 0;
		_delay_us(10);
		for(int i = 0;i<5;i++)
		{ 	
			// random and assign value to the random_value[]
			random_value[i] = (rand()%5)+1; 
			if(random_value[i] == 1) LED_PORT |= (1<<LED0);
			else if (random_value[i] == 2) LED_PORT |= (1<<LED1);
			else if (random_value[i] == 3) LED_PORT |= (1<<LED2);
			else if (random_value[i] == 4) LED_PORT |= (1<<LED3);
			else if (random_value[i] == 5) LED_PORT |= (1<<LED4);
			counter_1sec();
			LED_PORT &= ~(0x1F); // close the LED;
		}
		uint8_t guess = 0;
		// check the value compare to the guess from keypad
		for(int i=0;i<5;i++)
		{
			guess = keypad_check();
			if (guess == random_value[i])
			{
				LED_PORT |= (1<<green);
				_delay_ms(250);
				LED_PORT &= ~(1<<green);
			}
			else // wrong
			{
				LED_PORT |= (1<<red);
				_delay_ms(2000);
				LED_PORT &= ~(1<<red);
				break;
			}
			if(i==4)
			{
				LED_PORT |= (1<<green);
				score++;
			}
		}
		if(score==5)
		{	
			sevenseg_put(score);
			LED_PORT = 0;
			LED_PORT |= (1<<green);
			return 0;
		}
	}
	LED_PORT = 0;
	LED_PORT |= (1<<red);
	return  -1;
}

void setup()
{
	// set up of LCD + KEYPAD is done in the .h called by init()
	keypad_init();
	
	//***** TIMER/COUNTER1 (for 1sec delay) *****
	TCCR1A = 0;
	TCCR1B = (1<<CS12 | 1<<CS10 | 1<<WGM12); // Prescaler 1024, CTC MODE
	OCR1A = 15624; // 15625-1
	
	LED_DDR = 0xFF;
	SEVENSEG_DDR = 0xFF;
	LED_PORT = 0;
}

void sevenseg_put(int key)
{
	// Define 7-segment patterns for 0-9, A-F (common cathode)
	const uint8_t seg_patterns[] =
	{
		0b00111111, // 0
		0b00000110, // 1
		0b01011011, // 2
		0b01001111, // 3
		0b01100110, // 4
		0b01101101, // 5
		0b01111101, // 6
		0b00000111, // 7
		0b01111111, // 8
		0b01101111, // 9
		0b01110111, // A
		0b01111100, // B
		0b00111001, // C
		0b01011110, // D
		0b01111001, // E
		0b01110001  // F
	};
	//convert ASCII to int value;
	uint8_t pattern = 0x00;
	pattern = seg_patterns[key];
	// Output the pattern to PORTB
	SEVENSEG_PORT = pattern;
}

void counter_1sec()
{
	TCNT1 = 0x0000;
	TIFR1 |= (1<<OCF1A); // Clear Flag
	while((TIFR1 & (1<<OCF1A))==0){}
}