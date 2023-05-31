
SECTION "1627", ROM0[$1627]

; Sets ROM and SRAM banks to d, then loads data using the offset in e and the values in h and l
FUN_1627:
	ld a,d
	ld [rROMB0],a
	swap a
	rra
	and 0x03
	ld	[rRAMB],a

	push hl
	; hl = 0x4001 + (e * 2)
	ld l,e
	ld h,0x00
	add hl,hl
	ld de,0x4001
	add hl,de
	; de = [hl]
	ld e,[hl]
	inc hl
	ld d,[hl]
	pop hl

	; bc = [de]
	ld a,[de]
	ld c,a
	inc de
	ld a,[de]
	ld b,a
	
	inc de
	ld a,[de]
	; 0xFFAB = [de]
	ldh [0xFFAB],a
	inc de
	; 0xFFAC = l
	ld a,l
	ldh [0xFFAC],a
	; 0xFFAD = h
	ld a,h
	ldh [0xFFAD],a
	push hl
	; hl += bc
	add hl,bc
	; 0xFFB1 = l
	ld a,l
	ldh [0xFFB1],a
	; 0xFFB2 = h
	ld a,h
	ldh [0xFFB2],a
	pop hl
	; 0xFFB3 = hl
	ld a,l
	ldh [0xFFB3],a
	ld a,h
	ldh [0xFFB4],a
	ret
