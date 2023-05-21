
SECTION "1024", ROM0[$1024]

; 
FUN_1024:
	; SGB Request: 2-Players
	ld a,11
	ld [unk_start_7],a
	ld hl,$0800
	rst $10
	call wait_7000

	; If the current player is not #1, return true
	ldh a,[rP1]
	and 3
	cp 3
	jr nz,.ret_true

	ld a,P1F_GET_DPAD
	ldh [rP1],a
	ldh a,[rP1]
	ldh a,[rP1]
	ld a,P1F_GET_NONE
	ldh [rP1],a
	ld a,P1F_GET_BTN
	ldh [rP1],a
	ldh a,[rP1]
	ldh a,[rP1]
	ldh a,[rP1]
	ldh a,[rP1]
	ldh a,[rP1]
	ldh a,[rP1]
	ld a,P1F_GET_NONE
	ldh [rP1],a
	ldh a,[rP1]
	ldh a,[rP1]
	ldh a,[rP1]
	ldh a,[rP1]


	; Check if either left+right or B+A are pressed
	and P1F_1 | P1F_0
	cp P1F_1 | P1F_0
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