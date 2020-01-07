// Final Project : NewGame.cpp 
//Author: KETKI MOHIT NAIK , VARSHITHA NALADALA, KARTHIK NARAYAN
//CPS400.M001.Fall2019.Data Structures and C++ Programming

// Description: Implementation file of NewGame (Child class of BaseGame class)

//////////////////////////////////////////////////////////

#include "NewGame.h"
#include <stdlib.h>
#include <time.h>

NewGame::NewGame(string fp) {

		ofptr.open(fp, ios::out | ios::trunc);
	
	
}



void NewGame::generateNewGame() {
	srand((unsigned int)time(0));
	
	vector<int>* temp;
	int randomCellValue;
	// initialize gameDataRows
	for (int i = 0; i < 9; i++) {
		temp = new vector<int>();
		for (int j = 0; j < 9; j++)
			temp->push_back(0);
		gameDataRows.push_back(temp);
	}

	

	for (int i = 0; i < 9; i++) {
		rowData[i] = new map<int, int>();
		colData[i] = new map<int, int>();
		cellData[i] = new map<int, int>();
	}

	// randomnly selects a game among four games declared in the newGame.h file
	int tempGame = rand() % 1;
	// populates the gamedata in gameDataRows variable
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			
			(*gameDataRows[i])[j] = randomGame[tempGame][i][j];
			if (randomGame[tempGame][i][j] != 0) {
				(*rowData[i])[randomGame[tempGame][i][j]] = 1;
				(*colData[j])[randomGame[tempGame][i][j]] = 1;
				(*cellData[getCellNumber(i,j)])[randomGame[tempGame][i][j]] = 1;
			}

		}
	}

	
}

void NewGame::launchGame() {
	generateNewGame();
	// calls the method launchgame in base class
	BaseGame::launchGame();
	ofptr.close();
	ifptr.close();
}