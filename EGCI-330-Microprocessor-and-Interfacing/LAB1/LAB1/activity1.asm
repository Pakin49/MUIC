	;
; LAB1.asm
;
; Created: 18/10/2567 8:32:46
; Author : User
;


; Replace with your application code
start:
	LDI R16,0xFF
	OUT DDRB,R16
L1: OUT PORTB,R16
 	LDI R20,0
	OUT PORTB,R20
	RJMP L1