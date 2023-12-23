
SECTION "1264", ROM0[$1264]

; `$1264 | Bank:0`
;
; Resets all LCDC status values.
reset_STAT:
	ldh a,[rSTAT]
	and STATF_LYCF | STATF_LCD
	ldh [rSTAT],a
	ret