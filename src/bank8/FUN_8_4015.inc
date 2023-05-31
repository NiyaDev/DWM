
SECTION "4015", ROMX[$4015], BANK[8]

; Sends commands to SGB
sgb_commands:
	ld a,[doWait]
	or a
	ret z

	; If == $FF, 
	ld a,[unk_start_7]
	cp $FF
	jr nz,.grab_pointer

	ld hl,unk_8_4015_1
	jr .load_data

.grab_pointer:
	; unk_start_7 * 2 + $4069
	; Then grab the pointer at that location and put it in HL
	ld l,a
	ld h,0
	add hl,hl
	ld de,$4069
	add hl,de
	ld e,[hl]
	inc hl
	ld d,[hl]

	push de
	pop hl

.load_data:
	; leaves if [hl] & 7 == 0
	ld a,[hl]
	and 7
	ret z

	ld b,a
	ld c,0

.loop:
	push bc

	; Reset SGB data transfer
	ld a,SGB_RES
	ldh [c],a
	ld a,SGB_END
	ldh [c],a

	ld b,$10
.outer_loop:
	ld e,8
	ld a,[hl+]
	ld d,a

.inner_loop:
	bit 0,d
	ld a,SGB_LOW
	jr nz,.set_low

	ld a,SGB_HIG
.set_low:
	ldh [c],a
	ld a,SGB_END
	ldh [c],a

	rr d
	dec e
	jr nz,.inner_loop

	dec b
	jr nz,.outer_loop

	ld a,SGB_HIG
	ldh [c],a
	ld a,P1F_GET_NONE
	ldh [c],a

	pop bc
	dec b
	ret z

	call wait_7000
	jr .loop


; Jump table
dw SGB_MASKEN_CANCEL
dw SGB_MASKEN_ENABLE
dw SGB_DATASND_1
dw SGB_DATASND_2
dw SGB_DATASND_3
dw SGB_DATASND_4
dw SGB_DATASND_5
dw SGB_DATASND_6
dw SGB_DATASND_7
dw SGB_DATASND_8
dw SGB_MLTREQ_1P
dw SGB_MLTREQ_2P
dw SGB_PALTRN
dw SGB_ATTRTRN
dw SGB_PALSET
dw SGB_PCTTRN
dw SGB_CHRTRN_UPPERBG
dw SGB_CHRTRN_LOWERBG
dw SGB_PALPRI
dw SGB_ICONEN
dw SGB_MASKEN_BLACKSCREEN


; Command table
SGB_DATASND_1:
db $79
dw $085D
db 0
db 11
db $8C,$D0,$F4,$60,$00
db $00,$00,$00,$00,$00
db $00

SGB_DATASND_2:
db $79
dw $0852
db 0
db 11
db $A9,$E7,$9F,$01,$C0
db $7E,$E8,$E8,$E8,$E8
db $E0

SGB_DATASND_3:
db $79
dw $0847
db 0
db 11
db $C4,$D0,$16,$A5,$CB
db $C9,$05,$D0,$10,$A2
db $28

SGB_DATASND_4:
db $79
dw $083C
db 0
db 11
db $F0,$12,$A5,$C9,$C9
db $C8,$D0,$1C,$A5,$CA
db $C9

SGB_DATASND_5:
db $79
dw $0831
db 0
db 11
db $0C,$A5,$CA,$C9,$7E
db $D0,$06,$A5,$CB,$C9
db $7E

SGB_DATASND_6:
db $79
dw $0826
db 0
db 11
db $39,$CD,$48,$0C,$D0
db $34,$A5,$C9,$C9,$80
db $D0

SGB_DATASND_7:
db $79
dw $081B
db 0
db 11
db $EA,$EA,$EA,$EA,$EA
db $A9,$01,$CD,$4F,$0C
db $D0

SGB_DATASND_8:
db $79
dw $0810
db 0
db 11
db $4C,$20,$08,$EA,$EA
db $EA,$EA,$EA,$60,$EA
db $EA

SGB_MASKEN_CANCEL:
db $B9,$01,$00,$00
db $00,$00,$00,$00
db $00,$00,$00,$00
db $00,$00,$00,$00

SGB_MASKEN_ENABLE:
db $B9,$00,$00,$00
db $00,$00,$00,$00
db $00,$00,$00,$00
db $00,$00,$00,$00

SGB_MLTREQ_1P:
db $89,$00,$00,$00
db $00,$00,$00,$00
db $00,$00,$00,$00
db $00,$00,$00,$00

SGB_MLTREQ_2P:
db $89,$01,$00,$00
db $00,$00,$00,$00
db $00,$00,$00,$00
db $00,$00,$00,$00

SGB_PALTRN:
db $59,$00,$00,$00
db $00,$00,$00,$00
db $00,$00,$00,$00
db $00,$00,$00,$00

SGB_ATTRTRN:
db $A9,$00,$00,$00
db $00,$00,$00,$00
db $00,$00,$00,$00
db $00,$00,$00,$00

SGB_PALSET:
db $51,$00,$00,$01
db $00,$02,$00,$03
db $00,$C0,$00,$00
db $00,$00,$00,$00

SGB_PCTTRN:
db $A1,$00,$00,$00
db $00,$00,$00,$00
db $00,$00,$00,$00
db $00,$00,$00,$00

SGB_CHRTRN_UPPERBG:
db $99,$00,$00,$00
db $00,$00,$00,$00
db $00,$00,$00,$00
db $00,$00,$00,$00

SGB_CHRTRN_LOWERBG:
db $99,$01,$00,$00
db $00,$00,$00,$00
db $00,$00,$00,$00
db $00,$00,$00,$00

SGB_PALPRI:
db $C9,$01,$00,$00
db $00,$00,$00,$00
db $00,$00,$00,$00
db $00,$00,$00,$00

SGB_ICONEN:
db $71,$01,$00,$00
db $00,$00,$00,$00
db $00,$00,$00,$00
db $00,$00,$00,$00

SGB_MASKEN_BLACKSCREEN:
db $B9,$02,$00,$00
db $00,$00,$00,$00
db $00,$00,$00,$00
db $00,$00,$00,$00