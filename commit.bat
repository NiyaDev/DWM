@echo off

cls

set commitText=%1
set commitTag=%2

cls

git add *
git commit -m %commitText%

if "%commitTag%"=="-p" git push -u origin main