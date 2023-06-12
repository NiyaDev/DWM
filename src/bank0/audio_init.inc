
SECTION "3331", ROM0[$3331]

; Initiailizes audio
audio_init:
	; FUN_336D(0,0)
	ld bc,0
	call FUN_336D

	; Output - All sound on
	ld a,AUDENA_ON
	ldh [rNR52],a

	; Panning - Disable
	xor a
	ldh [rNR51],a

	; Set to 0
	ld [wUNK_3331_1],a

	; Volume - Disables mixing and sets volume to max
	ld a,$77
	ldh [rNR50],a

	; This loop sets a number of locations to $FF
	ld hl,wUNK_3331_2
	ld b,6
	ld a,$FF
.loop:
	ld [HL],a
	ld de,25
	add hl,de
	ld [hl],a
	ld de,1
	add hl,de
	dec b
	jr nz,.loop

	; Set to 0
	xor a
	ld [wUNK_3331_3],a
	
	ret