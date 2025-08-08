;
; LAB3.asm
;
; Created: 1/11/2567 7:54:58
; Author : User
;


; Replace with your application code

;========Press your up-counter code here==========

.org 0x300
mydata:
	.db $94,$34,$82,$29,$45,$67,$15,$69,$9,$10
.org 0x200;
start:
	LDI ZH,2*high(mydata)
	CLR ZL
	LDI R17,10; loop counter
lop:
	LPM R16,Z+
	ADD YL,R16
	DEC R17
	BRNE lop
	MOV ZH,YH
	MOV ZL,YL
end:
	jmp end;