
SECTION "143C", ROM0[$143C]


FUN_143C::
; Compare two variables
  ld a,[wUNK_START_18]
  ld e,a
  ld a,[wUNK_START_19]
  ld d,a
  ld a,d
; return if both are zero
  or e
  jr nz,.LAB_1449
  ret


.LAB_1449:
  ld a,[wC743]
  ld b,a
  ld hl,wC744

; return if wC742 equals $FF
  ld a,[wC742]
  cp $FF
  ret z

; if wC742 equals 0
  or a
  jr nz,.LAB_148F

; c = wUNK_START_18 & $E0
  ld a,e
  and $E0
  ld c,a
.LAB_145D:
  ld a,[hl+]
  ld [de],a
  inc e
  ld a,e
  and $1F
  or c
  ld e,a

  dec b
  jr nz,.LAB_145D

  ld a,[IsGBC]
  or a
  jr z,.LAB_14C7

  ld a,1
  ldh [rVBK],a

  ld a,[wUNK_START_18]
  ld e,a
  ld a,[wUNK_START_19]
  ld d,a
  ld a,[wC743]
  ld b,a
.LAB_147E:
  ld a,[hl+]
  ld [de],a
  inc e
  ld a,e
  and $1F
  or c
  ld e,a
  dec b
  jr nz,.LAB_147E

  ld a,0
  ldh [rVBK],a
  jr .LAB_14C7

.LAB_148F:
  ld a,[hl+]
  ld [de],a
  ld a,e
  add $20
  ld e,a
  ld a,d
  adc 0
  res 2,a
  ld d,a
  dec b
  jr nz,.LAB_148F

  ld a,[IsGBC]
  or a
  jr z,.LAB_14C7

  ld a,1
  ldh [rVBK],a
  ld a,[wUNK_START_18]
  ld e,a
  ld a,[wUNK_START_19]
  ld d,a
  ld a,[wC743]
  ld b,a

.LAB_14B4:
  ld a,[hl+]
  ld [de],a
  ld a,e
  add $20
  ld e,a
  ld a,d
  adc 0
  res 2,a
  ld d,a
  dec b
  jr nz,.LAB_14B4

  ld a,0
  ldh [rVBK],a

.LAB_14C7:
  xor a
  ld [wUNK_START_18],a
  ld [wUNK_START_19],a
  ret

