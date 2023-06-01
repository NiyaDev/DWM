
SECTION "1288", ROM0[$1288]

; Clear most of RAM and HRAM while preserving DMA_transfer and IsGBC
clear_memory:
	ld a,[IsGBC]
	push af
	
	; Clear $C000->$DE00
	ld hl,$C000
	ld bc,$1E00
	xor a
	call mem_fill

	; Clear HRAM
	ld hl,$FF8A
	ld bc,$0074
	xor a
	call mem_fill

	pop af
	ld [IsGBC],a

	ret