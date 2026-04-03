#pragma once
#include "FilledShapes.h"
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Abstract base class that manages the core Sudoku game logic,
// including rendering, input handling, validation, and persistence.
class BaseGame {
public:
    // Runs the main game loop: renders the board, reads moves, validates,
    // updates state, and saves progress until the puzzle is solved.
    virtual void launchGame();

    // Clears the screen and redraws the 9x9 Sudoku grid with current values.
    void displayUI();

    // Reads a move from the console in "row col value" format and returns it
    // as a three-element vector: {row, col, value}.
    vector<int>* getUserInput();

    // Returns true if the given move satisfies all Sudoku constraints.
    bool validateUserInput(vector<int> userMove);

    // Returns true if every cell in the grid has been filled (no zeros remain).
    bool isGameComplete();

    // Prints an error message when the player enters an invalid move.
    void errorAction(vector<int> userMove);

    // Serializes the current grid to the save file so the game can be resumed.
    void writeGameDataToFile();

    // Returns true if placing val at (row, col) obeys row, column, and box rules.
    bool validEntry(int row, int col, int val);

    // Maps a (row, col) coordinate to one of the nine 3x3 box indices (0-8).
    int getBoxIndex(int row, int col);

    // Draws the digit number inside the rectangle whose top-left corner is origin.
    void insertNumberInRectShapes(int number, POINT& origin);

    // Updates the grid cell at (userMove[0], userMove[1]) with value userMove[2].
    void operator+(vector<int>& userMove);

protected:
    // 9x9 grid; 0 represents an empty cell.
    vector<vector<int>*> grid;

    // Constraint maps: key = index (0-8), value = set of numbers already placed.
    map<int, map<int, int>*> rowConstraints;
    map<int, map<int, int>*> colConstraints;
    map<int, map<int, int>*> boxConstraints;

    ofstream outFile;
    ifstream inFile;

private:
    FilledShapes graphics;
    SHAPE_COLOR  gridBorderColor = PURPLE;
    SHAPE_COLOR  cellFillColor   = RED;
};
