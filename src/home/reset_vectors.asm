
SECTION "Reset Vectors", ROM0[$0000]

; Use Jump table located at return address
; with offset in A
RST00:
	pop hl
	add a
	add l
	ld l,a
	ld a,0
	adc h
	ld h,a
; Jumps to function pointed to by HL
RST08:
	ld a,[hl+]
	ld h,[hl]
	ld l,a
	jp hl

; Alternate version of RST08 that
; just returns after getting pointer
ALT08:
	ld a,[hl+]
	ld h,[hl]
	ld l,a
	ret

; Changes ROM bank to H, then jumps to
; the pointer located at $4001 + L*2
RST10:
	ld a,[rRAMB]
	push af
	
	ld a,h
	ld [rROMB0+$100],a

	swap a
	rra
	and $03
	ld [rRAMB+$100],a

; Doubles L and uses it to offset $4001
	add hl,hl
	ld h,0
	ld bc,$4001
	add hl,bc
	call RST08

	pop af
	ld [rROMB0+$100],a
	swap a

	rra
	and $03
	ld [rRAMB+$100],a
	ret
db $FF

; Increments data at DE + 1.
RST38:
	ld e,1
	ld a,[de]
	inc a
	ld [de],a
	ret
db $FF, $FF
