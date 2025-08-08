/*
 * LAB8.c
 *
 * Created: 30/11/2567 15:56:17
 * Author : User
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "USART.h"

#define POT_PIN 0 // ADC0 pin connected to potentiometer

// Initialize ADC
void ADC_Init()
{
	// Set reference voltage to AVCC and left-adjust result (8-bit)
	ADMUX = (1 << MUX0);
	// Enable ADC, enable ADC interrupt, and start conversion
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);
}

// Start ADC conversion
uint16_t ADC_Read(uint8_t channel)
{
	// Select the channel
	ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);
	
	// Start the conversion
	ADCSRA |= (1 << ADSC);
	
	// Wait for the conversion to complete
	while (ADCSRA & (1 << ADSC));
	
	// Return the 10-bit result from ADCL and ADCH
	return ADC;
}

// Convert integer to ASCII string (manual implementation of itoa for 8-bit values)
void int_to_ascii(uint8_t num, char* buffer)
{
	buffer[0] = (num / 100) + '0'; // Hundreds
	buffer[1] = ((num / 10) % 10) + '0'; // Tens
	buffer[2] = (num % 10) + '0'; // Ones
	buffer[3] = '\0'; // Null-terminate the string
}

// Main program
int main(void)
{
	// Initialize USART and ADC
	USART_Init(MYUBRR);
	ADC_Init();
	
	uint16_t adc_value;
	uint8_t scaled_value;
	char buffer[4]; // For storing ASCII representation of ADC value
	
	while (1)
	{
		// Read the potentiometer value (10-bit)
		adc_value = ADC_Read(POT_PIN);
		
		// Scale the 10-bit ADC value to 8-bit using right-shift (divide by 4)
		scaled_value = adc_value >> 2;
		
		// Convert scaled value (8-bit) to ASCII
		int_to_ascii(scaled_value, buffer);
		
		// Send the scaled ADC value via USART (send each character)
		USART_Print(buffer); // Uses your USART_Print function to send string
		
		// Send a newline for better readability in the terminal
		USART_Transmit('\r');
		USART_Transmit('\n');
		
		_delay_ms(100); // Delay to allow for stability in reading
	}
}
