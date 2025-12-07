
; rst vectors

; Use jumptable starting at return address offset A
section "rst0", rom0[$0000]
  pop hl
  add a
  add l
  ld l,a
  ld a,0
  adc h
  ld h,a
; Jumps to function at [HL]
section "rst8", rom0[$0008]
rst08:
  ld a,[hl+]
  ld h,[hl]
  ld l,a
  jp hl

; Loads [HL] into HL and returns
alt8:
  ld a,[hl+]
  ld h,[hl]
  ld l,a
  ret

; Changes to BANK H, then jumps to $4001 + (L*2)
section "rst10", rom0[$0010]
  ld a,[rRAMB]
	push af

; Set Bank
	ld a,h
	ld [rROMB0+$100],a

; For banks 0->20 sets RAM bank to 0
; For banks 20-95 sets RAM bank to 1
	swap a
	rra
	and $03
	ld [rRAMB+$100],a

; Doubles L and uses it to offset $4001
	add hl,hl
	ld h,0
	ld bc,$4001
	add hl,bc
	call rst08

; Resets ROM bank
	pop af
	ld [rROMB0+$100],a
	swap a

; and RAM bank
	rra
	and $03
	ld [rRAMB+$100],a
	ret
ds 1, $FF


; Increments data at DE + 1
section "rst38", rom0[$0038]
  ld e,1
	ld a,[de]
	inc a
	ld [de],a
	ret
ds 2, $FF



; Hardware Interrupts

section "vblank", rom0[$0040]
  di
  jp FUN_036E ; TODO
db $01,$1A,$18,$B8

section "stat", rom0[$0048]
  jp FUN_2EEA ; TODO
db $FA,$90,$CD,$18,$B0

section "timer", rom0[$0050]
  reti
db $FA,$02,$C0,$B7,$C9,$FF,$FF

section "serial", rom0[$0058]
  jp FUN_2EDD ; TODO
db $D9,$FF,$FF,$FF,$FF

section "joypad", rom0[$0060]
  reti
db $F3,$F5,$C5,$D5,$E5,$21,$40,$FF
db $CB,$86,$CB,$8E,$21,$C2,$DD,$34
db $FA,$84,$C9,$B7,$20,$34,$3C,$EA
db $84,$C9,$CD,$90,$FF,$CD,$F7


