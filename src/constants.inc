

; Set to 0 with others in init
; Checked if not 0 in FUN_036E
def unk_start_9 equ $C825

; 18 bytes filled ->$C839
def unk_21_4009_3 equ $C827

; Set to 0 with others in init
def unk_start_10 equ $C829
; Set to 0 with others in init
def unk_start_11 equ $C82A

def unk_21_4009_4_low equ $C83E
def unk_21_4009_4_high equ $C83F

; Checked if < $0F, and < $03
def unk_036E_1 equ $C842

; Loaded to test for jump
; Set to 0 in FUN_1660
def unk_start_27 equ $C850
; Set to $07
def unk_1660_1 equ $C851
; Set to $1F
def unk_1660_2 equ $C852
; Set to unk_13EF_1
def unk_1660_3 equ $C853
; Set to unk_13EF_2
def unk_1660_4 equ $C854
; Set to unk_13EF_3
def unk_1660_5 equ $C855
; Set to 0
def unk_1660_6 equ $C856
; Set to 0
def unk_1660_7 equ $C857
; Set to 0
def unk_1660_8 equ $C858
; Set to 0
def unk_1660_9 equ $C859

def unk_21_404F_8 equ $C863
def unk_21_404F_9 equ $C864
def unk_21_404F_6 equ $C865
def unk_21_404F_7 equ $C866

; Set to 0 with others in init
; Set to 0 in FUN_1660
def unk_start_8 equ $C86A

; Loaded for testing for func call
; Checked if 0 in FUN_036E
def unk_start_26 equ $C86C
def unk_21_404F_10 equ $C86D

; Set to copy of rLY
def unk_036E_2 equ $C886

; Four bytes set to 0
; lowest used in FUN_030F
def unk_start_1 equ $C88A
def unk_start_1_1 equ $C88B
def unk_start_1_2 equ $C88C
def unk_start_1_3 equ $C88D
; Set to 0 with second group in init, loaded to test for jump
def unk_start_15 equ $C88E
; Set to 0 with second group in init
def unk_start_16 equ $C88F

def unk_21_404F_5 equ $C892

; Calculated and then saved as big endian
def unk_12D0_1 equ $C899
def unk_12D0_2 equ $C89A
; Set to $D2 and copied to unk_13EF_4
def unk_13EF_1 equ $C89B
; Set to $D2 and copied to unk_13EF_5
def unk_13EF_2 equ $C89C
; Set to $E2 and copied to unk_13EF_6
def unk_13EF_3 equ $C89D
; Set to $D2
def unk_13EF_4 equ $C89E
; Set to $D2
def unk_13EF_5 equ $C89F
; Set to $E2
def unk_13EF_6 equ $C8A0
; Bit 7 reset along with rLCDC (OFF)
; Set to the same as rLCDC in FUN_10E5
def unk_11E7_1 equ $C8A1
; Set to 0 with second group in init
; Checked if bit 0 is 1 and is reset at end in FUN_036E
def unk_start_20 equ $C8A2
; Set to 0 with second group in init
def unk_start_17 equ $C8A3
; Set to 0 with second group in init
; Incremented in FUN_036E
def unk_start_21_low equ $C8A4
def unk_start_21_hig equ $C8A5

; Four bytes set to 0 with second group in init
def unk_start_25 equ $C8B1

; Set to $FFFF at init
def unk_start_4_low equ $C8B7
def unk_start_4_hig equ $C8B8
; Set to 0 with second group in init
; Checked if 0, not 0, is incremented, and set to 0 in FUN_036E
def unk_start_23 equ $C8B9

; Set to 0
def unk_start_5 equ $C8C7
; Set to 0 with others in init
def unk_start_12 equ $C8C8
; Set to 0 with others in init
def unk_start_13 equ $C8C9

; 18 bytes filled ->$C8DA
def unk_21_4009_5 equ $C8D2

; 8 bytes filled ->$C8E2
def unk_21_4009_2 equ $C8DA

; Set to 4 at init
def unk_start_2 equ $C8EE



; Set to 0 with second group in init
; Causes lock up if not 0, inc, then saved in FUN_14CF
def unk_start_24 equ $DA78

def unk_21_4009_1_low equ $DA7B
def unk_21_4009_1_high equ $DA7C

; Copy of 
def unk_3331_1 equ $DE1D

; Set to input b
; Only known call is 0
def unk_336D_1 equ $DE26
; Set to input c
; Only known call is 0
def unk_336D_2 equ $DE27
; Set to 0
def unk_336D_3 equ $DE28
; Set to 0
def unk_3331_3 equ $DE29

; A 12 locations starting from here set to $FF
def unk_3331_2 equ $DD80

; Set to 0 with others in init
def unk_start_14 equ $DF0E



;; HIRAM

def unk_14E1_1 equ $FFAB
def unk_14E1_4 equ $FFAC
def unk_14E1_5 equ $FFAD

def unk_14E1_3 equ $FFAF

def unk_14E1_2 equ $FFB0
def unk_14E1_7 equ $FFB1
def unk_14E1_6 equ $FFB2
def unk_14E1_9 equ $FFB3
def unk_14E1_8 equ $FFB4
def unk_21_404F_2 equ $FFB5
def unk_21_404F_3 equ $FFB6
def unk_140B equ $FFB7

def unk_21_404F_4 equ $FFBB

; Set to 0
def unk_high_1417 equ $CB
;
def unk_high_start_1 equ $D3