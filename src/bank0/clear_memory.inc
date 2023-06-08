
SECTION "clear_memory", ROM0[$1288]

; Clear most of RAM and HRAM while preserving DMA_transfer and IsGBC
clear_memory:
	ld a,[IsGBC]
	push af
	
	; Clear $C000->$DE00
	ld hl,_RAM
	ld bc,$1E00
	xor a
	call mem_fill

	; Clear HRAM
	ld hl,_HRAMP
	ld bc,$0074
	xor a
	call mem_fill

	pop af
	ld [IsGBC],a

	ret