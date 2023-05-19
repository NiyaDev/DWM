
include "src/includes/hardware.inc"
include "src/constants.inc"
include "src/todo.inc"

include "src/home/reset_vectors.inc"
include "src/home/interrupts.inc"
include "src/home/copy_dma.inc"
db $13,$cd,$90,$12,$cd,$00,$40,$cd,$ba,$17,$af,$ea,$84,$c9,$e1,$d1,$c1,$f1,$d9,$cd,$c2,$00,$af,$e0,$0f,$fa,$99,$c9,$e0,$ff,$fb,$cd,$ed,$04,$e1,$d1,$c1,$f1,$cd,$a7,$04,$d9,$21,$91,$c9,$2a,$e0,$42,$2a,$e0,$43,$2a,$e0,$4a,$2a,$e0,$4b,$2a,$e0,$47,$2a,$e0,$48,$2a,$e0,$49,$7e,$e0,$45,$fa,$c1,$dd,$ea,$c0,$dd,$fa,$90,$c9,$e0,$40,$fa,$c7,$dd,$b7,$c8,$c3,$14,$12,$ff,$ff,$ff,$ff,$ff,$ff,$ff,$ff,$ff,$ff,$ff,$ff,$ff,$ff,$ff,$ff


SECTION "Entry", ROM0[$0100]
EntryPoint:
	nop
	jp  Start


SECTION "Header", ROM0[$0104]
ds $150 - @, 0 ; Make room for the header


SECTION "Start", ROM0[$0150]
Start:
	; Checks if the device is a GBC and sets IsGBC to true if so.
	cp BOOTUP_A_CGB
	ld a,0
	jr nz,.not_color
	inc a
.not_color:
	ld [IsGBC],a

.LAB_015A:
	; Set stack
	ld sp,$DFFF

	; TODO: Explore
	call int_off
	call clear_memory
	call copy_dma

	; Clear first $1C00 of VRAM
	ld hl,_VRAM
	ld bc,$1C00
	xor a
	call mem_clear

	; Set $C88A->$C88D to 0
	ld hl,unk_start_1
	xor a
	ld [hl+],a
	ld [hl+],a
	ld [hl+],a
	ld [hl],a

	ld a,4
	ld [unk_start_2],a
	ld a,0
	ld [unk_start_1],a
	
	; Setting SRAM bank to 0 and enabling writing
	ld a,1
	ld [rBANKSEL],a
	ld a,0
	ld [rRAMB],a
	ld a,0
	ld [rBANKSEL],a
	ld a,0
	ld [rRAMB],a
	ld a,$0A
	ld [rRAMG],a

	; Setting ROM and SRAM banks to 1 and 0
	ld a,1
	ld [rROMB0],a
	ld a,0
	ld [rRAMB],a

	; Setting some variables
	ld a,1
	ld [unk_start_3],a
	ld a,$FF
	ld [unk_start_4_low],a
	ld [unk_start_4_hig],a
	
	; TODO: Explore
	call FUN_3331

	xor a
	ld [unk_start_5],a

	; If IsGBC == false, skip
	ld a,[IsGBC]
	or a
	jr z,.LAB_01C6

	; Clearing IO
	xor a
	ldh [rVBK],a
	ldh [rSVBK],a
	ldh [rRP],a

.LAB_01C6:
	; TODO: Explore
	; If returns 1, go through weird thing
	call FUN_1024
	jr c,.LAB_01D2

	xor a
	ld [unk_start_3],a
	jp .LAB_028B


.LAB_01D2:
	ld bc,$000C
	call FUN_10CF

	ld a,$14
	ld [unk_start_7],a
	ld hl,$0800
	rst $10
	call FUN_1013

	ld a,2
	ld [unk_start_7],a
	ld hl,$0800
	rst $10
	call FUN_1013

	ld a,3
	ld [unk_start_7],a
	ld hl,$0800
	rst $10
	call FUN_1013

	ld a,4
	ld [unk_start_7],a
	ld hl,$0800
	rst $10
	call FUN_1013

	ld a,5
	ld [unk_start_7],a
	ld hl,$0800
	rst $10
	call FUN_1013

	ld a,6
	ld [unk_start_7],a
	ld hl,$0800
	rst $10
	call FUN_1013

	ld a,7
	ld [unk_start_7],a
	ld hl,$0800
	rst $10
	call FUN_1013

	ld a,8
	ld [unk_start_7],a
	ld hl,$0800
	rst $10
	call FUN_1013

	ld a,9
	ld [unk_start_7],a
	ld hl,$0800
	rst $10
	call FUN_1013

	ld a,$0C
	ld de,$0803
	ld bc,$0800
	call FUN_113E
	call FUN_1013

	ld a,$0D
	ld de,$0804
	call FUN_10E5
	call FUN_1013

	ld a,$12
	ld [unk_start_7],a
	ld hl,$0800
	rst $10
	call FUN_1013

	ld a,$0A
	ld [unk_start_7],a
	ld hl,$0800
	rst $10
	call FUN_1013

	ld a,$13
	ld [unk_start_7],a
	ld hl,$0800
	rst $10
	call FUN_1013

	ld a,1
	ld [unk_start_3],a
	ld a,$FF
	ld [unk_start_6],a

.LAB_028B:
	call FUN_12A5
	call FUN_1417
	call FUN_13EF
	call FUN_140B
	call FUN_1660

	xor a
	ld [unk_start_8],a
	ld [unk_start_9],a
	ld [unk_start_10],a
	ld [unk_start_11],a
	ld [unk_start_12],a
	ld [unk_start_13],a
	ld [unk_start_14],a
	call FUN_030F

	xor a
	ld [unk_start_15],a
	ld [unk_start_16],a
	ld [unk_start_17],a
	ld [unk_start_18],a
	ld [unk_start_19],a
	ld [unk_start_20],a
	ld [unk_start_21_low],a
	ld [unk_start_21_hig],a
	ldh [unk_high_start_1],a
	ld [unk_start_23],a
	ld [unk_start_24],a
	ld hl,unk_start_25
	ld [hl+],a
	ld [hl+],a
	ld [hl+],a
	ld [hl],a

.LAB_02DB:
	ld a,[unk_start_26]
	or a
	call z,FUN_12D0

	ld a,[unk_start_15]
	or a
	jr z,.LAB_02DB

	ld a,[unk_start_27]
	or a
	jr z,.LAB_02F2

	bit 7,a
	jr z,.LAB_02DB

.LAB_02F2:
	di
	ld a,[unk_start_26]
	or a
	call nz,FUN_3331
	call int_off
	call FUN_1013

	ld a,0
	ld [unk_start_7],a
	ld hl,$0800
	rst $10
	call FUN_1013

	jp .LAB_028B


;; Functions
include "src/bank0/FUN_030F.inc"
include "src/bank0/FUN_036E.inc"

include "src/bank0/int_off.inc"

include "src/bank0/clear_memory.inc"
include "src/bank0/mem_clear.inc"