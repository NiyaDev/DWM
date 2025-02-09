
SECTION "030F", ROM0[$030F]

; `$030F | Bank:0`
;
; TODO Gotta name this
;
; Jump table using wUNK_START_1:
;
; ` 0: Bank 21 / $4009`
; ` 1: Bank  1 / $401D`
; ` 2: Bank 80 / $5DC9`
;
; ` 3: Bank  2 / $4E9F`
; ` 4: Bank 95 / $4017`
; ` 5: Bank 95 / $5BB7`
;
; ` 6: Bank 24 / $400B`
; ` 7: Bank 85 / $4936`
; ` 8: Bank 89 / $4013`
;
; ` 9: Bank 89 / $458F`
; `10: Bank 89 / $4824`
; `11: Bank 86 / $4916`
;
; `12: Bank 86 / $403F`
FUN_030F:
	ld a,[wUNK_START_1]
	rst $00

dw .jump00,.jump01,.jump02
dw .jump03,.jump04,.jump05
dw .jump06,.jump07,.jump08
dw .jump09,.jump10,.jump11
dw .jump12

.jump00:
	ld hl,jump_21_4009
	rst $10
	ret

.jump01:
	ld hl,jump_1_401D
	rst $10
	ret

.jump02:
	ld hl,jump_80_5DC9
	rst $10
	ret

.jump03:
	ld hl,jump_2_4E9F
	rst $10
	ret

.jump04:
	ld hl,jump_95_4017
	rst $10
	ret

.jump05:
	ld hl,jump_95_5BB7
	rst $10
	ret

.jump06:
	ld hl,jump_24_400B
	rst $10
	ret

.jump07:
	ld hl,jump_85_4936
	rst $10
	ret

.jump08:
	ld hl,jump_89_4013
	rst $10
	ret

.jump09:
	ld hl,jump_89_458F
	rst $10
	ret

.jump10:
	ld hl,jump_89_4824
	rst $10
	ret

.jump11:
	ld hl,jump_86_4916
	rst $10
	ret

.jump12:
	ld hl,jump_86_403F
	rst $10
	ret