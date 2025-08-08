#ifndef KEYPAD_H
#define KEYPAD_H

// in this version i modified keypad_check() to return int instead
// since we don't need to use with LCD
// doing this make comparing with random value easier
#include <avr/io.h>
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <util/delay.h>

#define KEY_PORT PORTD
#define KEY_PIN PIND
#define KEY_DDR DDRD

int get_key(void);

uint8_t read_key;

void keypad_init()
{
	KEY_DDR |= 0b11100000; // PORTD7,6 For check row PIN0-4 check collumn
	KEY_PORT |= 0x3F; // Enable pull-up resistors for pins 0-5;
}

int keypad_check()
{
	int press;
	//ground all row
	KEY_PORT &= 0b00011111;
	// wait_for_release
	do{read_key = KEY_PIN & (0b00011111);}while(read_key != 0b00011111);
	
	// wait_for_key (2 times to check if key really is pressed)
	do{read_key = KEY_PIN & (0b00011111);}while(read_key == 0b00011111);
	_delay_ms(15);
	do{read_key = KEY_PIN & (0b00011111);}while(read_key == 0b00011111);
	
	press = get_key();
	return press;
}

int get_key()
{
	//char c = 'x';
	int i = 10;
	KEY_PORT = 0b01111111; // ground row0
	_delay_us(10);
	read_key = KEY_PIN & (0b00011111);
	if(read_key != 0b00011111)
	{
		if (!(read_key & (1<<0))) i = 1;
		else if (!(read_key & (1 << 1))) i = 2;
		else if (!(read_key & (1 << 2))) i = 3;
		else if (!(read_key & (1 << 3))) i = 4;
		else if (!(read_key & (1 << 4))) i = 5;
		return i;
	}
	/*
	KEY_PORT = 0b10111111; // ground row1
	_delay_us(10);
	read_key = KEY_PIN & (0b00011111);
	if(read_key != 0b000111111)
	{
		if (!(read_key & (1 << 0))) i = 6;
		else if (!(read_key & (1 << 1))) i = 7;
		else if (!(read_key & (1 << 2))) i = 8;
		else if (!(read_key & (1 << 3))) i = 9;
		else if (!(read_key & (1 << 4))) i = 0;
		return i;
	}
	*/
	return i;
}


#endif