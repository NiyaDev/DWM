
SECTION "426A", ROMX[$426A], BANK[8]

; `$426A | Bank:8`
;
; Copys 8 bytes from (HL*8 + $447E) into DE.
;
; HL - Pointer, DE - Pointer
FUN_8_426A:
	; Multiply HL by 8
	add hl,hl
	add hl,hl
	add hl,hl
	; Add $447E
	ld a,l
	add $7E
	ld l,a
	ld a,h
	adc $44
	ld h,a

	; Loop 8 times, moving whats at HL into DE
	ld c,$08
.LAB_8_4277:
	ld a,[hl+]
	ld [de],a
	inc de
	dec c
	jr nz,.LAB_8_4277

	ret