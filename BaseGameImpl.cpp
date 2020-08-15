

#include "BaseGame.h"
#include <sstream>
bool BaseGame::validEntry(int row, int col, int val) {

	if (rowData.find(row) != rowData.end() && (*rowData[row]).find(val) != (*rowData[row]).end())
		return false;

	if (colData.find(col) != colData.end() && (*colData[col]).find(val) != (*colData[col]).end())
		return false;

	int cell = getCellNumber(row, col);

	if (cellData.find(cell) != cellData.end() && (*cellData[cell]).find(val) != (*cellData[cell]).end())
		return false;
	return true;
}

int BaseGame::getCellNumber(int row, int col) {
	if (row >= 0 && row <= 2 && col >= 0 && col <= 2)
		return 0;
	if (row >= 0 && row <= 2 && col >= 3 && col <= 5)
		return 1;
	if (row >= 0 && row <= 2 && col >= 6 && col <= 8)
		return 2;

	if (row >= 3 && row <= 5 && col >= 0 && col <= 2)
		return 3;
	if (row >= 3 && row <= 5 && col >= 3 && col <= 5)
		return 4;
	if (row >= 3 && row <= 5 && col >= 6 && col <= 8)
		return 5;

	if (row >= 6 && row <= 8 && col >= 0 && col <= 2)
		return 6;
	if (row >= 6 && row <= 8 && col >= 3 && col <= 5)
		return 7;
	if (row >= 6 && row <= 8 && col >= 6 && col <= 8)
		return 8;


}

void BaseGame::launchGame() {
	while (!isGameComplete()) {
		displayUI();
		vector<int>* userInput = getUserInput();
		if (validateUserInput(*userInput)) {
			
			//(*gameDataRows[(*userInput)[0]])[(*userInput)[1]] = (*userInput)[2];
			(*this) + *userInput;
			(*rowData[(*userInput)[0]])[(*userInput)[2]] = 1;
			(*colData[(*userInput)[1]])[(*userInput)[2]] = 1;
			(*cellData[getCellNumber((*userInput)[0], (*userInput)[1])])[(*userInput)[2]] = 1;
			
			writeGameDateIntoFile();
		}

		else {
			errorAction(*userInput);
		}
	}

	cout << "Congrats ! you have completed the game\n";

	ofptr.close();
	ofstream os("gameStorage.txt");
	cin.get();
}

void BaseGame::insertNumberInRectShapes(int number, POINT& p) {

	POINT start, end;
	
	switch (number) {
	case 1:
		start.x = p.x + 25;
		start.y = p.y + 10;
		end.x = p.x + 25;
		end.y = p.y + 25;
		fs.Line(start, end);
		break;
	case 2:
		start.x = p.x + 10;
		start.y = p.y + 10;
		end.x = p.x + 30;
		end.y = p.y + 10;
		fs.Line(start,end);

		start.x = p.x + 10;
		start.y = p.y + 30;
		end.x = p.x + 30;
		end.y = p.y + 30;
		fs.Line(start, end);

		start.x = p.x + 10;
		start.y = p.y + 30;
		end.x = p.x + 30;
		end.y = p.y + 10;
		fs.Line(start, end);

		break;
	case 3:
		start.x = p.x + 10;
		start.y = p.y + 30;
		end.x = p.x + 30;
		end.y = p.y + 30;
		fs.Line(start, end);

		start.x = p.x + 30;
		start.y = p.y + 30;
		end.x = p.x + 30;
		end.y = p.y + 10;
		fs.Line(start, end);

		start.x = p.x + 10;
		start.y = p.y + 10;
		end.x = p.x + 30;
		end.y = p.y + 10;
		fs.Line(start, end);

		start.x = p.x + 10;
		start.y = p.y + 20;
		end.x = p.x + 30;
		end.y = p.y + 20;
		fs.Line(start, end);

		break;
	case 4:
		start.x = p.x + 30;
		start.y = p.y + 30;
		end.x = p.x + 30;
		end.y = p.y + 20;
		fs.Line(start, end);

		start.x = p.x + 10;
		start.y = p.y + 20;
		end.x = p.x + 30;
		end.y = p.y + 20;
		fs.Line(start, end);

		start.x = p.x + 10;
		start.y = p.y + 20;
		end.x = p.x + 10;
		end.y = p.y + 10;
		fs.Line(start, end);

		break;
	case 5:
		start.x = p.x + 10;
		start.y = p.y + 30;
		end.x = p.x + 30;
		end.y = p.y + 30;
		fs.Line(start, end);

		start.x = p.x + 30;
		start.y = p.y + 30;
		end.x = p.x + 30;
		end.y = p.y + 20;
		fs.Line(start, end);

		start.x = p.x + 10;
		start.y = p.y + 20;
		end.x = p.x + 30;
		end.y = p.y + 20;
		fs.Line(start, end);

		start.x = p.x + 10;
		start.y = p.y + 20;
		end.x = p.x + 10;
		end.y = p.y + 10;
		fs.Line(start, end);

		start.x = p.x + 30;
		start.y = p.y + 10;
		end.x = p.x + 10;
		end.y = p.y + 10;
		fs.Line(start, end);

		break;
	case 6:
		start.x = p.x + 10;
		start.y = p.y + 10;
		end.x = p.x + 10;
		end.y = p.y + 30;
		fs.Line(start, end);

		start.x = p.x + 10;
		start.y = p.y + 30;
		end.x = p.x + 30;
		end.y = p.y + 30;
		fs.Line(start, end);

		start.x = p.x + 10;
		start.y = p.y + 20;
		end.x = p.x + 30;
		end.y = p.y + 20;
		fs.Line(start, end);

		start.x = p.x + 30;
		start.y = p.y + 20;
		end.x = p.x + 30;
		end.y = p.y + 30;
		fs.Line(start, end);
		

		break;
	case 7:
		start.x = p.x + 10;
		start.y = p.y + 10;
		end.x = p.x + 30;
		end.y = p.y + 10;
		fs.Line(start, end);

		start.x = p.x + 30;
		start.y = p.y + 30;
		end.x = p.x + 30;
		end.y = p.y + 10;
		fs.Line(start, end);

		break;
	case 8:
		start.x = p.x + 10;
		start.y = p.y + 10;
		end.x = p.x + 10;
		end.y = p.y + 30;
		fs.Line(start, end);

		start.x = p.x + 30;
		start.y = p.y + 10;
		end.x = p.x + 30;
		end.y = p.y + 30;
		fs.Line(start, end);

		start.x = p.x + 10;
		start.y = p.y + 30;
		end.x = p.x + 30;
		end.y = p.y + 30;
		fs.Line(start, end);

		start.x = p.x + 10;
		start.y = p.y + 10;
		end.x = p.x + 30;
		end.y = p.y + 10;
		fs.Line(start, end);

		start.x = p.x + 10;
		start.y = p.y + 20;
		end.x = p.x + 30;
		end.y = p.y + 20;
		fs.Line(start, end);

		break;
	case 9:

		start.x = p.x + 30;
		start.y = p.y + 10;
		end.x = p.x + 30;
		end.y = p.y + 30;
		fs.Line(start, end);

		start.x = p.x + 10;
		start.y = p.y + 10;
		end.x = p.x + 30;
		end.y = p.y + 10;
		fs.Line(start, end);

		start.x = p.x + 10;
		start.y = p.y + 20;
		end.x = p.x + 30;
		end.y = p.y + 20;
		fs.Line(start, end);

		start.x = p.x + 10;
		start.y = p.y + 20;
		end.x = p.x + 10;
		end.y = p.y + 10;
		fs.Line(start, end);

		break;

	}

	

}

void BaseGame::displayUI() {
	system("cls");
	
	fs.ClearScreen();
	fs.SetPenColor(borderColor);
	fs.SetBrushColor(fillcolor);
	
	POINT p;
	p.x = 5;
	p.y = 5;
	for (int i = 0; i < 9; i++) {
		p.x = 5;
		for (int j = 0; j < 9; j++) {
			
			fs.FilledRectangle(p, 50, 50);	
			insertNumberInRectShapes((*gameDataRows[i])[j],p);
			p.x += 50;
		}
		p.y += 35;
	}
	/*for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << (*gameDataRows[i])[j] << " ";
		}

		cout << "\n";
	}*/
}

vector<int>* BaseGame::getUserInput() {
	string row,col,number;
	vector<int>* temp = new vector<int>;
	cin >> row >> col >> number;
	temp->push_back(stoi(row));
	temp->push_back(stoi(col));
	temp->push_back(stoi(number));
	return temp;
}

bool BaseGame::validateUserInput(vector<int> userInput) {
	return validEntry(userInput[0], userInput[1], userInput[2]);
}

bool BaseGame::isGameComplete() {
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			//cout << (*gameDataRows[i])[j] << "\n";
			if ((*gameDataRows[i])[j] == 0)
				return false;
		}
	}
	return true;
}

void BaseGame::errorAction(vector<int> userInput) {
	cout << "Invalid data! it violates the game rules \n";
	//cin.get();
	cin.get();
}

void BaseGame::writeGameDateIntoFile() {
	ofptr.close();
	ofstream os("gameStorage.txt");
	ofptr.open("gameStorage.txt");
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			ofptr << (*gameDataRows[i])[j] << " ";
		}

		ofptr << "\n";
	}

	ofptr.flush();
}


void BaseGame::operator+(vector<int>& userInput) {
	(*gameDataRows[(userInput)[0]])[(userInput)[1]] = (userInput)[2];

}
