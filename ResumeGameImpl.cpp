#include "ResumeGame.h"
#include <sstream>
#include <vector>

// Opens the save file at filePath so loadGameFromFile() can read it.
ResumeGame::ResumeGame(string filePath) {
    inFile.open(filePath);
}

// Reads the save file line by line. Each line contains nine space-separated
// integers representing one row of the grid. Rebuilds rowConstraints,
// colConstraints, and boxConstraints from the restored values so that
// move validation works correctly when the game resumes.
void ResumeGame::loadGameFromFile() {
    // Allocate constraint maps for each row, column, and 3x3 box.
    for (int i = 0; i < 9; i++) {
        rowConstraints[i] = new map<int, int>();
        colConstraints[i] = new map<int, int>();
        boxConstraints[i] = new map<int, int>();
    }

    string line;
    int rowIndex = 0;
    while (getline(inFile, line) && rowIndex < 9) {
        vector<int>* rowVec = new vector<int>();
        istringstream stream(line);
        int val;
        int col = 0;

        while (stream >> val && col < 9) {
            rowVec->push_back(val);
            if (val != 0) {
                (*rowConstraints[rowIndex])[val]                  = 1;
                (*colConstraints[col])[val]                       = 1;
                (*boxConstraints[getBoxIndex(rowIndex, col)])[val] = 1;
            }
            col++;
        }

        grid.push_back(rowVec);
        rowIndex++;
    }
}

// Loads the saved game state, opens the save file for writing, and runs
// the base game loop.
void ResumeGame::launchGame() {
    loadGameFromFile();
    outFile.open("gameStorage.txt", ios::out | ios::trunc);
    BaseGame::launchGame();
    outFile.close();
    inFile.close();
}
