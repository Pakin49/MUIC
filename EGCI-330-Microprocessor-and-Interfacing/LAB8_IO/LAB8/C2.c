/*
 * LAB8.c
 *
 * Created: 30/11/2567 15:56:17
 * Author : User
 */ 

#include <avr/io.h>
#define FOSC 16000000 //Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1


void USART_Init(unsigned int ubrr){
	//Set baud rate
	UBRR0H = (unsigned char)(ubrr>>8);
	UBRR0L = (unsigned char)(ubrr);
	//Enable receiver and transmitter
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	//Set frame format: 8data, 2stop bit
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}


unsigned char USART_Receive(void){
	//Wait for data to be received
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
}


void USART_Transmit(unsigned char data){
	//Wait for empty transmit buffer
	while(!(UCSR0A & (1<<UDRE0)));
	//Put data into buffer, sends the data
	UDR0 = data;
}

int main(void){
	USART_Init(MYUBRR);
	while(1){
		//USART_Transmit(USART_Receive());
	}
}

/* answer
A1 : it send what ever we type back to I/O virtual terminal because we USART_Transmit(USART_Receive())
A2 : it will does nothing because we do nothing*/
