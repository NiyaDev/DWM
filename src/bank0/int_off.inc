
SECTION "11DE", ROM0[$11DE]

; Manipulates interrupts then falls into lcd_off
int_off:
	xor a
	ldh [rIF],a

	ldh a,[rIE]
	and IEF_UNUSED | IEF_STAT
	ldh [rIE],a

; Waits until VBlank and turns of LCD
lcd_off:
	; Return if LCD is off
	ld hl,rLCDC
	bit 7,[hl]
	ret z

.loop:
	; Loop until the VBlank
	ldh a,[rLY]
	cp 145
	jr nz,.loop

	; Turn off LCD
	res 7,[hl]
	ld hl,unk_11E7_1
	res 7,[hl]

	ret