
SECTION "336D", ROM0[$336D]

; `$336D | Bank:0`
;
; Sets some variables.
FUN_336D:
	ld a,b
	ld [wUNK_336D_1],a
	ld a,c
	ld [wUNK_336D_2],a
	xor a
	ld [wUNK_336D_3],a
	ret