;
; LAB3.asm
;
; Created: 1/11/2567 7:54:58
; Author : User
;


; Replace with your application code

;========Press your up-counter code here==========

start:
	OUT DDRB,R16;
	LDI R18,4; Prepared 4 for ADD
	
	IN R16, PORTC;
	IN R17, PORTD;
	ADD R16,R18;
	MUL R16,R17;
	
	OUT PORTB,R1;
	OUT PORTB,R0;

end:
	JMP end;