
SECTION "14CF", ROM0[$14CF]

; `$14CF | Bank:0`
;
; Locks up if unk_start_24
FUN_14CF:
	; Locks up game if unk_start_24 != 0
	ld a,[wUNK_START_24]
	or a
	jr nz,FUN_14CF

	; Sets unk_start_24 to 1 and calls FUN_14E1
	inc a
	ld [wUNK_START_24],a
	call FUN_14E1

	; Clears unk_start_24
	xor a
	ld [wUNK_START_24],a

	ret