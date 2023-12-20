
SECTION "12C7", ROM0[$12C7]

; `$12C7 | Bank:0`
;
; Fills the allotted amount of memory at destination with fill.
;
; HL - dest, BC - count, A - fill
mem_fill:
	ld d,a

.loop:
	ld [hl],d
	inc hl
	dec bc
	ld a,b
	or c
	jr nz,.loop

	ret