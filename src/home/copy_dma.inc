
SECTION "copy_dma", ROM0[$0080]

; `$0080 | Bank:0`
;
; Copy DMA transfer function to HRAM.
copy_dma:
	ld c,_HRAMSTART
	ld b,10
	ld hl,dma_data

.loop:
	ld a,[hl+]
	ldh [c],a
	inc c
	dec b
	jr nz,.loop

	ret


; `$008E | Bank:0`
;
; DMA transfer function
dma_data:
	ld a,$C0
	ldh [rDMA],a
	ld a,40

.LAB_0094: ; Wait 40 loops
	dec a
	jr nz,.LAB_0094

	ret