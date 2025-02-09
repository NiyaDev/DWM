
SECTION "11CB", ROM0[$11CB]

; `$11CB | Bank:0`
;
; 
;
; A - Interrupt Flags
FUN_11CB:
	push af

	ld a,[wUNK_START_26]
	or a
	jr z,.LAB_11D5
	; Calls if wUNK_START_26 != 0
	; TODO
	call FUN_1D45
	
.LAB_11D5:
	; Turn on LCD and apply flags
	call lcd_on

	; Reset interrupt flags and set input
	pop af
	call FUN_1227

	ei
	ret