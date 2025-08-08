;
; LAB3.asm
;
; Created: 1/11/2567 7:54:58
; Author : User
;


; Replace with your application code

;========Press your up-counter code here==========

start:
	LDI R16,$FF;
	OUT DDRB,R16;
	IN R16,PORTB;
	IN R17,PORTD;
	ADD R16,R17;
	ASR R16;
	OUT PORTB,R16;
end:
	RJMP end;