
SECTION "BANK8", ROMX[$4000], BANK[8]

db 8

; This bank seems to involve a lot of SGB sprites and functions

; `$4015 | Bank8`
;
; Sends commands to SGB
dw sgb_commands
def jump_sgb_commands equ $0800

; Probably Function
; TODO
dw $41E3
def jump_8_42E3 equ $0801

; `$422C | Bank:8`
;
; Copy data from one offset to a predetermined place.
dw FUN_8_422C
def jump_8_422C equ $0802

; Might be SGB Palette data
dw DATA_8_447E
def jump_8_447E equ $0803

; Might be SGB Attribute data
dw DATA_8_449E
def jump_8_449E equ $0804

; Probably Data
; TODO
dw DATA_8_44A5
def jump_8_44A5 equ $0805

; Probably Data
; TODO
dw $54A5
def jump_8_54A5 equ $0806

; Probably Data
; TODO
dw $64A5
def jump_8_64A5 equ $0807

; Probably Data
; TODO
dw $68DD
def jump_8_68DD equ $0808

; Probably Data
; TODO
dw $78DD
def jump_8_78DD equ $0809
