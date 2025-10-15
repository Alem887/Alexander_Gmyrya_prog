@echo off
chcp 1251 > log
del log

set MAIN=after_refactoring_2
set EXE=after_refactoring
set CHARSET="-finput-charset=utf-8 -fexec-charset=windows-1251"

g++ "%CHARSET%" %MAIN%.cpp -o %EXE%

after_refactoring.exe