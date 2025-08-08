;
; LAB3.asm
;
; Created: 1/11/2567 7:54:58
; Author : User
;


; Replace with your application code
.equ DELAY_INNER = 255     ; Inner loop count
.equ DELAY_OUTER = 255     ; Outer loop count

start:
	LDI R16,$FF
	OUT DDRB,R16
	OUT DDRC,R16
	OUT DDRD,R16
	LDI R16,$AA
LOP:
	OUT PORTB,R16
	OUT PORTC,R16
	OUT PORTD,R16
	COM R16
	RCALL delay
	RCALL delay
	JMP LOP

delay:
    LDI R18, DELAY_OUTER   ; Load outer loop counter (800)
L1:
    LDI R19, DELAY_INNER   ; Load inner loop counter (100)
L2:
    NOP                    ; Each NOP takes 1 cycle
    DEC R19                ; Decrement inner loop counter
    BRNE L2           	; Branch if not zero, takes 2 cycles if branch taken, 1 cycle if not
    DEC R18                ; Decrement outer loop counter
    BRNE L1           	; Branch if not zero
    RET                    ; Return from subroutine
