

; SGB command
macro SGBCommand
	ld a,\1
	ld [wUNK_START_7],a
	ld hl,jump_sgb_commands
	rst $10
	call wait_7000
endm