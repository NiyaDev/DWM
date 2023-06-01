
SECTION "336D", ROM0[$336D]

; Sets some variables
FUN_336D:
	ld a,b
	ld [unk_336D_1],a
	ld a,c
	ld [unk_336D_2],a
	xor a
	ld [unk_336D_3],a
	ret