
SECTION "1013", ROM0[$1013]

; Waits for 36 cycles 7000 times
; Roughly translates to ~.06 seconds
wait_7000:
	ld a,[doWait]
	or a
	ret z

	ld de,7000
.loop:
	nop
	nop
	nop

	dec de
	ld a,d
	or e
	jr nz,.loop

	ret