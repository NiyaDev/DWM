
SECTION "140B", ROM0[$140B]

FUN_140B:
; Clears $FFB7->$FFBE
	xor a
	ld hl,hSCX
	call .input

; Sets four bytes to input
.input:
	ld [hl+],a
	ld [hl+],a
	ld [hl+],a
	ld [hl+],a

	ret
