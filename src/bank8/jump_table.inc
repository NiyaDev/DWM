

SECTION "BANK8", ROMX[$4000], BANK[8]

db 8

dw sgb_commands
def jump_sgb_commands equ $0800

dw $41E3
def jump_8_42E3 equ $0801

dw $422C
def jump_8_422C equ $0802

dw DATA_8_447E ; Might be SGB Palette data
def jump_8_447E equ $0803

dw DATA_8_449E ; Might be SGB Attribute data
def jump_8_449E equ $0804

dw DATA_8_44A5
def jump_8_44A5 equ $0805

dw $54A5
dw $64A5
dw $68DD
dw $78DD


SECTION "DATA_8_447E", ROMX[$447E], BANK[8]

;; Seems to be sgb palette data
DATA_8_447E: incbin "src/testing/DATA_8_447E.bin"
DATA_8_449E: incbin "src/testing/DATA_8_449E.bin"
DATA_8_44A5: incbin "src/testing/DATA_8_44A5.bin"