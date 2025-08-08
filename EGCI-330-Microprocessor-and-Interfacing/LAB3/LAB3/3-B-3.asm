;
; LAB3.asm
;
; Created: 1/11/2567 7:54:58
; Author : User
;


; Replace with your application code

start:
	CLR R16;
	OUT DDRD,R16;
	LDI R16,0xFF;
	OUT DDRB,R16;
	LDI R17,0x55; Value for when PB0 is set;
lop:
	IN R20,PIND;
	OUT PORTB,R20;
	MOV R21,R20;
	MOV R22,R20;
	SBIS PORTB,0;
	OUT PORTB,R17;
	RCALL delay;
	JMP LOP;