// Final Project : BaseGame.h
//Author: KETKI MOHIT NAIK , VARSHITHA NALADALA, KARTHIK NARAYAN
//CPS400.M001.Fall2019.Data Structures and C++ Programming

// Description: BaseGame header file

//////////////////////////////////////////////////////////

#pragma once
#include "FilledShapes.h"
#include<map>
#include<vector>
#include <fstream>
#include<iostream>
class BaseGame {
	
public:
	// controls the entire game
	virtual void launchGame();
	// generates filledshapes and populates each boxes with a number
	void displayUI();
	// takes the input from user which he/she enters in console
	vector<int>* getUserInput();
	// validates whether the entered value meets the conditions of the game
	bool validateUserInput(vector<int> userInput);
	// checks whether all the boxes are full
	bool isGameComplete();
	// displays appropriate error message to the user
	void errorAction(vector<int> userInput);
	// writes the sudoku grid to a file so that if the user exits the game then it can be used to launch again
	void writeGameDateIntoFile();
	// validates the user entry
	bool validEntry(int row, int col, int val);
	// gets a cell number in range [1..9] using the rownumber and colnumber
	int getCellNumber(int row, int col);
	// auxiliary method used by displayUi method to insert a number in a filled shape
	void insertNumberInRectShapes(int number,POINT &p);
	// operator overloadin done here wherein user input is taken and added to the gamedata
	void operator+( vector<int>& userInput);
protected:
	vector<vector<int>*> gameDataRows;
	map<int, map<int,int>*> rowData;
	map<int, map<int,int>*> colData;
	map<int, map<int,int>*> cellData;
	ofstream ofptr;
	ifstream ifptr;
private:
	FilledShapes fs;
	SHAPE_COLOR borderColor = PURPLE , fillcolor = RED;
};