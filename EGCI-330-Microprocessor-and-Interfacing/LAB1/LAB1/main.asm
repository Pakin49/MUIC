;
; LAB1.asm
;
; Created: 18/10/2567 8:32:46
; Author : User
;


; Replace with your application code
;6580043
.SET RAM_START = 0x0100
.CSEG
.ORG 0x0000
hello_data:
.DB "HELLO WORLdjifdsoghidh39peghD!"
main:
	LDI YL, LOW(RAM_START)
	LDI YH, HIGH(RAM_START)
	LDI ZL, LOW(2*hello_data)
	LDI ZH, HIGH(2*hello_data)
	LDI R18, 12
copy_loop:
	LPM R16, Z+; Load whatever in hello data&increment hello data
	ST Y+, R16
	DEC R18
	BRNE copy_loop
END:
	rjmp END