
SECTION "10CF", ROM0[$10CF]

; `$10CF | Bank:0`
;
; Wait for 63,000 cycles input times.
;
; Each run is ~.015 seconds each
wait:
	; Check if SGB
	ld a,[doWait]
	or a
	ret z

.outer_loop:
	ld de,1750
.inner_loop:
	nop
	nop
	nop
	
	dec	de
	ld a,d
	or e
	jr nz,.inner_loop

	dec bc
	ld a,b
	or c
	jr nz,.outer_loop

	ret