
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

; these values are copied to rSCX, rSCY, and rWY during V-blank
hWX:: db  ; $FFB5
hWY:: db  ; $FFB6
hSCX:: db ; $FFB7
ds 3
hSCY:: db ; $FFBB


empty_h4:: ds 15


; `$FFCB` - ???
;
; Set to 0 in FUN_1417
hUNK_1417:: db


empty_h5:: ds 7
	
	
hUNK_START:: db ; $FFD3
