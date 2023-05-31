
SECTION "1627", ROM0[$1627]

; Sets ROM and SRAM banks to d, then loads data using the offset in e and the values in h and l
FUN_1627:
	ld a,d
	ld [rROMB0],a
	swap a
	rra
	and $03
	ld	[rRAMB],a

	push hl
	; hl = $4001 + (e * 2)
	ld l,e
	ld h,$00
	add hl,hl
	ld de,$4001
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
	; $FFAB = [de]
	ldh [$FFAB],a
	inc de
	; $FFAC = l
	ld a,l
	ldh [$FFAC],a
	; $FFAD = h
	ld a,h
	ldh [$FFAD],a
	push hl
	; hl += bc
	add hl,bc
	; $FFB1 = l
	ld a,l
	ldh [$FFB1],a
	; $FFB2 = h
	ld a,h
	ldh [$FFB2],a
	pop hl
	; $FFB3 = hl
	ld a,l
	ldh [$FFB3],a
	ld a,h
	ldh [$FFB4],a
	ret
