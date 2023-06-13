
SECTION "113E", ROM0[$113E]

; Called three times when a new sgb border is needed
; - Call 1: Init PAL_TRN
; - Call 2: Copy lower BG
; - Call 3: Copy upper BG
; * a-command
; * d-bank
; * e-offset
; * bc-count
sgb_copy_border:
	; Sets unk_start_7 to input a
	ld [wUNK_START_7],a

	; Checks if waiting is on
	ld a,[doWait]
	or a
	ret z

	push bc
	; Turns off lcd and clears some HRAM
	call lcd_off
	call FUN_140B

	; Clears scrolling
	xor a
	ldh [rSCX],a
	ldh [rSCY],a

	; Sets palette to default intensity
	ld a,%11100100
	ldh [rBGP],a
	pop bc

	; Saves current SRAM bank
	ld a,[rRAMB]
	push af
	push bc

	; Sets ROM and SRAM banks to input d
	ld a,d
	ld [rROMB0],a
	swap a
	rra
	and $03
	ld [rRAMB],a

	; Grabs ptr from table with offset of e
	; hl = $4001 + (e * 2)
	ld a,e
	add a
	ld e,a
	ld d,0
	ld hl,$4001
	add hl,de
	ld e,[hl]
	inc hl
	ld d,[hl]

	pop bc

	; Copies data at ptr to VRAM Tile block 1
	; Runs bc times
	ld hl,_VRAM8800
.copy_data:
	ld a,[de]
	ld [hl+],a
	inc de
	dec bc
	ld a,b
	or c
	jr nz,.copy_data

	; Sets the tilemap data to use the copied data
	ld hl,_SCRN0
	ld de,12
	ld a,$80
	ld c,13
.set_map:
	ld b,20
.set_line:
	ld [hl+],a
	inc a
	dec b
	jr nz,.set_line

	add hl,de
	dec c
	jr nz,.set_map

	; Turn on LCD and BG
	ld a,LCDCF_ON | LCDCF_BGON
	ldh [rLCDC],a
	ld [wUNK_11E7_1],a

	; Wait and send SGB command
	ld bc,5
	call wait
	ld hl,jump_sgb_commands
	rst $10

	; Wait then turn off LCD
	ld bc,6
	call wait
	call lcd_off

	; Reset ROM and SRAM banks to originals
	pop af
	ld [rROMB0],a
	swap a
	rra
	and $03
	ld [rRAMB],a

	ret