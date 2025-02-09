
SECTION "422C", ROMX[$422C], BANK[8]

; `$422C | Bank:8`
;
; Copy data from one offset to a predetermined place.
FUN_8_422C:
	; Leave if not SGB
	ld a,[doWait]
	or a
	ret z

	ld a,[wUNK_8_422C_1]
	ld l,a
	ld a,[wUNK_8_422C_1+1]
	ld h,a
	ld de,wUNK_8_422C_5
	call FUN_8_426A

	ld de,wUNK_8_422C_6
	ld a,[wUNK_8_422C_2]
	ld l,a
	ld a,[wUNK_8_422C_2+1]
	ld h,a
	call FUN_8_426A

	ld de,wUNK_8_422C_7
	ld a,[wUNK_8_422C_3]
	ld l,a
	ld a,[wUNK_8_422C_3+1]
	ld h,a
	call FUN_8_426A

	ld de,wUNK_8_422C_8
	ld a,[wUNK_8_422C_4]
	ld l,a
	ld a,[wUNK_8_422C_4+1]
	ld h,a
	call FUN_8_426A

	ret