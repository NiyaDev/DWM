
SECTION "1660", ROM0[$1660]

; `$1660 | Bank:0`
;
; Copies a few variables and sets the rest to 0.
FUN_1660:
	; Copy wUNK_13EF_1[0] into wUNK_1660_3[0->2]
	ld hl,wUNK_1660_3
	ld a,[wUNK_13EF_1]
	ld [hl+],a
	ld a,[wUNK_13EF_1+1]
	ld [hl+],a
	ld a,[wUNK_13EF_1+2]
	ld [hl],a
	jr .LAB_1671

.LAB_1671:
	; Clear wUNK_1660_6[0->4] and wUNK_START_27
	xor a
	ld hl,wUNK_1660_6
	ld [hl+],a
	ld [hl+],a
	ld [hl+],a
	ld [hl+],a
	ld [hl],a
	ld [wUNK_START_27],a

	; Values set.
	ld a,$07
	ld [wUNK_1660_1],a
	ld a,$1F
	ld [wUNK_1660_2],a
	
	ret