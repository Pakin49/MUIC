;
; LAB3.asm
;
; Created: 1/11/2567 7:54:58
; Author : User
;


; Replace with your application code

;========Press your up-counter code here==========

start:
	LDI R16,0xFF;
	OUT DDRD,R16;
	LDI R18, 10; for checking if == 10;
RESET:
	CLR R16;
LOP:
	OUT PORTD,R16;
	MOV R17,R16;
	CALL DELAY;
	SUB R18,R17;
	BREQ RESET;
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
