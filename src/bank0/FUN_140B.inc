
SECTION "140B", ROM0[$140B]

; Clears $FFB7->$FFBE
FUN_140B:
	xor a
	ld hl,unk_140B
	call .input

; Sets four bytes to input
.input:
	ld [hl+],a
	ld [hl+],a
	ld [hl+],a
	ld [hl+],a

	ret