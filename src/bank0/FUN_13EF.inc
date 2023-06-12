
SECTION "13EF", ROM0[$13EF]

; 
FUN_13EF:
	ld hl,wUNK_13EF_1
	ld a,$D2
	ld [HL+],a
	ld a,$D2
	ld [hl+],a
	ld a,$E2
	ld [hl],a

	ld hl,wUNK_13EF_2
	ld a,[wUNK_13EF_1]
	ld [hl+],a
	ld a,[wUNK_13EF_1+1]
	ld [hl+],a
	ld a,[wUNK_13EF_1+2]
	ld [hl],a

	ret