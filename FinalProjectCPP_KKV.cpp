

#include <iostream>
#include <fstream>
#include "NewGame.h"
#include "ResumeGame.h"
#include "BaseGame.h"

using namespace std;

// determines whether the game type i.e. Resume or new game
BaseGame* determineGameType(string fileLoc);

int main()
{
	// handle exceptions thrown while opening the file or reading the data in file or conversion of user input to integer
	try {
		string gameLocation = "gameStorage.txt";
		cout << "Welcome to Sudoku Game\nIn order to play this game you need to enter the value which you want to enter in blank box by entering the value in this format (rownumber space colnumber space value)\n";
		cin.get();
		// Polymorphism is done here where the proper downcasting is done to invoke the launchgame method
		BaseGame* game = determineGameType(gameLocation);
		NewGame* newGame = dynamic_cast<NewGame*>(game);
		ResumeGame* resumeGame = dynamic_cast<ResumeGame*>(game);
		if (newGame != NULL)
			newGame->launchGame();
		else
			resumeGame->launchGame();
	}
	catch (ofstream::failure) {
		cerr << "Error opening the file\n";
	}
	catch (invalid_argument e) {
		cerr << "Junk data in the game data file\n";
	}
}

BaseGame* determineGameType(string fileLoc) {
	ifstream fptr;
	string line;
	fptr.open(fileLoc);
	// if the file contains some data then it is a new game
	if (fptr >> line)
	{
		fptr.close();

		return new ResumeGame(fileLoc);
	}
	fptr.close();
	return new NewGame(fileLoc);
}
