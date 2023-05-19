
SECTION "12C7", ROM0[$12C7]

; HL - dest, BC - count, A - fill
; Fills the alloted amount of memory at destination with fill.
mem_clear:
	ld d,a

.loop:
	ld [hl],d
	inc hl
	dec bc
	ld a,b
	or c
	jr nz,.loop

	ret