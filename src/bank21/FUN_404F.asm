
SECTION "404F", ROMX[$404F], BANK[21]

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

; Sets View position to ($07,$FF)
	ld a,7
	ldh [hWX],a
	ld a,$FF
	ldh [hWY],a
; Sets Screen position to (0,0)
	ld a,0
	ldh [hSCY],a
	ld a,0
	ldh [hSCX],a

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
