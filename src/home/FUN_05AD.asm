
SECTION "05AD", ROM0[$05AD]


FUN_05AD::
; if wUNK_START_17 == 0, return
  ld a,[wUNK_START_17]
  or a
  ret z

  call FUN_143C
  ret
