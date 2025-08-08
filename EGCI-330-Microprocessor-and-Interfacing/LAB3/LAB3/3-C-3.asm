;
; LAB3.asm
;
; Created: 1/11/2567 7:54:58
; Author : User
;


; Replace with your application code

;========Press your up-counter code here==========

start:
	CLR R16;
	OUT DDRB,R16;
	LDI R16,0xFF;
	OUT DDRD,R16;
RESET:
	CLR R16;
LOP:
	IN R18,PINB; R18 for set the cap
	MOV R17,R16;
	SUB R18,R17;
	BRLO RESET;
	OUT	 PORTD,R16;
	CALL DELAY;
	INC R16;
	JMP LOP;
;=================================================


DELAY:	LDI	R21, 32
DL1:	LDI	R22, 200
DL2:	LDI	R23, 250
DL3:	NOP
		NOP
		DEC	R23
		BRNE DL3
		DEC	R22
		BRNE DL2
		DEC	R21
		BRNE DL1
		RET
