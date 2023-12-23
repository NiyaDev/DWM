
section "hram", hram[$FF8A]

empty_h1:: ds 33

; 
hUNK_14E1_1:: db ; $FFAB
hUNK_14E1_4:: db ; $FFAC
hUNK_14E1_5:: db ; $FFAD


empty_h2:: db ; $FFAE


hUNK_14E1_3:: db ; $FFAF
hUNK_14E1_2:: db ; $FFB0
hUNK_14E1_7:: db ; $FFB1
hUNK_14E1_6:: db ; $FFB2
hUNK_14E1_9:: db ; $FFB3
hUNK_14E1_8:: db ; $FFB4
; `$FFB5` - ???
;
; Set to 7 in FUN_404F.
;
; Used for rWX in FUN_1227.
hUNK_21_404F_2:: db
; `$FFB6` - ???
;
; Set to $FF in FUN_404F.
;
; Used for rWY in FUN_1227.
hUNK_21_404F_3:: db
; `$FFB7` - ???[8]
;
; 8 bytes cleared $FFB7->$FFBE
;
; [0] Used for rSCX.
hUNK_140B:: db


empty_h3:: ds 3


; `$FFBB` - ???
;
; Set to 0 in FUN_404F.
;
; Used for rSCY in FUN_1227.
hUNK_21_404F_4:: db ; $FFBB


empty_h4:: ds 15


; `$FFCB` - ???
;
; Set to 0 in FUN_1417
hUNK_1417:: db


empty_h5:: ds 7
	
	
hUNK_START:: db ; $FFD3