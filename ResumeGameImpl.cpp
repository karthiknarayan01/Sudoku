

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


