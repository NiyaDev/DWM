
SECTION "13EF", ROM0[$13EF]

; 
FUN_13EF:
	ld hl,unk_13EF_1
	ld a,$D2
	ld [HL+],a
	ld a,$D2
	ld [hl+],a
	ld a,$E2
	ld [hl],a

	ld hl,unk_13EF_4
	ld a,[unk_13EF_1]
	ld [hl+],a
	ld a,[unk_13EF_2]
	ld [hl+],a
	ld a,[unk_13EF_3]
	ld [hl],a

	ret