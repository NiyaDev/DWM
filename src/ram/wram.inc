
section "wram", wram0[$C000]

empty_1:: ds $0740


; Both set to 0 in start
wUNK_START_18:: db ; $C740
wUNK_START_19:: db ; $C741


empty_2:: ds $0032


; `$C774` - byte
;
; SGB Command
wUNK_START_7:: db


empty_3:: ds 2


; Appears to be a SGB Command in memory
wUNK_8_4015_1:: db ; $C777

ds $0060

; `$C7D7` - ??[8]
;
; Copied to using FUN_8_426A in FUN_8_422C.
wUNK_8_422C_5:: ds 8
; `$C7DF` - ??[8]
;
; Copied to using FUN_8_426A in FUN_8_422C.
wUNK_8_422C_6:: ds 8
; `$C7E7` - ??[8]
;
; Copied to using FUN_8_426A in FUN_8_422C.
wUNK_8_422C_7:: ds 8
; `$C7EF` - ??[8]
;
; Copied to using FUN_8_426A in FUN_8_422C.
wUNK_8_422C_8:: ds 8


ds $001F


; `$C817` - ???
;
; Might be a word
wUNK_21_404F_1:: db


empty_5:: ds $0003


; `$C818` - ???
;
; Set to $FF in start only when in SGB mode.
wUNK_START_6:: db
; `$C81C` - bool
;
; If true, removes loops.
;
; Usually used in conjunction with SGB commands.
doWait:: db
; `$C81D` - bool
;
; True if GBC or equivalent
IsGBC:: db
; `$C81E` - bool
;
; 
wUNK_95_441C_1:: db


empty_6:: ds $0006


; `$C825` - ???
;
; Set to 0 at the start of main loop.
;
; Checked if not 0 in FUN_036E.
wUNK_START_9:: db


empty_7:: db ; $C826


; 18 bytes filled ->$C838
;; TODO
wUNK_21_4009_3:: db ; $C827 


empty_8:: db ; $C828


; `$C829` - ???
;
; Set to 0 with others in init
wUNK_START_10:: db
; `$C82A` - ???
;
; Set to 0 with others in init
wUNK_START_11:: db ; $C82A


empty_9:: ds 19


wUNK_21_4009_4:: ds 2 ; $C83E


empty_10:: ds 2


; Checked if < $0F, and < $03
wUNK_036E_1:: db ; $C842


empty_11:: ds 13


; `$C850` - ???
;
; Loaded to test for jump
; Set to 0 in FUN_1660
wUNK_START_27:: db
; `$C851` - ???
;
; Set to $07 in FUN_1660.
wUNK_1660_1:: db
; `$C852` - ???
;
; Set to $1F in FUN_1660.
wUNK_1660_2:: db
; `$C853` - ???[3]
;
; [0] Set to unk_13EF_1[0].
;
; [1] Set to unk_13EF_1[0].
;
; [2] Set to unk_13EF_1[0].
wUNK_1660_3:: db
; `$C856` - ???[5]
;
; [0->4] Set to 0.
wUNK_1660_6:: db
	; Set to 0
wUNK_1660_7:: db ; $C857
	; Set to 0
wUNK_1660_8:: db ; $C858
	; Set to 0
wUNK_1660_9:: db ; $C859


ds 1


; $C85B->$C862 seem to be pointers

; `$C85B` - ptr offset
;
; (x*8 + $447E)
;
; Used in FUN_8_422C
wUNK_8_422C_1:: dw
; `$C85E` - ptr offset
;
; (x*8 + $447E)
;
; Used in FUN_8_422C
wUNK_8_422C_2:: dw
; `$C860` - ptr offset
;
; (x*8 + $447E)
;
; Used in FUN_8_422C
wUNK_8_422C_3:: dw
; `$C862` - ptr offset
;
; (x*8 + $447E)
;
; Used in FUN_8_422C
wUNK_8_422C_4:: dw
; `$C863` - ???
;
; Set to 0 in FUN_404F.
wUNK_21_404F_8:: db
; `$C864` - ???
;
; Set to 0 in FUN_404F.
wUNK_21_404F_9:: db
; `$C865` - ???
;
; Set to 0 in FUN_404F.
wUNK_21_404F_6:: db
; `$C866` - ???
;
; Set to 0 in FUN_404F.
wUNK_21_404F_7:: db


ds 5


; `$C86A` - ???
;
; Set to 0 at the start of main loop.
;
; Set to 0 in FUN_1660.
wUNK_START_8:: db


db ; $C86B


; `$C86C` - ???
;
; Loaded for testing for func call.
;
; Checked if 0 in FUN_036E and FUN_11CB.
;
; Set to 0 in FUN_404F.
wUNK_START_26:: db
; `$C86D` - ???
;
; Set to 0 in FUN_404F.
wUNK_21_404F_10:: db


empty_15:: ds 24


; Set to copy of rLY
wUNK_036E_2:: db ; $C886


empty_16:: ds 3


; `$C88A` - byte
;
; Used for jump table in FUN_030F. That clamps it to 0->12, otherwise it would overflow.
wUNK_START_1:: db
; `$C88B` - byte
;
; Used for jump table in FUN_21_4009. That clamps it to 0->3
wUNK_START_1_2:: db
; `$C88C` - ???
;
; Used for jumptable at FUN_95_441C
wUNK_START_1_3:: db
; `$C88D` - ???
;
; Used for jumptable at $442E within FUN_95_441C
wUNK_START_1_4:: db
; `$C88E` - ???
;
; Set to 0 with second group in init, loaded to test for jump
wUNK_START_15:: db
; `$C88F` - ???
;
; Set to 0 with second group in init
wUNK_START_16:: db


empty_18:: ds 2


; `$C892` - ???
;
; Set to 0 in FUN_404F
wUNK_21_404F_5:: db


empty_19:: ds 6


; Calculated and then saved as big endian
wUNK_12D0_1:: ds 2 ; $C899
; `$C89B` - ???
;
; [0] to $D2.
; Copied into wUNK_1660_3[0->2]
;
; [1] to $D2.
;
; [2] to $E2.
wUNK_13EF_1:: ds 3
; `$C89B` - ???
;
; [0] to $D2
;
; [1] to $D2
;
; [2] to $E2
wUNK_13EF_2:: ds 3 ; $C89E
; `$C8A1` - byte
;
; Contains LCD control flags and is copied to rLCDC.
lcdcFlags:: db
; Set to 0 with second group in init
; Checked if bit 0 is 1 and is reset at end in FUN_036E
wUNK_START_20:: db ; $C8A2
; Set to 0 with second group in init
wUNK_START_17:: db ; $C8A3
; `$C8A4` - ???(Word?)
;
; Set to 0 with second group in init.
;
; Incremented in FUN_036E.
wUNK_START_21:: ds 2 ; $C8A4


empty_20:: ds 11


; Four bytes set to 0 with second group in init
wUNK_START_25:: ds 4 ; $C8B1


empty_21:: ds 2


; `$C8B7` - ???
;
; Set to $FFFF at init
wUNK_START_4:: ds 2 ; $C8B7
; Set to 0 with second group in init
; Checked if 0, not 0, is incremented, and set to 0 in FUN_036E
wUNK_START_23:: db ; $C8B9


empty_22:: ds 13


; `$C8C7` - ???
;
; Set to 0 in start
wUNK_START_5:: db
; `$C8C8` - ???
;
; Set to 0 with others in init
wUNK_START_12:: db ; $C8C8
; `$C8C9` - ???
;
; Set to 0 with others in init
wUNK_START_13:: db ; $C8C9


empty_23:: ds 8


; 8 bytes filled ->$C8D9
wUNK_21_4009_5:: ds 8 ; $C8D2
; 8 bytes filled ->$C8E1
wUNK_21_4009_2:: ds 8 ; $C8DA


empty_24:: ds 12


; `$C8EE` - ???
;
; Set to 4 at init
wUNK_START_2:: db


empty_25:: ds 4489
; `$DA78` - ???
;
; WRAM0 MODE
;
; Set to 0 with second group in init.
;
; Causes lock up if not 0, inc, then saved in FUN_14CF
wUNK_START_24:: db


empty_26:: ds 2


; $DA7B - fn ptr
;
; Set to the return address
wUNK_21_4009_1:: ds 2 ; $DA7B


empty_27:: ds 771


wUNK_3331_2:: db ; $DD80


empty_28:: ds 156


; Copy of 
wUNK_3331_1:: db ; $DE1D


empty_29:: ds 8


; Set to input b
; Only known call is 0
wUNK_336D_1:: db ; $DE26
; Set to input c
; Only known call is 0
wUNK_336D_2:: db ; $DE27
; Set to 0
wUNK_336D_3:: db ; $DE28
; Set to 0
wUNK_3331_3:: db ; $DE29


empty_30:: ds 228


; `$DF0E` - ???
;
; Set to 0 with others in init
wUNK_START_14:: db ; $DF0E