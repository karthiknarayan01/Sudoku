#include <fstream>
#include <iostream>
#include "NewGame.h"
#include "ResumeGame.h"

using namespace std;

// Returns a NewGame if the save file is empty or missing, or a ResumeGame
// if the file contains a previously saved grid.
BaseGame* createGame(const string& saveFilePath);

int main() {
    try {
        const string saveFilePath = "gameStorage.txt";

        cout << "Welcome to Sudoku!\n"
             << "Enter your move as: row col value  (e.g. 3 5 7)\n"
             << "Press Enter to start...\n";
        cin.get();

        BaseGame* game = createGame(saveFilePath);

        NewGame*    newGame    = dynamic_cast<NewGame*>(game);
        ResumeGame* resumeGame = dynamic_cast<ResumeGame*>(game);

        if (newGame != nullptr)
            newGame->launchGame();
        else
            resumeGame->launchGame();

    } catch (const ofstream::failure&) {
        cerr << "Error: could not open the save file.\n";
    } catch (const invalid_argument&) {
        cerr << "Error: the save file contains invalid data.\n";
    }
}

// Opens saveFilePath and checks whether it contains any data.
// A non-empty file means a game was previously saved and should be resumed;
// an empty or absent file means this is a fresh start.
BaseGame* createGame(const string& saveFilePath) {
    ifstream saveFile(saveFilePath);
    string   firstLine;

    if (saveFile >> firstLine) {
        saveFile.close();
        return new ResumeGame(saveFilePath);
    }

    saveFile.close();
    return new NewGame(saveFilePath);
}
