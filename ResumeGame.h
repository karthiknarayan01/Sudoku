

#pragma once
#include "BaseGame.h"
class ResumeGame : public BaseGame {
public:
	// takes the location of the gamedata file and then opens a file pointer
	ResumeGame(string fp);
	// reads the contents inside the file and populates the gamedata variable
	void extractGameDataFromFile();
	// launches the basegame variable
	void launchGame();

};
