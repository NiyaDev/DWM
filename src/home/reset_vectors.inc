
SECTION "Reset Vectors", ROM0[$0000]

;; Use Jump table located at return address
RST00:
	pop hl
	add a
	add l
	ld l,a
	ld a,0
	adc h
	ld h,a
;; Jumps to function pointed to by HL
RST08:
	ld a,[hl+]
	ld h,[hl]
	ld l,a
	jp hl

;; Alternate version of RST08 that
;; just returns after getting pointer
ALT08:
	ld a,[hl+]
	ld h,[hl]
	ld l,a
	ret

; Grabs current SRAM bank, saves it to stack,
; then sets ROM bank to whats in h.
; NOTE: This one is used a lot.
RST10:
	ld a,[rRAMB_ex]
	push af
	ld a,h
	ld [rROMB0],a

; Manipulates a, then sets it as current SRAM bank.
RST18:
	swap a
	rra
	and $03
	ld [rRAMB],a

; Doubles L and uses it to offset $4001 before alling into RST28
RST20:
	add hl,hl
	ld h,0
	ld bc,$4001
	add hl,bc

; Calls RST08, then pops AF off stack and sets ROM bank 0 to A. Then swaps A.
RST28:
	call RST08
	pop af
	ld [rROMB0],a
	swap a

; Manipulates A and then sets SRAM bank to it. End.
RST30:
	rra
	and $03
	ld [rRAMB],a
	ret
db $FF

; Increments data at D + 1.
RST38:
	ld e,1
	ld a,[de]
	inc a
	ld [de],a
	ret
db $FF, $FF