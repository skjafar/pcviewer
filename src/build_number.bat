@echo off 
set /p var= <build_number.txt 
set /a var= %var%+1 
echo %var% >build_number.txt
echo #define BUILD_NUMBER %var% >build_number.h
echo %var%