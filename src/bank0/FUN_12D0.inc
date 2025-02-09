
SECTION "12D0", ROM0[$12D0]

; Manipluates data from memory
FUN_12D0:
	push hl
	push de

	; Load pointer
	ld a,[wUNK_12D0_1]
	ld h,a
	ld a,[wUNK_12D0_1+1]
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
	ld [wUNK_12D0_1],a
	ld a,l
	ld [wUNK_12D0_1+1],a

	pop de
	pop hl

	ret