;
; LAB4.asm
;
; Created: 4/11/2567 20:01:47
; Author : User
;


; Replace with your application code

start:
	CLR R16
	OUT DDRC,R16
	LDI R16,0b101
	OUT DDRB,R16
	CLR R16
	SBIC PINC,1
	SBI PORTB,0
	SBIC PINC,6
	SBI PORTB,2
end:
	jmp end