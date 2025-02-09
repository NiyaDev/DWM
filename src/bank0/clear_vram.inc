
SECTION "12A5", ROM0[$12A5]

; `$12A5 | Bank:0`
;
; Clear banked VRAM
clear_vram:
	; Clear VRAM tilemap 0
	ld hl,_SCRN0
	ld bc,$0800
	xor a
	call mem_fill

	; Check if GB
	ld a,[IsGBC]
	or a
	ret z

	; Swap to VRAM bank 1
	ld a,1
	ldh [rVBK],a

	; Clear VRAM bank 1
	ld hl,$9800
	ld bc,$800
	xor a
	call mem_fill

	; Return to VRAM bank 0
	ld a,0
	ldh [rVBK],a

	ret