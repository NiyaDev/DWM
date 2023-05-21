#!/bin/bash

clear

date=$(date +"%Y_%m_%d")

mkdir "target/debug/$date" > /dev/null 2>&1
cp -r -u "src/" "target/debug/$date/src"

rgbasm  -L -o target/debug/$date/DWM.o   src/entry.asm
rgblink -o    target/debug/$date/DWM.gbc target/debug/$date/DWM.o
rgbfix        target/debug/$date/DWM.gbc -c -i AWQE -j -k 4F -l 0x33 -m 0x1B -r 0x02 -s -t "DRAGON WMON" -v -p 0x00

rm compared.txt
cmp -l ROM/DWM.gbc target/debug/$date/DWM.gbc | gawk '{printf "%08X %02X %02X\n", $1-1, strtonum(0$2), strtonum(0$3)}' > compared.txt