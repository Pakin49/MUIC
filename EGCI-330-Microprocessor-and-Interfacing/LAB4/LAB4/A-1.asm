;
; LAB4.asm
;
; Created: 4/11/2567 20:01:47
; Author : User
;


; Replace with your application code
setup:
	CLR R16
	OUT DDRD,R16
	LDI R16,0b111
	OUT DDRB ,R16
start:
	IN R16,PIND
	LDI R17,0b00001110
	AND R16,R17
	ASR R16
	OUT PORTB,R16
end:
	RJMP end