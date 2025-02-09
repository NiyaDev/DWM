
SECTION "13EF", ROM0[$13EF]

; `$13EF | Bank:0`
;
; Stores $E2D2D2 at two places right after one another.
FUN_13EF:
	; Stores $E2D2D2 at wUNK_13EF_1
	ld hl,wUNK_13EF_1
	ld a,$D2
	ld [HL+],a
	ld a,$D2
	ld [hl+],a
	ld a,$E2
	ld [hl],a
	
	; And at wUNK_13EF_1
	ld hl,wUNK_13EF_2
	ld a,[wUNK_13EF_1]
	ld [hl+],a
	ld a,[wUNK_13EF_1+1]
	ld [hl+],a
	ld a,[wUNK_13EF_1+2]
	ld [hl],a

	ret