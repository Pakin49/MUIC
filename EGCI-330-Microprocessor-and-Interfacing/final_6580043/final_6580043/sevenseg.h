#ifndef SEVENSEG_H
#define SEVENSEG_H

#define SEVENSEG_PORT PORTC
#define SEVENSEG_DDR DDRC

void sevenseg_init(){
	SEVENSEG_DDR |= 0xFF;
}
void sevenseg_put(char key)
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
	if (key >= '0' && key <= '9')
		pattern = seg_patterns[key - '0'];
	else if (key >= 'A' && key <= 'F')
		pattern = seg_patterns[key - 'A' + 10];
	
	// Output the pattern to PORTB
	SEVENSEG_PORT = pattern;
}

/*
int main()
{
	sevenseg_put('c');
}*/
#endif