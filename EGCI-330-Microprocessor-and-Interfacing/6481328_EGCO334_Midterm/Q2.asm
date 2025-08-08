
; logic gate operation with symbol to 7 seg

.macro getsevenseg
	cpi @0, 0b00000000
	breq getNOT
	cpi @0, 0b00000100
	breq getOR
	cpi @0, 0b00001000
	breq getAND
	cpi @0, 0b00001100
	breq getXOR

	; using bit 7 to be the input of digit
	getNOT: ldi @1, 0b01000000 jmp fin
	getOR:  ldi @1, 0b00011100 jmp fin
	getAND: ldi @1, 0b01010100 jmp fin
	getXOR: ldi @1, 0b01011100 jmp fin
	fin: nop
.endmacro

.macro findop
	cpi @0, 0b00000000
	breq getNOT
	cpi @0, 0b00000100
	breq getOR
	cpi @0, 0b00001000
	breq getAND
	cpi @0, 0b00001100
	breq getXOR

	getNOT: com r18		; com input bit 0
			andi r18, 0b00000001
			jmp fin
	getOR:  or r18, r19
			jmp fin
	getAND: and r18, r19
			jmp fin
	getXOR: eor r18, r19
			jmp fin
	fin: nop
.endmacro

.org 0x0000

	ldi r16, 0x00
	out ddrc, r16
	ldi r16, 0xff
	out ddrb, r16
	out ddrd, r16

	clr r18
	clr r19
	clr r22
start:
	in r17, pinc	; 0000xxxx
	mov r18, r17	; 0
	mov r19, r17	; 1
	mov r20, r17	; logic
; in bit 0
	andi r18, 0b00000001
	or r22, r18
; in bit 1
	andi r19, 0b00000010
	or r22, r19
	lsr r19
; logic
	andi r20, 0b00001100
	getsevenseg r20, r21
	findop r20
; output r18 now have ans
	lsl r18
	lsl r18
	lsl r18
	or r22, r18
	call waitanddis
	jmp start

displayoutput:
	out portb, r21
	out portd, r22
	call delay
	ret

delay:
	sts 0x0300, r16
	sts 0x0301, r17
	sts 0x0302, r18
	ldi r16, 100
l1: ldi r17, 200
l2: ldi r18, 250
l3:
	nop
	call displayoutput
	dec r18
	brne l3
	dec r17
	brne l2
	dec r16
	brne l1
	lds r16, 0x0300
	lds r17, 0x0301
	lds r18, 0x0302
	ret

waitanddis:
	sts 0x318, r18
	sts 0x319, r19
	sts 0x320, r20
	ldi r18, 2
wd1: ldi r19, 2
wd2: ldi r20, 10
wd3: nop
	rcall displayoutput
	dec r20
	brne wd3
	dec r19
	brne wd2
	dec r18
	brne wd1
	ret