
SECTION "Interrupts", ROM0[$0040]

; 
vblanK:
	di
	jp FUN_036E
db $01,$1a,$18,$b8

;
stat:
	jp FUN_2EEA
db $FA,$90,$CD,$18,$B0

;
timer:
	reti
db $FA,$02,$C0,$B7,$C9,$FF,$FF

;
serial:
	jp FUN_2EDD
db $D9,$FF,$FF,$FF,$FF

;
joypad:
	reti
db $F3,$F5,$C5,$D5,$E5,$21,$40,$FF
db $CB,$86,$CB,$8E,$21,$C2,$DD,$34
db $FA,$84,$C9,$B7,$20,$34,$3C,$EA
db $84,$C9,$CD,$90,$FF,$CD,$F7