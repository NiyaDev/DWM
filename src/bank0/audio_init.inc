
SECTION "3331", ROM0[$3331]

; Initiailizes audio
audio_init:
	ld bc,0
	call FUN_336D

	; Output - All sound on
	ld a,AUDENA_ON
	ldh [rNR52],a
	; Panning - Disable
	xor a
	ldh [rNR51],a
	; TODO
	ld [unk_3331_1],a
	; Volume - Disables mixing and sets volume to max
	ld a,$77
	ldh [rNR50],a

	; This loop sets a number of locations to $FF
	ld hl,unk_3331_2
	ld b,$06
	ld a,$FF
.loop:
	ld [HL],a
	ld de,$19
	add hl,de
	ld [hl],a
	ld de,$01
	add hl,de
	dec b
	jr nz,.loop

	; TODO
	xor a
	ld [unk_3331_3],a
	
	ret