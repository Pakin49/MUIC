;
; Midterm.asm
;
; Created: 8/11/2567 8:03:14
; Author : User
;

;
.dseg
.org $100
my_data:

.cseg
.org $100
encoded_string:
.db "VGhlIHF1aWNrIGJyb3duIGZveCBqdW1wcyBvdmVyIHRoZSBsYXp5IGRvZw==",0,0
;this Macro Store the 6bits value in the REGISTER
;from arguement @0
.macro get6bits
	MOVW Z,X;store sencoded string data
	LPM @0,Z+
	MOVW X,Z
	LDI ZL,low(base64_data*2)
	LDI ZH,high(base64_data*2)
	ADD ZL,@0
	BRCC NO_CARRY
	INC ZH
NO_CARRY:
	LPM @0,Z
.endmacro

start:
	LDI XL,low(encoded_string*2) ; X stores encoded_string addr
	LDI XH,high(encoded_string*2)
	LDI YL,low(my_data)
	LDI YH,high(my_data)
	LDI R21,16; LOP counter
LOP:
	get6bits R16
	get6bits R17
	get6bits R18
	get6bits R19
	CALL arrange
	ST Y+,R16
	ST Y+,R17
	ST Y+,R18
	DEC R21
	BRNE LOP
end:
	RJMP end
arrange:
	;arrange from 4 to 3
	LSL R16
	LSL R16
	;filter two MSB
	LDI R20,0b00110000
	AND R20,R17
	SWAP R20
	ADD R16,R20
	;2nd bit
	LDI R22,0b00001111
	AND R17,R22
	SWAP R17
	MOV R20,R18
	LSR R20
	LSR R20
	ADD R17,R20

	LDI R20,0b00000011
	AND R20,R18
	SWAP R20
	LSL R20
	LSL R20
	ADD R20,R19
	MOV R18,R20
	RET

.org $300
base64_data:
	.db -1,-1,-1,-1,-1,-1,-1,-1
	.db -1,-1,-1,-1,-1,-1,-1,-1
	.db -1,-1,-1,-1,-1,-1,-1,-1
	.db -1,-1,-1,-1,-1,-1,-1,-1
	.db -1,-1,-1,-1,-1,-1,-1,-1
	.db -1,-1,-1,62,-1,-1,-1,63
	.db 52,53,54,55,56,57,58,59 ; 0-7
	.db 60,61,-1,-1,-1,-1,-1,-1; 8-9
	.db -1,0,1,2,3,4,5,6
	.db 7,8,9,10,11,12,13,14
	.db 15,16,17,18,19,20,21,22
	.db 23,24,25,-1,-1,-1,-1,-1
	.db -1,26,27,28,29,30,31,32
	.db 33,34,35,36,37,38,39,40
	.db 41,42,43,44,45,46,47,48
	.db 49,50,51,-1,-1,-1,-1,-1

