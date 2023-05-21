
; Set to 0 with second group in init
def unk_start_18 equ $C740
; Set to 0 with second group in init
def unk_start_19 equ $C741

; Set to various numbers in the weird section
; Set to $0B or $0A in FUN_1024
; Used in FUN_8_4015
; SGB command offset
def unk_start_7 equ $C774

; ANDed with 7 and leaves function if result is 0
def unk_8_4015_1 equ $C777

; Set to $FF at init
def unk_start_6 equ $C81B
; Set to 1 at init in multiple places
; If 0, will skip waits
def unk_wait equ $C81C
def IsGBC equ $C81D

; Set to 0 with others in init
; Checked if not 0 in FUN_036E
def unk_start_9 equ $C825

; Set to 0 with others in init
def unk_start_10 equ $C829
; Set to 0 with others in init
def unk_start_11 equ $C82A

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
; Set to 0 with others in init
; Set to 0 in FUN_1660
def unk_start_8 equ $C86A

; Loaded for testing for func call
; Checked if 0 in FUN_036E
def unk_start_26 equ $C86C

; Set to copy of rLY
def unk_036E_2 equ $C886

; Four bytes set to 0
; lowest used in FUN_030F
def unk_start_1 equ $C88A
; Set to 0 with second group in init, loaded to test for jump
def unk_start_15 equ $C88E
; Set to 0 with second group in init
def unk_start_16 equ $C88F

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

; Set to 4 at init
def unk_start_2 equ $C8EE



; Set to 0 with second group in init
def unk_start_24 equ $DA78

; Set to 0
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

; Set to 0
def unk_high_1417 equ $CB
;
def unk_high_start_1 equ $D3