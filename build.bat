@echo off
cl /EHsc /std:c++17 /D_CONSOLE ^
   main.cpp BaseGameImpl.cpp NewGameImpl.cpp ResumeGameImpl.cpp ^
   /FeSudoku.exe /link ^
   FilledShapes_Lib.lib user32.lib gdi32.lib kernel32.lib
