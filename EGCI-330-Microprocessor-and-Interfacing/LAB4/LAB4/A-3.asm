;
; LAB4.asm
;
; Created: 4/11/2567 20:01:47
; Author : User
;


; Replace with your application code

/*
start:
	SBIS PORTC,3
	SBI PORTB,5
	SBIC PORTC,3
	CBI PORTB,5
end:
	jmp end
*/
/*
start:
	LDI R16, $45
	ROR	R16
	ROR	R16
	ROR	R16
end:
	JMP end
*/
/*
start:
	LDI R16, $45
	ROL	R16
	ROL	R16
	ROL	R16
end:
	JMP end
*/

/*start:
	CLR	R2
	LDI	R21, $FF
	EOR	R2, R21 
end:
	jmp end*/
start:
	CLR	R10
	COM	R10
	LDI	R16, $AA
	EOR	R10, R16
end:
	JMP end