
SECTION "4009", ROMX[$4009], BANK[21]

; Clears and sets a bunch of memory and then uses jumptable
FUN_21_4009:

	; Store return address in unk_21_4009_1
	ld hl, sp+0
	ld a,l
	ld [unk_21_4009_1_low],a
	ld a,h
	ld [unk_21_4009_1_high],a

	; Clears $C8DA->$C8E2
	xor a
	ld hl,unk_21_4009_2
	ld bc,8
	call mem_fill

	; Clears $C827->$C839
	xor a
	ld hl,unk_21_4009_3
	ld bc,18
	call mem_fill

	; Stores $99C1 into WRAM
	ld hl,$99C1
	ld a,l
	ld [unk_21_4009_4_low],a
	ld a,h
	ld [unk_21_4009_4_high],a

	; Clears $C8D2->$C8DA
	xor a
	ld hl,unk_21_4009_5
	ld bc,8
	call mem_fill

	call FUN_1264

	xor a
	ld [unk_start_5],a

	; Uses second byte of unk_start_1
	ld a,[unk_start_1_1]
	rst $00


dw FUN_21_404F
dw $40A0
dw $4172
dw $4218