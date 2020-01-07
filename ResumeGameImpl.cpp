// Final Project : ResumeGameImpl.cpp
//Author: KETKI MOHIT NAIK , VARSHITHA NALADALA, KARTHIK NARAYAN
//CPS400.M001.Fall2019.Data Structures and C++ Programming

// Description: ResumeGame implementation

//////////////////////////////////////////////////////////

#include "ResumeGame.h"
#include <sstream>
#include<vector>
ResumeGame::ResumeGame(string fp) {
	ifptr.open(fp);
}

void ResumeGame::extractGameDataFromFile() {

	string line;
	stringstream ss;
	string token;
	vector<int>* temp;
	int i = 0;

		
			temp = new vector<int>();
			while (ifptr >> line) {
				
				ss = stringstream(line);

				while (getline(ss, token, ' ')) {
					(*temp).push_back(stoi(token));
					i += 1;
					
				}

				if (i % 9 == 0) {
					gameDataRows.push_back(temp);
					temp = new vector<int>;	
				}
				
			}

}

void ResumeGame::launchGame() {
	extractGameDataFromFile();
	ofptr.open("gameStorage.txt", ios::out | ios::trunc);
	BaseGame::launchGame();
	ofptr.close();
	ifptr.close();
}


