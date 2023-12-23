
SECTION "122F", ROM0[$122F]

; `$122F | Bank:0`
;
; Copies values from HRAM into I/O.
FUN_122F:
	ldh a,[hUNK_140B]
	ldh [rSCX],a
	ldh a,[hUNK_21_404F_4]
	ldh [rSCY],a

	ldh a,[hUNK_21_404F_2]
	ldh [rWX],a
	ldh a,[hUNK_21_404F_3]
	ldh [rWY],a

	ret