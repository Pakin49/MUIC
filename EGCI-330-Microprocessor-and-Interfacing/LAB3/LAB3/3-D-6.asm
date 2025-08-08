;
; LAB3.asm
;
; Created: 1/11/2567 7:54:58
; Author : User
;


; Replace with your application code

;========Press your up-counter code here==========

.org $120
data1: .db $54,$76,$65,$98
data2: .db $93,$56,$77,$38

start:
	CLC
	CLR R21; For storing data
	LDI R17,2*high(data1)
	LDI R16,2*low(data1)
	LDI R19,2*high(data2)
	LDI R18,2*low(data2)
	LDI R20,4;LOP counter
	CLR XL
	LDI XH,$01
lop:

	MOV ZH,R17
	MOV ZL,R16
	LPM
	INC R16
	ADC R21,R0
	MOV ZH,R19
	MOV ZL,R18
	LPM
	INC R18
	ADC R21,R0
	ST X+,R21
	CLR R21
	DEC R20
	BRNE lop
end:
	rjmp end