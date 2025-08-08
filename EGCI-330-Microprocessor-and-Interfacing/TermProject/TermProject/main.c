/*
 * TermProject.c
 *
 * Created: 11/12/2567 15:03:31
 * Author : User
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>

#define button_pin 0
#define switch_pin 1
#define LED_pin 2

#include "keypad.h"
#include "LCD.h"
/*
 * PORTD : keypad
 * PORTC : button + switch + LED
 * PORTB : LCD
 */

//*************** Function Prototypes ***************
void counter_1sec(void);
int ASCII_to_int(char c);
char hex_to_ASCII(int hex);
void setup(void);
void timer(void);
void authenticate(void);

int main(void)
{	
	setup();
	authenticate();
	timer();
	while(1)
	{	
		if(PINC & (1<<switch_pin))
			authenticate();
		timer();
	}
}

void setup()
{
	keypad_init();
	lcd_init();
	DDRC &= ~(1<<button_pin | 1<<switch_pin );
	DDRC |= (1<<LED_pin);
	
//*************** Timer/Counter ***************
	TCCR1A = 0;
	TCCR1B = (1<<CS12 | 1<<CS10 | 1<<WGM12); // Prescaler 1024, CTC MODE 
	OCR1A = 15624; // 15625-1

//*************** While ***************
	PCMSK1 |= (1<<0);
	PCIFR |= (1 << PCIF1);      // Clear any pending interrupt flag AFTER configuration
	sei();
}

void authenticate()
{
//*************** authentication ***************
	char password[5] = "2544";
	while(1)
	{	
		char buffer[5];
		lcd_clear();
		lcd_print("Enter 4 digits");
		lcd_gotoxy(1,2);
		lcd_print("Password:");
		for(int i=0;i<5;i++)
		{
			buffer[i] = keypad_check();
			lcdData('*');
			if(buffer[i] == '\0')
			{
				if(i==4)
					break;
				else // password is not 4 digits and user enter
				{	
					lcd_hideCursor();
					lcd_clear();
					lcd_print("4 digits");
					lcd_gotoxy(1,2);
					lcd_print("password");
					_delay_ms(2000);
					lcd_clear();
					lcd_print("Enter 4 digits");
					lcd_gotoxy(1,2);
					lcd_print("Password:");
					lcd_showCursor();
					i = -1;
					continue;
				}
			}
			if (i==4)// user enter more than 4 number
			{
				lcd_clear();
				lcd_print("4 digits");
				lcd_gotoxy(1,2);
				lcd_print("password");
				lcd_hideCursor();
				i = 0;
				_delay_ms(2000);
				lcd_clear();
				lcd_print("Enter 4 digits");
				lcd_gotoxy(1,2);
				lcd_print("Password:");
				lcd_showCursor();
				i = -1;
				continue;
			}
		}
		if(strcmp(password,buffer) == 0)
		{	
			lcd_hideCursor();
			lcd_clear();
			lcd_print("Access Granted");
			_delay_ms(2000);
			lcd_showCursor();
			break;
		}
		else
		{	
			lcd_hideCursor();
			lcd_clear();
			lcd_print("Access denied!");
			_delay_ms(2000);
			lcd_showCursor();
		}
	}	
}

uint8_t reset_button = 0;
void timer()
{
//***************  set timer ***************
	lcd_clear();
	lcd_print("Set timer(HEX)");
	lcd_gotoxy(1,2);
	uint32_t countdown = 0;
	uint8_t n_digit = 0;
	for(int i = 0; i<9; i++)
	{	
		char key;
		key = keypad_check();
		if((key == '\0'))
		{
			n_digit = i-1;
			break;
		}
		if(i==8) // if insert timer more than 8 digits
		{
			lcd_clear();
			lcd_hideCursor();
			lcd_print("Maximum 8bits");
			_delay_ms(2000);
			lcd_print("Set timer(HEX)");
			lcd_showCursor();
			lcd_gotoxy(1,2);
			i = 0;
			continue;
		}
		lcdData(key);
		uint8_t value = ASCII_to_int(key);
		//error correction
		if (value < 0 || value > 15)
		{
			lcd_clear();
			lcd_print("Error :");
			lcdData(key);
			return;
		}
		countdown = countdown<<(4*1);
		countdown += value;
	}
	
//***************  counting down ***************
	while(PINC & (1<<button_pin )){}//wait for button release
	_delay_ms(15);
	PCICR |= (1<<PCIE1);
	lcd_hideCursor();
	uint32_t countdown_backup = countdown;
	while(countdown > 0)
	{	
		char c;
		lcd_clear();
		lcd_gotoxy(1,1);
		lcd_print("Timer(HEX)");
		lcd_gotoxy(1,2);
		for(int i=n_digit;i>=0;i--) 
		{
			uint8_t hexDigit = (countdown >> (4 * i)) & 0xF; // Extract each hex digit using bitwise shift and mask
			c = hex_to_ASCII(hexDigit);
			lcdData(c); 
		}
		if(reset_button==1)
		{	
			reset_button = 0;
			countdown = countdown_backup;
			continue;
		}
		counter_1sec();
		countdown--;
	}
	PCICR &= ~(1<<PCIE1);
	lcd_clear();
	lcd_gotoxy(4,1);
	lcd_print("Time's up!");
	lcd_gotoxy(1,2);
	lcd_print("button=>restart");
	PORTC |= (1<<LED_pin);
	while((PINC & (1<<button_pin )) == 0){}
	_delay_ms(15);
	while(PINC & (1<<button_pin)){}
	PORTC &= ~(1<<LED_pin);
	lcd_showCursor();
}
	
char hex_to_ASCII(int hex) {
	char ascii;	
	if (hex < 0 || hex > 15)
		return '\0'; 
	if (hex >= 0 && hex <= 9)
		ascii = '0' + hex;
	else 
		ascii = 'A' + (hex - 10);
	return ascii; 
}


int ASCII_to_int(char ascii)
{
	int i = -1;
	if (ascii >= '0' && ascii <= '9')
		i = ascii-'0';
	else if (ascii >= 'A' && ascii <= 'F')
		i = ascii-'A'+10;
	return i;
}

void counter_1sec()
{
	TCNT1 = 0x0000;
	TIFR1 |= (1<<OCF1A); // Clear Flag
	while((TIFR1 & (1<<OCF1A))==0)
	{
		if(reset_button)
			break;
	}
}

ISR (PCINT1_vect)
{	
	_delay_ms(15);
	if ((PINC & (1 << button_pin)))
	{	
		reset_button = 1;
	}
	PCIFR |= (1 << PCIF1);
}