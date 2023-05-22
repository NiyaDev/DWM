
SECTION "14E1", ROM0[$14E1]

; 
FUN_14E1:
	ld a,[rRAMB_ex]
	push af

	; TODO: Explore
	call FUN_1627

.LAB_14E8:
	ld a,[de]
	inc de
	push hl
	ld hl,$FFAB
	cp [hl]
	jr z,.LAB_14FC

	pop hl
	ld [hl],a
	inc hl
	
	dec bc
	ld a,b
	or c
	jr nz,.LAB_14E8

	jp .LAB_156A


.LAB_14FC:
	pop hl

	ld a,[de]
	ldh [$B0],a
	inc de
	ld a,[de]
	ldh [$AF],a
	inc de
	ldh a,[$AF]
	push af
	and $0F
	add $04
	cp $13
	jr nz,.LAB_1514

	ld a,[de]
	inc de
	add $13

.LAB_1514:
	ldh [$AF],a
	pop af
	push de
	swap a
	and $0F
	ld d,a
	ldh a,[$B0]
	ld e,a
	push hl
	ldh a,[$AC]
	ld l,a
	ldh a,[$AD]
	ld h,a
	add hl,de
	ld e,l
	ld d,h
	pop hl

.LAB_152B:
	ldh a,[$B2]
	cp d
	jr z,.LAB_1534
	jr c,.LAB_153B
	jr .LAB_1556


.LAB_1534:
	ldh a,[$B1]
	cp e
	jr z,.LAB_153B
	jr nc,.LAB_1556

.LAB_153B:
	ld a,$F0
	add d
	ld d,a
	ldh a,[$B4]
	cp d
	jr z,.LAB_1548
	jr nc,.LAB_154F
	jr .LAB_1556


.LAB_1548:
	ldh a,[$B3]
	cp e
	jr z,.LAB_1556
	jr c,.LAB_1556

.LAB_154F:
	ld a,$10
	add d
	ld d,a
	xor a
	jr .LAB_1557


.LAB_1556:
	ld a,[de]
.LAB_1557:
	ld [hl+],a
	inc de
	dec bc
	ld a,b
	or c
	jr z,.LAB_1569

	ldh a,[$AF]
	dec a
	ldh [$AF],a

	jr nz,.LAB_152B

	pop de

	jp .LAB_14E8


.LAB_1569:
	pop de
.LAB_156A:
	pop af
	ld [rROMB0],a
	swap a
	rra
	and $03
	ld [rRAMB],a

	ret