
SECTION "14CF", ROM0[$14CF]

; 
FUN_14CF:
	; Locks up game if unk_start_24 != 0
	ld a,[unk_start_24]
	or a
	jr nz,FUN_14CF

	; Sets unk_start_24 to 1 and calls FUN_14E1
	inc a
	ld [unk_start_24],a
	call FUN_14E1

	; Clears unk_start_24
	xor a
	ld [unk_start_24],a

	ret