@echo off

cls

for /f "tokens=2 delims==" %%a in ('wmic OS Get localdatetime /value') do set "dt=%%a"
set "date=%dt:~0,4%_%dt:~4,2%_%dt:~6,2%"

ROBOCOPY "src" "target\debug\%date%\source\src" /mir /nfl /ndl /njh /njs /np /ns /nc > nul

rgbasm  -L -o target/debug/%date%/DWM.o   src/entry.asm
rgblink -o    target/debug/%date%/DWM.gbc target/debug/%date%/DWM.o -w
rgbfix        target/debug/%date%/DWM.gbc -c -i AWQE -j -k 4F -l 0x33 -m 0x1B -r 0x02 -s -t "DRAGON WMON" -v -p 0x00

del compared.txt
fc /b ROM\DWM.gbc target\debug\%date%\DWM.gbc >> compared.txt