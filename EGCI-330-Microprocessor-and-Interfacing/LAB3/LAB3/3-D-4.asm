;
; LAB3.asm
;
; Created: 1/11/2567 7:54:58
; Author : User
;


; Replace with your application code

;========Press your up-counter code here==========

.org $200
mydata:
	.db 94,34,82,129,45,67,15,69,9,10

start:
	LDI ZH,2*high(mydata)
	LDI R17,10; loop counter
lop:
	LPM R16,Z+
	ADD YL,R16
	DEC R17
	BRNE lop
	MOV ZL,YL
	MOV ZH,YH
end:
	jmp end;