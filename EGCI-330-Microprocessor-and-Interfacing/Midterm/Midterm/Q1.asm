;
; Midterm.asm
;
; Created: 8/11/2567 8:03:14
; Author : User
;

;
.MACRO CHECK
	LDI ZH,high(data7seg*2)
	LDI ZL,low(data7seg*2)
	ADD ZL,@0
	LPM @0,Z
.ENDMACRO

start:
	LDI R16,$FF
	OUT DDRD,R16
	OUT DDRB,R16
	LDI R21,$00

seven_seg:
	RCALL mod10 ; get digit0 in r22
	RCALL div10; get digit1, in r23
	CHECK R22
	CHECK R23
display:
	LDI R16,0b01
	OUT PORTB,R16
	OUT PORTD,R22
	CALL DELAY
	COM R16
	OUT PORTB,R16	
	OUT PORTD,R23
	CALL DELAY
	COM R16
	OUT PORTB,R16
	SBIC PINC,1
	INC R21
	SBIC PINC,0
	RJMP RESET
	CPI R21,100
	BREQ RESET
	RJMP seven_seg
RESET:
	CLR R21
	RJMP seven_seg
;mod 10 and mov value to r22
mod10:
	CLR R19
	MOV R22,R21
lop_mod10:
	CPI R22,10
	BRLO done_mod10
	SUBI R22,10
	RJMP lop_mod10
done_mod10:
	RET

div10:
	CLR R19
	MOV R23,R21
lop_div10:
	CPI R23,10
	BRLO done_div10
	SUBI R23,10
	INC R19
	RJMP lop_div10
done_div10:
	MOV R23,R19
	RET
	
	
data7seg:
	.db 0b00111111,0b00000110; 0,1
	.db 0b01011011,0b01001111; 2,3
	.db 0b01100110,0b01101101; 4,5
	.db 0b01111101,0b00000111; 6,7
	.db 0b01111111,0b01101111; 8,9
	.db 0b01011111,0b01111100; a,b
	.db 0b00111001,0b01011110; c,d
	.db 0b01111001,0b01110001; E,F

DELAY:	LDI	R25, 12
DL1:	LDI	R26, 200
DL2:	LDI	R27, 250
DL3:	NOP
		NOP
		DEC	R27
		BRNE DL3
		DEC	R26
		BRNE DL2
		DEC	R25
		BRNE DL1
		RET