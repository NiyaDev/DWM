
SECTION "10CF", ROM0[$10CF]

; Wait for 63,000 cycles input times
; Each run is ~.015 seconds each
wait:
	ld a,[doWait]
	or a
	ret z

.LAB_10D4:
	ld de,$06D6
.LAB_10D7:
	nop
	nop
	nop
	
	dec	de
	ld a,d
	or e
	jr nz,.LAB_10D7

	dec bc
	ld a,b
	or c
	jr nz,.LAB_10D4

	ret