
SECTION "10E5", ROM0[$10E5]

; Clears the sprite data copied using FUN_113E

; * a-command
; * d-bank
; * e-offset
FUN_10E5:
	; Sets unk_start_7 to input a
	ld [wUNK_START_7],a

	; skip if waiting off
	ld a,[doWait]
	or a
	ret z

	; Turn off LCD and clears some HRAM
	call lcd_off
	call FUN_140B

	; Clears scrolling
	xor a
	ldh [rSCX],a
	ldh [rSCY],a

	; Clearing VRAM Tile block 1
	push de
	ld hl,_VRAM8800
	ld bc,$1000
	xor a
	call mem_fill
	pop de

	; Sets palette to default intensity
	ld a,%11100100
	ldh [rBGP],a

	; 
	ld hl,$8800
	call FUN_14CF

	; Sets the tilemap data to incremental tiles
	ld hl,_SCRN0
	ld de,12
	ld a,$80
	ld c,13
.outer_loop:
	ld b,20
.inner_loop:
	ld [hl+],a
	inc a
	dec b
	jr nz,.inner_loop

	add hl,de
	dec c
	jr nz,.outer_loop

	; Turn on LCD and BG
	ld a,LCDCF_ON | LCDCF_BGON
	ldh [rLCDC],a
	ld [lcdcFlags],a

	; Wait and send SGB command
	ld bc,5
	call wait
	ld hl,jump_sgb_commands
	rst $10

	; Wait then turn off LCD
	ld bc,6
	call wait
	call lcd_off

	ret