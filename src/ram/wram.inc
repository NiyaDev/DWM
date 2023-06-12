
section "wram", wram0[$C000]

empty_1:: ds $0740


; Both set to 0 in start
wUNK_START_18:: db ; $C740
wUNK_START_19:: db ; $C741


empty_2:: ds $0032


; SGB Command
wUNK_START_7:: db ; $C774


empty_3:: ds 2


; Appears to be a SGB Command in memory
wUNK_8_4015_1:: db ; $C777


empty_4:: ds $009F


wUNK_21_404F_1:: db ; $C817


empty_5:: ds $0003


; Set to $FF in start
wUNK_START_6:: db ; $C81B
doWait:: db ; $C81C
IsGBC:: db ; $C81D