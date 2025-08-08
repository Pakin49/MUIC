;
; LAB4.asm
;
; Created: 4/11/2567 20:01:47
; Author : User
;


; Replace with your application code

.cseg

start:
	LDI	R20, 0xFF
	OUT	DDRD, R20
	//LDI	R20, 0b00000111 ; act1
	LDI	R20, 0b01100111 ; act2
	OUT	PORTD, R20
HERE: 
	RJMP HERE