@echo off

cls

code ./

call "D:\SDKs\Ghidra\support\launch.bat" bg Ghidra "%MAXMEM%" "" ghidra.GhidraRun %*
