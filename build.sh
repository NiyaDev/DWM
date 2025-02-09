#!/bin/bash

clear


rgbasm  -o target/DWM.o   src/entry.asm
rgblink -o target/DWM.gbc target/DWM.o
rgbfix     target/DWM.gbc -c -i AWQE -j -k 4F -l 0x33 -m 0x1B -r 0x02 -s -t "DRAGON WMON" -v -p 0x00

filesize=$(cat rom/DWM-Decomp.gbc | wc -c)
diffs=$(radiff2 -c rom/DWM-Decomp.gbc target/DWM.gbc)
echo $diffs / $filesize
perc=$(bc <<< "scale = 10; ($diffs / $filesize) * 100")
echo Similarity: $perc%


rm compared.txt
cmp -l rom/DWM-Decomp.gbc target/DWM.gbc | gawk '{printf "%08X %02X %02X\n", $1-1, strtonum(0$2), strtonum(0$3)}' > compared.txt
