	.EQU SUM = 0x300
	.ORG 00
	LDI R16, 0x25
	LDI R17, $34
	LDI R18, 0b00110001
	ADD R16, R17
	ADD R16, R18
	LDI R17, 11
	ADD R16, R17
	STS SUM, R16
HERE: JMP HERE


.SET RAM_START = 0x0100
.CSEG
.ORG 0x0000
hello_data:
.DB "HELLO WORLD!"
main:
	LDI YL, LOW(RAM_START)
	LDI YH, HIGH(RAM_START)
	LDI ZL, LOW(2*hello_data)
	LDI ZH, HIGH(2*hello_data)
	LDI R18, 12
copy_loop:
	LPM R16, Z+
	ST Y+, R16
	DEC R18
	BRNE copy_loop
END:
	rjmp END