#include "BaseGame.h"
#include <sstream>

// Returns true if placing val at (row, col) does not conflict with any
// existing number in the same row, column, or 3x3 box.
bool BaseGame::validEntry(int row, int col, int val) {
    if (rowConstraints.count(row) && rowConstraints[row]->count(val))
        return false;

    if (colConstraints.count(col) && colConstraints[col]->count(val))
        return false;

    int boxIdx = getBoxIndex(row, col);
    if (boxConstraints.count(boxIdx) && boxConstraints[boxIdx]->count(val))
        return false;

    return true;
}

// Maps a (row, col) pair to one of the nine 3x3 box indices using integer
// division: boxRow = row/3, boxCol = col/3, index = boxRow*3 + boxCol.
int BaseGame::getBoxIndex(int row, int col) {
    return (row / 3) * 3 + (col / 3);
}

// Main game loop. Keeps prompting the player for moves until the board is
// full. Valid moves are recorded in the constraint maps and persisted to disk.
// Clears the save file when the game is won.
void BaseGame::launchGame() {
    while (!isGameComplete()) {
        displayUI();
        vector<int>* userMove = getUserInput();

        if (validateUserInput(*userMove)) {
            (*this) + *userMove;

            int row = (*userMove)[0];
            int col = (*userMove)[1];
            int val = (*userMove)[2];

            (*rowConstraints[row])[val]                   = 1;
            (*colConstraints[col])[val]                   = 1;
            (*boxConstraints[getBoxIndex(row, col)])[val] = 1;

            writeGameDataToFile();
        } else {
            errorAction(*userMove);
        }
    }

    cout << "Congrats! You have completed the game.\n";

    // Clear the save file so the next run starts a fresh game.
    outFile.close();
    ofstream clearFile("gameStorage.txt", ios::trunc);
    cin.get();
}

// Draws the digit number as a series of line segments inside a cell whose
// top-left corner is at origin. Each case encodes the segment geometry for
// that digit using pixel offsets relative to origin.
void BaseGame::insertNumberInRectShapes(int number, POINT& origin) {
    POINT lineStart, lineEnd;

    switch (number) {
    case 1:
        lineStart = {origin.x + 25, origin.y + 10};
        lineEnd   = {origin.x + 25, origin.y + 25};
        graphics.Line(lineStart, lineEnd);
        break;

    case 2:
        lineStart = {origin.x + 10, origin.y + 10}; lineEnd = {origin.x + 30, origin.y + 10};
        graphics.Line(lineStart, lineEnd);
        lineStart = {origin.x + 10, origin.y + 30}; lineEnd = {origin.x + 30, origin.y + 30};
        graphics.Line(lineStart, lineEnd);
        lineStart = {origin.x + 10, origin.y + 30}; lineEnd = {origin.x + 30, origin.y + 10};
        graphics.Line(lineStart, lineEnd);
        break;

    case 3:
        lineStart = {origin.x + 10, origin.y + 30}; lineEnd = {origin.x + 30, origin.y + 30};
        graphics.Line(lineStart, lineEnd);
        lineStart = {origin.x + 30, origin.y + 30}; lineEnd = {origin.x + 30, origin.y + 10};
        graphics.Line(lineStart, lineEnd);
        lineStart = {origin.x + 10, origin.y + 10}; lineEnd = {origin.x + 30, origin.y + 10};
        graphics.Line(lineStart, lineEnd);
        lineStart = {origin.x + 10, origin.y + 20}; lineEnd = {origin.x + 30, origin.y + 20};
        graphics.Line(lineStart, lineEnd);
        break;

    case 4:
        lineStart = {origin.x + 30, origin.y + 30}; lineEnd = {origin.x + 30, origin.y + 20};
        graphics.Line(lineStart, lineEnd);
        lineStart = {origin.x + 10, origin.y + 20}; lineEnd = {origin.x + 30, origin.y + 20};
        graphics.Line(lineStart, lineEnd);
        lineStart = {origin.x + 10, origin.y + 20}; lineEnd = {origin.x + 10, origin.y + 10};
        graphics.Line(lineStart, lineEnd);
        break;

    case 5:
        lineStart = {origin.x + 10, origin.y + 30}; lineEnd = {origin.x + 30, origin.y + 30};
        graphics.Line(lineStart, lineEnd);
        lineStart = {origin.x + 30, origin.y + 30}; lineEnd = {origin.x + 30, origin.y + 20};
        graphics.Line(lineStart, lineEnd);
        lineStart = {origin.x + 10, origin.y + 20}; lineEnd = {origin.x + 30, origin.y + 20};
        graphics.Line(lineStart, lineEnd);
        lineStart = {origin.x + 10, origin.y + 20}; lineEnd = {origin.x + 10, origin.y + 10};
        graphics.Line(lineStart, lineEnd);
        lineStart = {origin.x + 30, origin.y + 10}; lineEnd = {origin.x + 10, origin.y + 10};
        graphics.Line(lineStart, lineEnd);
        break;

    case 6:
        lineStart = {origin.x + 10, origin.y + 10}; lineEnd = {origin.x + 10, origin.y + 30};
        graphics.Line(lineStart, lineEnd);
        lineStart = {origin.x + 10, origin.y + 30}; lineEnd = {origin.x + 30, origin.y + 30};
        graphics.Line(lineStart, lineEnd);
        lineStart = {origin.x + 10, origin.y + 20}; lineEnd = {origin.x + 30, origin.y + 20};
        graphics.Line(lineStart, lineEnd);
        lineStart = {origin.x + 30, origin.y + 20}; lineEnd = {origin.x + 30, origin.y + 30};
        graphics.Line(lineStart, lineEnd);
        break;

    case 7:
        lineStart = {origin.x + 10, origin.y + 10}; lineEnd = {origin.x + 30, origin.y + 10};
        graphics.Line(lineStart, lineEnd);
        lineStart = {origin.x + 30, origin.y + 30}; lineEnd = {origin.x + 30, origin.y + 10};
        graphics.Line(lineStart, lineEnd);
        break;

    case 8:
        lineStart = {origin.x + 10, origin.y + 10}; lineEnd = {origin.x + 10, origin.y + 30};
        graphics.Line(lineStart, lineEnd);
        lineStart = {origin.x + 30, origin.y + 10}; lineEnd = {origin.x + 30, origin.y + 30};
        graphics.Line(lineStart, lineEnd);
        lineStart = {origin.x + 10, origin.y + 30}; lineEnd = {origin.x + 30, origin.y + 30};
        graphics.Line(lineStart, lineEnd);
        lineStart = {origin.x + 10, origin.y + 10}; lineEnd = {origin.x + 30, origin.y + 10};
        graphics.Line(lineStart, lineEnd);
        lineStart = {origin.x + 10, origin.y + 20}; lineEnd = {origin.x + 30, origin.y + 20};
        graphics.Line(lineStart, lineEnd);
        break;

    case 9:
        lineStart = {origin.x + 30, origin.y + 10}; lineEnd = {origin.x + 30, origin.y + 30};
        graphics.Line(lineStart, lineEnd);
        lineStart = {origin.x + 10, origin.y + 10}; lineEnd = {origin.x + 30, origin.y + 10};
        graphics.Line(lineStart, lineEnd);
        lineStart = {origin.x + 10, origin.y + 20}; lineEnd = {origin.x + 30, origin.y + 20};
        graphics.Line(lineStart, lineEnd);
        lineStart = {origin.x + 10, origin.y + 20}; lineEnd = {origin.x + 10, origin.y + 10};
        graphics.Line(lineStart, lineEnd);
        break;
    }
}

// Clears the screen and redraws the entire 9x9 grid. Each cell is a filled
// rectangle; non-zero values are rendered as line-segment digits.
void BaseGame::displayUI() {
    system("cls");
    graphics.ClearScreen();
    graphics.SetPenColor(gridBorderColor);
    graphics.SetBrushColor(cellFillColor);

    POINT cellOrigin;
    cellOrigin.y = 5;
    for (int row = 0; row < 9; row++) {
        cellOrigin.x = 5;
        for (int col = 0; col < 9; col++) {
            graphics.FilledRectangle(cellOrigin, 50, 50);
            insertNumberInRectShapes((*grid[row])[col], cellOrigin);
            cellOrigin.x += 50;
        }
        cellOrigin.y += 35;
    }
}

// Reads a move from stdin as three whitespace-separated tokens (row, col, val)
// and returns them as a heap-allocated three-element vector.
vector<int>* BaseGame::getUserInput() {
    string rowStr, colStr, valStr;
    cin >> rowStr >> colStr >> valStr;

    vector<int>* userMove = new vector<int>;
    userMove->push_back(stoi(rowStr));
    userMove->push_back(stoi(colStr));
    userMove->push_back(stoi(valStr));
    return userMove;
}

// Delegates validation to validEntry using the move components.
bool BaseGame::validateUserInput(vector<int> userMove) {
    return validEntry(userMove[0], userMove[1], userMove[2]);
}

// Returns true if no cell in the grid contains zero.
bool BaseGame::isGameComplete() {
    for (int row = 0; row < 9; row++)
        for (int col = 0; col < 9; col++)
            if ((*grid[row])[col] == 0)
                return false;
    return true;
}

// Prints an error message and waits for the player to press Enter.
void BaseGame::errorAction(vector<int> userMove) {
    cout << "Invalid move — it violates the Sudoku rules. Press Enter to try again.\n";
    cin.get();
}

// Rewrites the entire grid to the save file so the game can be resumed.
// Each row is written as nine space-separated integers followed by a newline.
void BaseGame::writeGameDataToFile() {
    outFile.close();
    outFile.open("gameStorage.txt", ios::out | ios::trunc);
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++)
            outFile << (*grid[row])[col] << " ";
        outFile << "\n";
    }
    outFile.flush();
}

// Places the value from userMove into the appropriate grid cell.
void BaseGame::operator+(vector<int>& userMove) {
    (*grid[userMove[0]])[userMove[1]] = userMove[2];
}
