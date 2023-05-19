
; Set to 0 with second group in init
def unk_start_18 equ $C740
; Set to 0 with second group in init
def unk_start_19 equ $C741

; Set to various numbers in the weird section
def unk_start_7 equ $C774

; Set to $FF at init
def unk_start_6 equ $C81B
; Set to 1 at init in multiple places
def unk_start_3 equ $C81C
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
def unk_start_27 equ $C850

; Set to 0 with others in init
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

; Set to 0 with others in init
def unk_start_14 equ $DF0E



;; HIRAM

def unk_high_start_1 equ $D3