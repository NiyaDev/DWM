
SECTION "1024", ROM0[$1024]

; Changes SGB to 2-player mode, looks at rP1, then returns to 1-player mode.
; This is probably a really goofy way of seeing if the game is being run on a SGB.
FUN_1024:
	; SGB Request: 2-Players
	ld a,11
	ld [unk_start_7],a
	ld hl,$0800
	rst $10
	call wait_7000

	; If the current player is not #1, return true
	ldh a,[rP1]
	and SGB_PLAYER1
	cp SGB_PLAYER1
	jr nz,.ret_true

	ld a,SGB_HIG
	ldh [rP1],a
	ldh a,[rP1]
	ldh a,[rP1]
	ld a,SGB_END
	ldh [rP1],a
	ld a,SGB_LOW
	ldh [rP1],a
	ldh a,[rP1]
	ldh a,[rP1]
	ldh a,[rP1]
	ldh a,[rP1]
	ldh a,[rP1]
	ldh a,[rP1]
	ld a,SGB_END
	ldh [rP1],a
	ldh a,[rP1]
	ldh a,[rP1]
	ldh a,[rP1]
	ldh a,[rP1]


	;  If the current player is not #1, return true
	and SGB_PLAYER1
	cp SGB_PLAYER1
	jr nz,.ret_true

	; SGB Request: 1-Player
	ld a,10
	ld [unk_start_7],a
	ld hl,$0800
	rst $10
	call wait_7000
	
	sub a
	
	ret

.ret_true:
	; SGB Request: 1-Player
	ld a,$0A
	ld [unk_start_7],a
	ld hl,$0800
	rst $10
	call wait_7000
	
	scf

	ret