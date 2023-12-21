
SECTION "11CB", ROM0[$11CB]

; `$11CB | Bank:0`
;
; 
FUN_11CB:
	push af

	ld a,[wUNK_START_26]
	or a
	jr z,.LAB_11D5

	; Calls if wUNK_START_26 == 0
	call FUN_1D45
	
.LAB_11D5:
	call FUN_11FB

	pop af
	call FUN_1227

	ei
	ret