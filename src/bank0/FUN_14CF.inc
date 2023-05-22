
SECTION "14CF", ROM0[$14CF]

; 
FUN_14CF:
	ld a,[unk_start_24]
	or a
	jr nz,FUN_14CF

	inc a
	ld [unk_start_24],a
	call FUN_14E1

	xor a
	ld [unk_start_24],a

	ret