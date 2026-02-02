
SECTION "vblank-func", ROM0[$036E]


; `$036E | Bank:0`
; DEF
FUN_036E::
	push af
	push bc
	push de
	push hl

; if bit 0 of wUNK_START_20 is false
	ld hl,wUNK_START_20
	bit 0,[hl]
	jp nz,.LAB_045C
	set 0,[hl]

	call _RUNDMA
	call FUN_05AD
	call FUN_124C
	call copy_scvi
	call FUN_056E
	call FUN_1240

; if wUNK_START_26 == 0
	ld a,[wUNK_START_26]
	or a
	jr z,.LAB_039B

; if wUNK_START_23 == 0
	ld a,[wUNK_START_23]
	or a
	call z,FUN_3473

.LAB_039B:
	ei

; if wUNK_START_26 != 0
	ld a,[wUNK_START_26]
	or a
	jr nz,.LAB_03B3

	call FUN_12EE
	call FUN_1364

; wUNK_START_23++
	ld hl,wUNK_START_23
	inc [hl]

	call FUN_3473

; wUNK_START_23 = 0
	xor a
	ld [wUNK_START_23],a

.LAB_03B3:
	call FUN_1BB1
	call FUN_046B

; if wUNK_START_26 != 0
	ld a,[wUNK_START_26]
	or a
	jr nz,.LAB_03D9

; if wUNK_START_9 != 0
	ld a,[wUNK_START_9]
	or a
	call nz,FUN_0618

	call FUN_17EC

; wUNK_START_21++
	ld a,[wUNK_START_21]
	add 1
	ld [wUNK_START_21],a
	ld a,[wUNK_START_21+1]
	adc 0
	ld [wUNK_START_21+1],a

.LAB_03D9:
; if wUNK_036E_1 != 15
	ld a,[wUNK_036E_1]
	and $0F
	cp $0F
	jr nz,.LAB_03E9

; if wUNK_START_26 == 0
	ld a,[wUNK_START_26]
	or a
	jp z,Start.LAB_015A

.LAB_03E9:
; if wUNK_START_26 != 0
	ld a,[wUNK_START_26]
	or a
	jr nz,.LAB_044D

	ld a,[wUNK_036E_1]
	and $03
	cp $03
	jr .LAB_044D

db $FA,$46,$C8,$CB,$57,$28,$20,$21,$AD,$C8,$FA,$8A,$C8,$22,$FA,$8B,$C8,$22,$FA,$8C,$C8,$22,$FA,$8D,$C8,$77,$3E,$07,$EA,$8A,$C8,$AF,$EA,$8B,$C8,$21,$8E,$C8,$34,$FA,$42,$C8,$CB,$5F,$28,$27,$FA,$46,$C8,$CB,$57,$28,$20,$21,$AD,$C8,$FA,$8A,$C8,$22,$FA,$8B,$C8,$22,$FA,$8C,$C8,$22,$FA,$8D,$C8,$77,$3E,$0C,$EA,$8A,$C8,$AF,$EA,$8B,$C8,$21,$8E,$C8,$34

.LAB_044D:
	ld hl,wUNK_START_20
	res 0,[hl]
.return:
	ldh a,[rLY]
	ld [wUNK_036E_2],a

	pop hl
	pop de
	pop bc
	pop af

	reti


.LAB_045C:
	call FUN_1240

; if wUNK_START_23 != 0
	ld a,[wUNK_START_23]
	or a
	jr nz,.LAB_0468

	call FUN_3473

.LAB_0468:
	ei
	jr .return
