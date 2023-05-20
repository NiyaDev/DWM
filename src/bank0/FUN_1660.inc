
SECTION "1660", ROM0[$1660]

; Copies a few variables and sets the rest to 0
FUN_1660:
	ld hl,unk_1660_3
	ld a,[unk_13EF_1]
	ld [hl+],a
	ld a,[unk_13EF_2]
	ld [hl+],a
	ld a,[unk_13EF_3]
	ld [hl],a
	jr .LAB_1671

.LAB_1671:
	xor a
	ld hl,unk_1660_6
	ld [hl+],a
	ld [hl+],a
	ld [hl+],a
	ld [hl+],a
	ld [hl],a
	ld [unk_start_27],a
	ld a,$07
	ld [unk_1660_1],a
	ld a,$1F
	ld [unk_1660_2],a
	
	ret