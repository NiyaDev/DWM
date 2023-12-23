
SECTION "11FB", ROM0[$11FB]

; `$11FB | Bank:0`
;
; Turns on LCD and if in SGB mode waits and cancels the mask.
lcd_on:
	; Turn on LCD and apply other controls
	ld hl,lcdcFlags
	set LCDCB_ON,[hl]
	ld a,[hl]
	ldh [rLCDC],a

	; Check if SGB
	ld a,[doWait]
	or a
	ret z

	; SGB Request: Cancel mask
	SGBCommand sgb_command_maskcancel

	ret