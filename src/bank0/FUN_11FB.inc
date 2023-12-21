
SECTION "11FB", ROM0[$11FB]

; `$11FB | Bank:0`
;
; Turns on LCD and if in SGB mode waits and cancels the mask.
FUN_11FB:
	; Turn on LCD
	ld hl,wUNK_11E7_1
	set LCDCB_ON,[hl]
	ld a,[hl]
	ldh [rLCDC],a

	; Wait
	ld a,[doWait]
	or a
	ret z

	; SGB Request: Cancel mask
	SGBCommand sgb_command_maskcancel

	ret