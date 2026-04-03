#include "NewGame.h"
#include <cstdlib>
#include <ctime>

// Opens (and truncates) the save file at filePath for writing.
NewGame::NewGame(string filePath) {
    outFile.open(filePath, ios::out | ios::trunc);
}

// Seeds the RNG, picks one of the built-in puzzles at random, and populates
// the grid and constraint maps with all pre-filled clue values.
void NewGame::initializePuzzle() {
    srand(static_cast<unsigned int>(time(nullptr)));

    // Allocate a zero-filled 9x9 grid.
    for (int row = 0; row < 9; row++) {
        vector<int>* rowVec = new vector<int>(9, 0);
        grid.push_back(rowVec);
    }

    // Allocate the constraint maps for each row, column, and 3x3 box.
    for (int i = 0; i < 9; i++) {
        rowConstraints[i] = new map<int, int>();
        colConstraints[i] = new map<int, int>();
        boxConstraints[i] = new map<int, int>();
    }

    int selectedPuzzleIndex = rand() % PUZZLE_COUNT;

    // Copy clues from the selected puzzle into the grid and constraint maps.
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            int val = puzzleLibrary[selectedPuzzleIndex][row][col];
            (*grid[row])[col] = val;

            if (val != 0) {
                (*rowConstraints[row])[val]                   = 1;
                (*colConstraints[col])[val]                   = 1;
                (*boxConstraints[getBoxIndex(row, col)])[val] = 1;
            }
        }
    }
}

// Initializes the puzzle and runs the base game loop.
void NewGame::launchGame() {
    initializePuzzle();
    BaseGame::launchGame();
    outFile.close();
    inFile.close();
}
