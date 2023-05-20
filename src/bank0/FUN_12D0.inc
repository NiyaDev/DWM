
SECTION "12D0", ROM0[$12D0]

; Manipluates data from memory
FUN_12D0:
	push hl
	push de

	; Load pointer
	ld a,[unk_12D0_1]
	ld h,a
	ld a,[unk_12D0_2]
	ld l,a
	
	; Calculate pointer
	; HL = (HL * 4) + $1357
	ld d,h
	ld e,l
	add hl,hl
	add hl,hl
	add hl,de
	ld de,$1357
	add hl,de

	; Save pointer back to mem
	ld a,h
	ld [unk_12D0_1],a
	ld a,l
	ld [unk_12D0_2],a

	pop de
	pop hl

	ret