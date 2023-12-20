
SECTION "1024", ROM0[$1024]

; `$1024 | bank:0`
;
; Detects if the game is in a SGB
;
; Returns bool in carry
check_sgb:
	; sgb_commands: 2-Players
	ld a,sgb_command_multitwo
	ld [wUNK_START_7],a
	ld hl,jump_sgb_commands
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

	; sgb_commands: 1-Player
	ld a,sgb_command_multione
	ld [wUNK_START_7],a
	ld hl,jump_sgb_commands
	rst $10
	call wait_7000
	
	sub a
	ret

.ret_true:
	; sgb_commands: 1-Player
	ld a,sgb_command_multione
	ld [wUNK_START_7],a
	ld hl,jump_sgb_commands
	rst $10
	call wait_7000
	
	scf
	ret