
SECTION "Interrupts", ROM0[$0040]

; Disable interrupts and jump to FUN_046E
vblanK:
	di
	jp FUN_036E
db $01,$1a,$18,$b8

; Jump to FUN_2EEA
stat:
	jp FUN_2EEA
db $FA,$90,$CD,$18,$B0

; Return and disable interrupts
timer:
	reti
db $FA,$02,$C0,$B7,$C9,$FF,$FF

; Jump to FUN_3EDD
serial:
	jp FUN_2EDD
db $D9,$FF,$FF,$FF,$FF

; Return and disable interrupts
joypad:
	reti
db $F3,$F5,$C5,$D5,$E5,$21,$40,$FF
db $CB,$86,$CB,$8E,$21,$C2,$DD,$34
db $FA,$84,$C9,$B7,$20,$34,$3C,$EA
db $84,$C9,$CD,$90,$FF,$CD,$F7
