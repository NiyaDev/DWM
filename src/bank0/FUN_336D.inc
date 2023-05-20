
SECTION "336D", ROM0[$336D]

; Sets some variables
FUN_336D:
	ld a,b
	ld [$DE26],a
	ld a,c
	ld [$DE27],a
	xor a
	ld [$DE28],a
	ret