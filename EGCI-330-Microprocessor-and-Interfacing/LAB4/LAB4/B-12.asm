;
; LAB4.asm
;
; Created: 4/11/2567 20:01:47
; Author : User
;


; Replace with your application code
.cseg
.org $200
DATA_PROG: .db "I love Ninny",0,0

.org 0
start:
	LDI ZH,high(DATA_PROG*2)
	LDI ZL,low(DATA_PROG*2)
	LDI XH,high($140)
	LDI XL,low($140)
lop:
	LPM R16,Z+
	ST X+,R16
	CPI R16,0
	BRNE lop
	CALL activity2
end:
	JMP end

activity2:
	LDI ZL,LOW($140)
	LDI ZH,HIGH($140)
	LDI YL,LOW($160)
	LDI YH,HIGH($160)
LOP2:
	MOVW XL,ZL
	LD R16,X
	INC ZL
	MOVW XL,YL
	ST X,R16
	INC YL
	ADD R16,R17
	BRNE LOP2
	RET
