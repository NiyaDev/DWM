

SECTION "BANK8", ROMX[$4000], BANK[8]

db 8

dw sgb_commands
def jump_sgb_commands equ $0800
dw $41E3
def jump_8_422C equ $0801
dw $422C
dw FUN_8_447E ; Might be Border data
def jump_8_447E equ $0803
dw FUN_8_449E ; Might be Border data
def jump_8_449E equ $0804
dw $44A5
dw $54A5
dw $64A5
dw $68DD
dw $78DD
