
SECTION "copy_dma", ROM0[$0080]

; Copy DMA transfer function to HRAM
copy_dma:
	ld c,_HRAMSTART
	ld b,$0A
	ld hl,dma_data

.loop:
	ld a,[hl+]
	ldh [c],a
	inc c
	dec b
	jr nz,.loop

	ret

dma_data: db $3E,$C0,$E0,$46,$3E,$28,$3D,$20,$FD,$C9