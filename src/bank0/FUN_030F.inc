
SECTION "030F", ROM0[$030F]

; 
FUN_030F:
	ld a,[unk_start_1]
	rst $00

;; TODO: These are all functions
dw .jump01,.jump02,.jump03
dw .jump04,.jump05,.jump06
dw .jump07,.jump08,.jump09
dw .jump10,.jump11,.jump12
dw .jump13

.jump01:
	ld hl,$1500
	rst $10
	ret

.jump02:
	ld hl,$0100
	rst $10
	ret

.jump03:
	ld hl,$5000
	rst $10
	ret

.jump04:
	ld hl,$0201
	rst $10
	ret

.jump05:
	ld hl,$5F00
	rst $10
	ret

.jump06:
	ld hl,$5F08
	rst $10
	ret

.jump07:
	ld hl,$1800
	rst $10
	ret

.jump08:
	ld hl,$550D
	rst $10
	ret

.jump09:
	ld hl,$5900
	rst $10
	ret

.jump10:
	ld hl,$5902
	rst $10
	ret

.jump11:
	ld hl,$5904
	rst $10
	ret

.jump12:
	ld hl,$5603
	rst $10
	ret

.jump13:
	ld hl,$5607
	rst $10
	ret