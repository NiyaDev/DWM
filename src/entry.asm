
; Definitions
include "src/includes/hardware.inc"
include "src/constants.inc"
include "src/macros.inc"
include "src/todo.inc"

;; RAM
include "src/ram/hram.inc"
include "src/ram/sram.inc"
include "src/ram/vram.inc"
include "src/ram/wram.inc"

; Home
include "src/home/reset_vectors.inc"
include "src/home/interrupts.inc"
include "src/home/copy_dma.inc"

db $13,$cd,$90,$12,$cd,$00,$40,$cd
db $ba,$17,$af,$ea,$84,$c9,$e1,$d1
db $c1,$f1,$d9,$cd,$c2,$00,$af,$e0
db $0f,$fa,$99,$c9,$e0,$ff,$fb,$cd
db $ed,$04,$e1,$d1,$c1,$f1,$cd,$a7
db $04,$d9,$21,$91,$c9,$2a,$e0,$42
db $2a,$e0,$43,$2a,$e0,$4a,$2a,$e0
db $4b,$2a,$e0,$47,$2a,$e0,$48,$2a
db $e0,$49,$7e,$e0,$45,$fa,$c1,$dd
db $ea,$c0,$dd,$fa,$90,$c9,$e0,$40
db $fa,$c7,$dd,$b7,$c8,$c3,$14,$12
db $ff,$ff,$ff,$ff,$ff,$ff,$ff,$ff
db $ff,$ff,$ff,$ff,$ff,$ff,$ff,$ff


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

	call int_res
	call clear_memory
	call copy_dma

	; Clear first $1C00 of VRAM
	ld hl,_VRAM
	ld bc,$1C00
	xor a
	call mem_fill

	; Set $C88A->$C88D to 0
	ld hl,wUNK_START_1
	xor a
	ld [hl+],a
	ld [hl+],a
	ld [hl+],a
	ld [hl],a

	ld a,4
	ld [wUNK_START_2],a
	ld a,0
	ld [wUNK_START_1],a
	
	; Writing to SRAM and RTCLatch? Does MBC5 even have that?
	ld a,1
	ld [rRTCLATCH+$100],a
	ld a,0
	ld [rRAMB+$100],a
	ld a,0
	ld [rRTCLATCH+$100],a
	ld a,0
	ld [rRAMB+$100],a

	; Enable reading and writing to SRAM
	ld a,WRITE_SRAM
	ld [rRAMG+$100],a

	; Set ROM bank to 1
	ld a,1
	ld [rROMB0+$100],a
	; Set SRAM bank to 0
	ld a,0
	ld [rRAMB+$100],a

	; Setting some variables
	ld a,1
	ld [doWait],a
	ld a,$FF
	ld [wUNK_START_4],a
	ld [wUNK_START_4+1],a
	
	call audio_init

	xor a
	ld [wUNK_START_5],a

	; If on DMG, jump
	ld a,[IsGBC]
	or a
	jr z,.check_for_sgb

	; Clearing GBC IO
	xor a
	ldh [rVBK],a
	ldh [rSVBK],a
	ldh [rRP],a

.check_for_sgb:
	; If returns true, go through SGB commands
	call check_sgb
	jr c,.sgb_commands

	; Turn off wait
	xor a
	ld [doWait],a
	jp .main_loop


.sgb_commands:
	; Wait ~.18 seconds
	ld bc,12
	call wait

	; SGB Request: Mask with black screen
	SGBCommand sgb_command_maskblack

	; SGB Request: Send data 
	SGBCommand sgb_command_data1
	SGBCommand sgb_command_data2
	SGBCommand sgb_command_data3
	SGBCommand sgb_command_data4
	SGBCommand sgb_command_data5
	SGBCommand sgb_command_data6
	SGBCommand sgb_command_data7
	SGBCommand sgb_command_data8

	; Initialize Palette Transfer
	ld a,sgb_command_paltrn
	ld de,jump_8_447E
	ld bc,2048
	call sgb_copy_border
	call wait_7000

	; Initialize Attribute files
	ld a,sgb_command_attrtrn
	ld de,jump_8_449E
	call FUN_10E5
	call wait_7000

	; SGB Request: Sets palette Priority to software
	SGBCommand sgb_command_palpri

	; SGB Request: 1-Player
	SGBCommand sgb_command_multione

	; SGB Request: Disable built in Palettes
	SGBCommand sgb_command_iconenable

	ld a,1
	ld [doWait],a

	ld a,$FF
	ld [wUNK_START_6],a

.main_loop:
	call clear_vram
	call FUN_1417
	call FUN_13EF
	call FUN_140B
	call FUN_1660

	xor a
	ld [wUNK_START_8],a
	ld [wUNK_START_9],a
	ld [wUNK_START_10],a
	ld [wUNK_START_11],a
	ld [wUNK_START_12],a
	ld [wUNK_START_13],a
	ld [wUNK_START_14],a
	call FUN_030F

	xor a
	ld [wUNK_START_15],a
	ld [wUNK_START_16],a
	ld [wUNK_START_17],a
	ld [wUNK_START_18],a
	ld [wUNK_START_19],a
	ld [wUNK_START_20],a
	ld [wUNK_START_21],a
	ld [wUNK_START_21+1],a
	ldh [hUNK_START],a
	ld [wUNK_START_23],a
	ld [wUNK_START_24],a
	ld hl,wUNK_START_25
	ld [hl+],a
	ld [hl+],a
	ld [hl+],a
	ld [hl],a

.LAB_02DB:
	ld a,[wUNK_START_26]
	or a
	call z,FUN_12D0

	ld a,[wUNK_START_15]
	or a
	jr z,.LAB_02DB

	ld a,[wUNK_START_27]
	or a
	jr z,.LAB_02F2

	bit 7,a
	jr z,.LAB_02DB

.LAB_02F2:
	di
	ld a,[wUNK_START_26]
	or a
	call nz,audio_init
	call int_res
	call wait_7000

	; SGB Request: Freeze mask
	ld a,sgb_command_maskfreeze
	ld [wUNK_START_7],a
	ld hl,jump_sgb_commands
	rst $10
	call wait_7000

	jp .main_loop


;; Functions
;; BANK0
include "src/bank0/FUN_030F.inc" ; 030F
include "src/bank0/FUN_036E.inc" ; 036E

include "src/bank0/wait_7000.inc" ; 1013
include "src/bank0/check_sgb.inc" ; 1024
;include "src/bank0/FUN_1082.inc" ; 1082
include "src/bank0/wait.inc" ; 10CF
include "src/bank0/FUN_10E5.inc" ; 10E5

include "src/bank0/sgb_copy_border.inc" ; 113E 

include "src/bank0/int_res.inc" ; 11DE

include "src/bank0/FUN_1264.inc" ; 1264

include "src/bank0/clear_memory.inc" ; 1288
include "src/bank0/clear_vram.inc" ; 12A5
include "src/bank0/mem_fill.inc" ; 12C7
include "src/bank0/FUN_12D0.inc" ; 12D0

include "src/bank0/FUN_13EF.inc" ; 13EF

include "src/bank0/FUN_140B.inc" ; 140B
include "src/bank0/FUN_1417.inc" ; 1417

include "src/bank0/FUN_14CF.inc" ; 14CF
include "src/bank0/FUN_14E1.inc" ; 14E1

include "src/bank0/FUN_1627.inc" ; 1627

include "src/bank0/FUN_1660.inc" ; 1660
include "src/bank0/FUN_1688.inc" ; 1688

include "src/bank0/audio_init.inc" ; 3331
db $AF,$EA,$29,$DE,$C9,$3E,$04,$EA
db $29,$DE,$AF,$EA,$1D,$DE,$C9 ; TODO: This is a function
include "src/bank0/FUN_336D.inc" ; 336D

;; BANK 8
include "src/bank8/jump_table.inc"
include "src/bank8/sgb_commands.inc"

;; BANK 21
include "src/bank21/jump_table.inc"
include "src/bank21/FUN_4009.inc"
include "src/bank21/FUN_404F.inc"


;; BANK123
SECTION "BANK123", ROMX[$4000], BANK[123]
db $83