;
; LAB3.asm
;
; Created: 1/11/2567 7:54:58
; Author : User
;


; Replace with your application code

;========Press your up-counter code here==========

start:
	CLR R16; R16 FOR value
	LDI R17,0xFF; R17 for set DDRD
	OUT DDRD,R17; 
lop:
	OUT PORTD,R16;
	RCALL delay;
	INC R16;
	JMP lop;
;=================================================


DELAY:	LDI	R21, 5
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
