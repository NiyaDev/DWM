
SECTION "10E5", ROM0[$10E5]

; 
FUN_10E5:
	ld [unk_start_7],a

	; skip if waiting off
	ld a,[doWait]
	or a
	ret z

	; Turn off LCD and clears some HRAM
	call lcd_off
	call FUN_140B

	; Reset X/Y scrolling
	xor a
	ldh [rSCX],a
	ldh [rSCY],a

	; Clearing VRAM
	push de
	ld hl,$8800
	ld bc,$1000
	xor a
	call mem_fill
	pop de

	ld a,$E4
	ldh [rBGP],a

	; TODO: Explore
	ld hl,$8800
	call FUN_14CF

	; Sets VRAM to values starting with $80 in chunks of 20 seperated by 12
	; 260 times incrementing A each time
	ld hl,$9800
	ld de,$000C
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
	ld [unk_11E7_1],a

	; SGB Request based on input A
	ld bc,5
	call wait
	ld hl,$0800
	rst $10
	ld bc,6
	call wait

	; Turn LCD back off
	call lcd_off

	ret