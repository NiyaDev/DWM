

SECTION "BANK8", ROMX[$4000], BANK[8]

db 8

dw sgb_commands
def jump_sgb_commands equ $0800
dw FUN_8_41E3
dw FUN_8_422C
def jump_8_447E equ $0803
dw FUN_8_447E ; Might be Border data
def jump_8_449E equ $0804
dw FUN_8_449E ; Might be Border data
dw FUN_8_44A5
dw FUN_8_54A5
dw FUN_8_64A5
dw FUN_8_68DD
dw FUN_8_78DD
