
SECTION "441C", ROMX[$441C], BANK[95]

; `$441C | Bank:95`
;
; 
FUN_95_441C:
	ld a,[wUNK_START_1_3]
	rst $00

dw .jmp0, .jmp1, .jmp2
dw .jmp3, .jmp4, .jmp5
dw .jmp6


; `$442E | Bank:95`
;
; A jumptable within a jump table.
.jmp0:
	ld a,[wUNK_START_1_4]
	rst $00

dw .jmp0_0, .jmp0_1, .jmp0_2
.jmp1:
.jmp2:
.jmp3:
.jmp4:
.jmp5:
.jmp6:

; `$4439 | Bank:95`
;
; 
.jmp0_0:
	ld a,2
;	call FUN_1C89
	call wait_7000

	; Clear _SCRN0
	xor a
	ld hl,_SCRN0
	ld bc,$0400
	call mem_fill

	; Clear $C0D8 -> $C100 in RAM
	xor a
	ld hl,$C0D8
	ld bc,$0028
	call mem_fill

	; 
	ld de,$560E
	ld bc,$9000
	call FUN_14CF

	ld de,$669D
	ld hl,$9800
;	call FUN_95_4263

	ld a,0
	ld [wUNK_95_441C_1],a
	ld hl,$170B
	rst $10

	ld de,$3F00
	ld a,1
	ldh [rVBK],a
	ld hl,$9800

	; If on DMG call FUN_14CF
	ld a,[IsGBC]
	or a
	call nz,FUN_14CF

	ld a,0
	ldh [rVBK],a
	ret

.jmp0_1:
.jmp0_2: