
SECTION "11BC", ROM0[$11BC]

; `$11BC | Bank:0`
;
; Clears memory from `$C777->$C787`.
FUN_11BC:
	push hl
	push bc

	xor a
	ld hl,$C777
	ld c,$10
.LAB_11C4:
	ld [hl+],a
	dec c
	jr nz,.LAB_11C4

	pop bc
	pop hl
	ret