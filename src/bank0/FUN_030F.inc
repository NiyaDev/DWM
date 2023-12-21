
SECTION "030F", ROM0[$030F]

; `$030F | Bank:0`
;
; TODO Gotta name this
;
; Jump table:
;
; ` 1: Bank 21 / $4009`
; ` 2: Bank  1 / $401D`
; ` 3: Bank 80 / $5DC9`
;
; ` 4: Bank  2 / $4E9F`
; ` 5: Bank 95 / $4017`
; ` 6: Bank 95 / $5BB7`
;
; ` 7: Bank 24 / $400B`
; ` 8: Bank 85 / $4936`
; ` 9: Bank 89 / $4013`
;
; `10: Bank 89 / $458F`
; `11: Bank 89 / $4824`
; `12: Bank 86 / $4916`
;
; `13: Bank 86 / $403F`
;
FUN_030F:
	ld a,[wUNK_START_1]
	rst $00

dw .jump01,.jump02,.jump03
dw .jump04,.jump05,.jump06
dw .jump07,.jump08,.jump09
dw .jump10,.jump11,.jump12
dw .jump13

.jump01:
	ld hl,jump_21_4009
	rst $10
	ret

.jump02:
	ld hl,jump_1_401D
	rst $10
	ret

.jump03:
	ld hl,jump_80_5DC9
	rst $10
	ret

.jump04:
	ld hl,jump_2_4E9F
	rst $10
	ret

.jump05:
	ld hl,jump_95_4017
	rst $10
	ret

.jump06:
	ld hl,jump_95_5BB7
	rst $10
	ret

.jump07:
	ld hl,jump_24_400B
	rst $10
	ret

.jump08:
	ld hl,jump_85_4936
	rst $10
	ret

.jump09:
	ld hl,jump_89_4013
	rst $10
	ret

.jump10:
	ld hl,jump_89_458F
	rst $10
	ret

.jump11:
	ld hl,jump_89_4824
	rst $10
	ret

.jump12:
	ld hl,jump_86_4916
	rst $10
	ret

.jump13:
	ld hl,jump_86_403F
	rst $10
	ret