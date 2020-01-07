// Final Project : NewGame.h
//Author: KETKI MOHIT NAIK , VARSHITHA NALADALA, KARTHIK NARAYAN
//CPS400.M001.Fall2019.Data Structures and C++ Programming

// Description: Header file of NewGame (Child class of BaseGame class)

//////////////////////////////////////////////////////////

#pragma once
#include <vector>
#include <fstream>
#include "BaseGame.h"
using namespace std;
class NewGame : public BaseGame {
public:
	NewGame(string fp);
	// generates a new game by selecting one of the games declared in randomGame variable
	void generateNewGame();
	// it initiates the game by loading all the data into the variables of the game and then invoking the launchgame version of the base class
	void launchGame();
	
private:
	// random 4 games. 0 indicates that user need to input the value
	int randomGame[4][9][9] = { {
		{5,3,0,1,6,8,2,9,4},
		{8,6,2,0,5,4,3,1,7},
		{9,1,4,2,3,7,5,8,6},
		{2,4,0,8,7,6,9,3,1},
		{3,0,0,4,2,5,7,6,8},
		{6,7,8,3,1,9,4,2,5},
		{7,5,0,6,8,2,1,4,3},
		{4,8,0,5,9,1,6,7,2},
		{1,2,0,7,4,3,8,5,9}
	} };
};