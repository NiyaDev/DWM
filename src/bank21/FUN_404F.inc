
SECTION "404F", ROMX[$404F], BANK[21]

; `$404F | Bank:21`
;
; Sets a bunch of variables
;
; A - 
FUN_21_404F:
	; Saves input a into two places
	ld hl,wUNK_21_404F_1
	ld [hl],a
	inc hl
	ld [hl],a

	; Copy data
	ld hl,jump_8_422C
	rst $10

	; Calls FUN_95_441C
	; TODO
	ld hl,jump_95_441C
	rst $10

	; Calls FUN_1688
	; TODO
	ld a,$FC
	call FUN_1688

	; Sets a couple HRAM values
	ld a,7
	ldh [hUNK_21_404F_2],a
	ld a,$FF
	ldh [hUNK_21_404F_3],a
	ld a,0
	ldh [hUNK_21_404F_4],a
	ld a,0
	ldh [hUNK_140B],a

	; Clears a couple WRAM values
	xor a
	ld [wUNK_START_21],a
	ld [wUNK_START_21+1],a
	xor a
	ld [wUNK_21_404F_5],a
	ld a,0
	ld [wUNK_21_404F_6],a
	ld a,0
	ld [wUNK_21_404F_7],a
	ld [wUNK_START_26],a
	ld [wUNK_21_404F_8],a
	xor a
	ld [wUNK_21_404F_10],a
	ld [wUNK_21_404F_9],a

	; Turn on OBJs and BGs
	ld a,LCDCF_OBJON & LCDCF_BGON
	ld [lcdcFlags],a

	; Jumps to FUN_11CB
	ld a,IEF_VBLANK
	jp FUN_11CB