
SECTION "1417", ROM0[$1417]

; Sets a variable in HRAM to 0, then clears first 160 spaces in WRAM
FUN_1417:
	xor a
	ldh [unk_high_1417],a

	ld hl,$C000
	ld bc,$00A0
	call mem_fill

	ret