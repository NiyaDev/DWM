
SECTION "int_res", ROM0[$11DE]

; Manipulates interrupts then falls into lcd_off
int_res:
	; Reset all interrupts
	xor a
	ldh [rIF],a

	; Enable Keep sSTAT enabled if it already was
	ldh a,[rIE]
	and IEF_UNUSED | IEF_STAT
	ldh [rIE],a

; Waits until VBlank and turns off LCD
lcd_off:
	; Return if LCD is already off
	ld hl,rLCDC
	bit 7,[hl]
	ret z

.loop:
	; Loop until the VBlank
	ldh a,[rLY]
	cp 145
	jr nz,.loop

	; Turn off LCD and mirror in memory
	res 7,[hl]
	ld hl,wUNK_11E7_1
	res 7,[hl]

	ret