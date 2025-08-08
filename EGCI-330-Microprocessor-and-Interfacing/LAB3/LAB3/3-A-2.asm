;
; LAB3.asm
;
; Created: 1/11/2567 7:54:58
; Author : User
;


; Replace with your application code

.CSEG
START: 
	LDI R17,6; LOOP COUNTER And Value
	LDI XH, $02;
	LDI XL, $9D;
	LDI R16,$02;
	OUT SPH,R16;
	LDI R16,$9D;
	OUT SPL,R16;
LOP:
	ST X-,R17;
	DEC XL;
	DEC R17;
	BRNE LOP;
	
	POP R20;
	POP R21;
	POP R22;
	POP R23;
	POP R24;
	POP R25;
END:
	JMP END;