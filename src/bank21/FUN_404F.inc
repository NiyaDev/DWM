
SECTION "404F", ROMX[$404F], BANK[21]

; Sets a bunch of variables
FUN_21_404F:

	ld hl,unk_21_404F_1
	ld [hl],a
	inc hl
	ld [hl],a

	ld hl,jump_8_422C
	rst $10

	ld hl,jump_95_441C
	rst $10

	ld a,$FC
	call FUN_1688

	ld a,7
	ldh [unk_21_404F_2],a

	ld a,$FF
	ldh [unk_21_404F_3],a

	ld a,0
	ldh [unk_21_404F_4],a

	ld a,0
	ldh [unk_140B],a

	xor a
	ld [unk_start_21_low],a
	ld [unk_start_21_hig],a

	xor a
	ld [unk_21_404F_5],a

	ld a,0
	ld [unk_21_404F_6],a

	ld a,0
	ld [unk_21_404F_7],a
	ld [unk_start_26],a
	ld [unk_21_404F_8],a

	xor a
	ld [unk_21_404F_10],a
	ld [unk_21_404F_9],a

	ld a,3
	ld [unk_11E7_1],a

	ld a,1
;	jp .LAB_11CB