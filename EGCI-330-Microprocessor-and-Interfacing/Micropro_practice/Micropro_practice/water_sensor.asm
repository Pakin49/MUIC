;
; midterm.asm
;
; Created: 7/11/2567 10:50:04
; Author : User
;


; Replace with your application code
start:
	LDI R16,0b100
	OUT DDRB,R16
	SBIC PINB,1
	CBI PORTB,2
	SBIS PINB,0
	SBI PORTB,2
	RJMP start

/*
on:
	SBI PORTB,2
check_on:
	SBIC PINB,1
	RJMP off
	RJMP check_on

off:
`	CBI PORTB,2
check_off:
	SBIS PINB,0
	RJMP on
	RJMP check_off
	*/