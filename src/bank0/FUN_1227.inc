
SECTION "1227", ROM0[$1227]

; `$1227 | Bank:0`
;
; Reset interrupt flags and enable input interrupts.
;
; TODO rename set_interrupts ?
FUN_1227:
	ld b,a
	; Reset Interrupt flags
	xor a
	ldh [rIF],a
	; Enable input interrupts
	ld a,b
	ldh [rIE],a

	ret
