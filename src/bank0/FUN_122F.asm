
SECTION "122F", ROM0[$122F]

copy_scvi::
; $FFB7 into View X position
; $FFBB into View Y position
; $FFB5 into Window X position
; $FFB6 into Window Y position

	ldh a,[hSCX]
	ldh [rSCX],a
	ldh a,[hSCY]
	ldh [rSCY],a

	ldh a,[hWX]
	ldh [rWX],a
	ldh a,[hWY]
	ldh [rWY],a

	ret
