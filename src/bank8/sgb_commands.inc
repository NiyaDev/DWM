
SECTION "4015", ROMX[$4015], BANK[8]

; `$4015 | Bank8`
;
; Sends commands to SGB
sgb_commands:
	; Skip if waiting off
	ld a,[doWait]
	or a
	ret z

	; If wUNK_START_7 == $FF, 
	ld a,[wUNK_START_7]
	cp $FF
	jr nz,.grab_pointer

	ld hl,wUNK_8_4015_1
	jr .load_data

.grab_pointer:
	; sgb_jumptable[wUNK_START_7]
	ld l,a
	ld h,0
	add hl,hl
	ld de,sgb_jumptable
	add hl,de
	ld e,[hl]
	inc hl
	ld d,[hl]

	push de
	pop hl

.load_data:
	; leaves if the SGB command has no length
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


; Jump table contents
def sgb_command_maskfreeze	equ  0
def sgb_command_maskcancel	equ  1
def sgb_command_data1		equ  2
def sgb_command_data2		equ  3
def sgb_command_data3		equ  4
def sgb_command_data4		equ  5
def sgb_command_data5		equ  6
def sgb_command_data6		equ  7
def sgb_command_data7		equ  8
def sgb_command_data8		equ  9
def sgb_command_multione	equ 10
def sgb_command_multitwo	equ 11
def sgb_command_paltrn		equ 12
def sgb_command_attrtrn		equ 13
def sgb_command_palset		equ 14
def sgb_command_pcttran		equ 15
def sgb_command_chrtrnlower	equ 16
def sgb_command_chrtrnupper	equ 17
def sgb_command_palpri		equ 18
def sgb_command_iconenable	equ 19
def sgb_command_maskblack	equ 20
; Jump table
def sgb_jumptable equ $4069
dw SGB_MASKEN_FREEZE
dw SGB_MASKEN_CANCEL
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
dw SGB_CHRTRN_LOWERBG
dw SGB_CHRTRN_UPPERBG
dw SGB_PALPRI
dw SGB_ICONEN
dw SGB_MASKEN_BLACKSCREEN


; Command table
/* Function sent with DATA_SND:
 *	jmp .start
 *	
 *	nop x5
 *	rts
 *	nop x7
 *	
 *.start:
 *	lda $01
 *	cmp [$0C4F]
 *	bne .far
 *	
 *	cmp [$0C48]
 *	bne .far
 *	
 *	lda $C9
 *	cmp $80
 *	bne .close
 *	
 *	lda $CA
 *	cmp $7E
 *	bne .close
 *	
 *	lda $CB
 *	cmp $7E
 *.close:
 *	beq .mid
 *	
 *	lda $C9
 *	cmp $C8
 *	bne .far
 *	
 *	lda $CA
 *	cmp $C4
 *	bne .far
 *	
 *	lda $CB
 *	cmp $05
 *.mid:
 *	bne .far
 *	
 *	ldx $28
 *	lda $E7
 *	sta [$7EC001]
 *	inx
 *	inx
 *	inx
 *	inx
 *	cpx $8C
 *.far:
 *	bne next
 *	rts
 *	
 *	brk 00 x4
 */
SGB_DATASND_1:
db DATA_SND*8 + 1
dw $085D
db 0
db 11
db $8C,$D0,$F4,$60
ds 7

SGB_DATASND_2:
db DATA_SND*8 + 1
dw $0852
db 0
db 11
db $A9,$E7,$9F,$01,$C0	
db $7E,$E8,$E8,$E8,$E8
db $E0

SGB_DATASND_3:
db DATA_SND*8 + 1
dw $0847
db 0
db 11
db $C4,$D0,$16,$A5,$CB
db $C9,$05,$D0,$10,$A2
db $28

SGB_DATASND_4:
db DATA_SND*8 + 1
dw $083C
db 0
db 11
db $F0,$12,$A5,$C9,$C9
db $C8,$D0,$1C,$A5,$CA
db $C9

SGB_DATASND_5:
db DATA_SND*8 + 1
dw $0831
db 0
db 11
db $0C,$A5,$CA,$C9,$7E
db $D0,$06,$A5,$CB,$C9
db $7E

SGB_DATASND_6:
db DATA_SND*8 + 1
dw $0826
db 0
db 11
db $39,$CD,$48,$0C,$D0
db $34,$A5,$C9,$C9,$80
db $D0

SGB_DATASND_7:
db DATA_SND*8 + 1
dw $081B
db 0
db 11
db $EA,$EA,$EA,$EA,$EA
db $A9,$01,$CD,$4F,$0C
db $D0

SGB_DATASND_8:
db DATA_SND*8 + 1
dw $0810
db 0
db 11
db $4C,$20,$08,$EA,$EA
db $EA,$EA,$EA,$60,$EA
db $EA

SGB_MASKEN_FREEZE:
db MASK_EN*8 + 1
db MASK_EN_FREEZE
ds 14

SGB_MASKEN_CANCEL:
db MASK_EN*8 + 1
db MASK_EN_CANCEL
ds 14

SGB_MLTREQ_1P:
db MLT_REQ*8 + 1
db MLT_REQ_1P
ds 14

SGB_MLTREQ_2P:
db MLT_REQ*8 + 1
db MLT_REQ_2P
ds 14

SGB_PALTRN:
db PAL_TRN*8 + 1
ds 15

SGB_ATTRTRN:
db ATTR_TRN*8 + 1
ds 15

SGB_PALSET:
db PAL_SET*8 + 1
db $00,$00
db $01,$00
db $02,$00
db $03,$00
db PAL_SET_CANCEL|PAL_SET_USE|$00
ds 6

SGB_PCTTRN:
db PCT_TRN*8 + 1
ds 15

SGB_CHRTRN_LOWERBG:
db CHR_TRN*8 + 1
db CHR_TRN_LOWER|CHR_TRN_BG
ds 14

SGB_CHRTRN_UPPERBG:
db CHR_TRN*8 + 1
db CHR_TRN_UPPER|CHR_TRN_BG
ds 14

SGB_PALPRI:
db PAL_PRI*8 + 1
db PAL_PRI_SOFT
ds 14

SGB_ICONEN:
db ICON_EN*8 + 1
db ICON_EN_BIPAL_D|ICON_EN_CONSU_E|ICON_EN_REGTR_R
ds 14

SGB_MASKEN_BLACKSCREEN:
db MASK_EN*8 + 1
db MASK_EN_BLANKB
ds 14