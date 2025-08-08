/*
 * final_6580043.c
 *
 * Created: 13/12/2567 8:02:39
 * Author : User
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include "keypad.h"
#include "LCD.h"

//***** Function Prototypes
void setup(void);
void authenticate(void);
void lockdown(void);
void counter_1sec(void);

#define LED_PORT PORTB
#define LED_DDR DDRB
#define green 2
#define red 3

// PORTB : LCD(4PIN MODE)+ LED
// PORTD : KEYPAD
 
int main(void)
{
	setup();
	while(1){
		authenticate();
	}
}

void setup()
{
	// set up of LCD + KEYPAD is done in the .h called by init()
	keypad_init();
	lcd_init();
	LED_DDR |= ((1<<green) | (1<<red));
	
	//***** TIMER/COUNTER1 (for 1sec delay) *****
	TCCR1A = 0;
	TCCR1B = (1<<CS12 | 1<<CS10 | 1<<WGM12); // Prescaler 1024, CTC MODE
	OCR1A = 15624; // 15625-1
	
	//***** TIMER/COUNTER0 for(blinking LED) *******
	// blinking LED f = 400hz using timer interrupt
	TCCR0A =  0;
	TCCR0B =  (1<<CS02) | (1<<CS00); //Prescaler 1024, normal mode
	TIMSK0 |= (1<< TOIE0);	//set mask bit 0;
}

void authenticate()
{	
	uint8_t attempt = 0;
	char password[5] = "2544";
	while(1)
	{
		char buffer[5];
		lcd_clear();
		lcd_print("Enter Passcode");
		lcd_gotoxy(1,2);
		for(int i=0;i<4;i++)
		{
			buffer[i] = keypad_check();
			lcdData('*');
		}
		buffer[4] = '\0';
		if(strcmp(password,buffer) == 0)
		{
			lcd_hideCursor();
			lcd_clear();
			lcd_print("Access Granted");
			LED_PORT |= (1<<green);
			for(int i=0;i<10;i++){
				counter_1sec();
			}
			LED_PORT &= ~(1<<green);
			lcd_showCursor();
			break;
		}
		else
		{
			lcd_hideCursor();
			lcd_clear();
			lcd_print("Access Denied");
			LED_PORT |= (1<<red);
			lcd_showCursor();
			attempt++;
			if (attempt==3)
			{
				attempt = 0;
				lockdown();	
			}
			_delay_ms(1000);
			LED_PORT &= ~(1<<red);
		}
	}
}

void lockdown()
{
	lcd_clear();
	lcd_print("Lockdown Mode");
	lcd_hideCursor();
	TCNT0 = 0x00;
	sei();
	for(int i=0;i<30;i++){
		counter_1sec();
	}
	cli();
	LED_PORT &= ~(1<<red);
	lcd_showCursor();
}


uint8_t timer0_interupt_count = 0;
ISR(TIMER0_OVF_vect)
{
	timer0_interupt_count++;
	if(timer0_interupt_count == 12)
	{
		timer0_interupt_count = 0;
		LED_PORT ^= (1<<red);
	}
}

void counter_1sec()
{
	TCNT1 = 0x0000;
	TIFR1 |= (1<<OCF1A); // Clear Flag
	while((TIFR1 & (1<<OCF1A))==0){}
}