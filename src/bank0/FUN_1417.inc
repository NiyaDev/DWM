
SECTION "1417", ROM0[$1417]

; `$1417 | Bank:0`
;
; Sets a variable in HRAM to 0, then clears first 160 spaces in WRAM
FUN_1417:
	; Clears value
	xor a
	ldh [hUNK_1417],a

	; Fill $C000 -> $C0A0 with 0
	ld hl,$C000
	ld bc,$00A0
	call mem_fill

	ret