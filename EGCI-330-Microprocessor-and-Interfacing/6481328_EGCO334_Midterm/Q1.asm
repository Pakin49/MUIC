
; auto water pump

.org 0x0000
	
	ldi r16, 0x00
	out ddrb, r16
	out ddrc, r16
	ldi r16, 0xff
	out ddrd, r16

	out portb, r16		; pull up
	out portc, r16		; pull up

start:
	ldi r16, 0x00
	out portd, r16
check_c:
	in r17, pinc		; a
	cpi r17, 0x00	
	breq check_b
	jmp start
check_b:
	in r18, pinb		; b
	cpi r18, 0x00
	breq pumpon
	jmp check_c
pumpon:
	ldi r19, 0xff
	out portd, r19
	jmp check_c
