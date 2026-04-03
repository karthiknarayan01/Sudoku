# Sudoku

A console Sudoku game written in C++ with a graphical grid rendered via Windows GDI.

## Requirements

- Windows 10 or later
- [Visual Studio Build Tools](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2019) with the **MSVC compiler** and **Windows 10 SDK**

## Build & run

Open a **Developer Command Prompt for VS** (search for it in the Start menu), navigate to this folder, then:

```bat
build.bat
Sudoku.exe
```

Or compile manually in one command:

```bat
cl /EHsc /std:c++17 /D_CONSOLE main.cpp BaseGameImpl.cpp NewGameImpl.cpp ResumeGameImpl.cpp /FeSudoku.exe /link FilledShapes_Lib.lib user32.lib gdi32.lib kernel32.lib
```

## How to play

- Enter moves as `row col value` (e.g. `3 5 7`) and press Enter.
- Progress is saved automatically after every valid move — close and rerun to resume.
- The game ends when all 81 cells are filled correctly.
