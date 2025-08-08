/*
 * LAB8.c
 *
 * Created: 30/11/2567 15:56:17
 * Author : User
 */ 

/******************
*			PINB0	PINB1	PINB2	PINB3
*PORTB7		1		2		3		A
*PORTB6		4		5		6		B
*PORTB5		7		8		9		C
*PORTB4		E		0		F		D
******************/

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "LCD.h"

#define KEY_PORT PORTD
#define KEY_PIN PIND 
#define KEY_DDR DDRD

uint8_t read_key;
char key_check(void);

int main()
{	
	KEY_DDR = 0xF0;//pin0-3 INPUT pin4-7 OUTPUT
	lcd_init();
	char press;
	uint8_t char_count = 0, lcd_line = 0;
	while(1)
	{
		//ground all row
		KEY_PORT = 0x0F;
		// wait_for_release
		do{read_key = KEY_PIN & (0x0F);}while(read_key != 0x0F);
			
		// wait_for_key (2 times to check if key really is pressed)
		do{read_key = KEY_PIN & (0x0F);}while(read_key == 0x0F);
		_delay_ms(15);
		do{read_key = KEY_PIN & (0x0F);}while(read_key == 0x0F);
	
		press = key_check();
		if (char_count == 16)
		{
			char_count = 0;
			lcd_gotoxy(1,2);
			lcd_line++;
			if (lcd_line==2)
			{
				lcd_line=0;
				lcd_clear();
				lcd_gotoxy(1,1);
			}
		}
		if (press != 'x')
		{
			lcdData(press);
			char_count++;
		}
	}
}

char key_check()
{
	char c = 'x';
	KEY_PORT  = 0b01111111; // ground row0
	_delay_us(10);
	read_key = KEY_PIN & (0x0F);
	if(read_key != 0x0F)
	{
		if (!(read_key & (1<<0))) c = '1'; 
		else if (!(read_key & (1 << 1))) c = '2';
		else if (!(read_key & (1 << 2))) c = '3';
		else if (!(read_key & (1 << 3))) c = 'A';
		return c;
	}
	KEY_PORT  = 0b10111111; // ground row1
	_delay_us(10);
	read_key = KEY_PIN & (0x0F);
	if(read_key != 0x0F)
	{
		if (!(read_key & (1 << 0))) c = '4';
		else if (!(read_key & (1 << 1))) c = '5';
		else if (!(read_key & (1 << 2))) c = '6';
		else if (!(read_key & (1 << 3))) c = 'B';
		return c;
	}
	KEY_PORT  = 0b11011111; // ground row2
	_delay_us(10);
	read_key = KEY_PIN & (0x0F);
	if(read_key != 0x0F)
	{
		if (!(read_key & (1 << 0))) c = '7';
        else if (!(read_key & (1 << 1))) c = '8';
        else if (!(read_key & (1 << 2))) c = '9';
        else if (!(read_key & (1 << 3))) c = 'C';
		return c;
	}
	KEY_PORT  = 0b11101111; // ground row3
	_delay_us(10);
	read_key = KEY_PIN & (0x0F);
	if(read_key != 0x0F)
	{
		if (!(read_key & (1 << 0))) c = 'E';
        else if (!(read_key & (1 << 1))) c = '0';
        else if (!(read_key & (1 << 2))) c = 'F';
        else if (!(read_key & (1 << 3))) c = 'D';
        return c;
	}
	return c;
}

