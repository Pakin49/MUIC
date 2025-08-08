;
; LAB4.asm
;
; Created: 4/11/2567 20:01:47
; Author : User
;


; Replace with your application code
.cseg
.org$200
Data: .db 8,0xff

.MACRO ADDI
	LDI R25,@1
	ADD @0,R25
.ENDMACRO

.org 0
start:
	CLR R21
	LDI ZL,low(Data*2)
	LDI ZH,high(Data*2)
	LPM R20,Z
	MUL R20,R20
	MOV R21,R0
	ADD R21,R20
	ADDI R21,9
end:
	JMP end

