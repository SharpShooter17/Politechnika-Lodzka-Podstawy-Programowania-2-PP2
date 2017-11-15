@echo off 

set path=%PATH%;C:\MinGW-4.8.1\bin

g++.exe main.cpp -std=c++11

a.exe

echo.
echo Aplikacja zwrocila wartosc:  %errorlevel%

cmd.exe