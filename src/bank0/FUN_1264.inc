
SECTION "1264", ROM0[$1264]

; Modifies rSTAT
FUN_1264:
	ldh a,[rSTAT]
	and STATF_LYCF | STATF_LCD
	ldh [rSTAT],a
	ret