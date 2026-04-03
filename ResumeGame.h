#pragma once
#include "BaseGame.h"

using namespace std;

// Resumes a previously saved Sudoku game by reading the grid state from disk.
class ResumeGame : public BaseGame {
public:
    // Opens the save file at filePath for reading.
    ResumeGame(string filePath);

    // Parses the save file to restore the grid and rebuild the constraint maps.
    void loadGameFromFile();

    // Loads the saved game state and delegates to BaseGame::launchGame().
    void launchGame();
};
