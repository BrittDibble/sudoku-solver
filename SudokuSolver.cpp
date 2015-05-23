/* This is the implementation file for the Sudoku Solver
Compiler: g++
Author: Brittany Dibble 
*/
using namespace std;
#include "SudokuSolver.h"
#include <iostream>

SudokuSolver::SudokuSolver() //sets each element of the gameBoard to 0 and fills the pencil array with 1-9.
{
	for(int i = 0; i < 81; i++)
	{
		gameBoard[i].elem = 0;
		for(int j = 0; j < 9; j++)
		{
			gameBoard[i].pencil[j] = j + 1;
		}
	}
}
SudokuSolver::~SudokuSolver()
{
	//nothing to do as static memory was used
}

/* Purpose: Enters a number into the gameBoard given the row and column for the number. Will make a check
that placing the number is legal and removed pencil marks in the square, row, and column.
How to Call:Give the row, column  and the number.
*/
void SudokuSolver::enterNumber(int x, int y, int number)
{
	//I do nothing right now
	return;
}
/* Purpose: To be used by the printBoard. Prints out the row of the board including pencil marks.
How to Call: Provide the row number from 0 to 26;
*/
void SudokuSolver::printRow(int rowNumber)
{
	int row = rowNumber / 3;
	cout << "=|";
	for(int i = 0; i < 9; i++)
	{
		if(i % 3 == 0)
		{
			cout << "|";
		}
		cout << gameBoard[row].pencil[rowNumber*3]
		<< gameBoard[row].pencil[rowNumber*3 + 1]
		<< gameBoard[row].pencil[rowNumber*3 + 2]
		<< "|";
	}
	cout << "=";
	return;
}
/* Purpose: Prints out the gameBoard and the pencil marks in a readable format. 
*/
void SudokuSolver::printBoard()
{
	string aString = "=|======================================|=\n";
	for(int i = 0; i < 27; i++)
	{
		if(i % 3 == 0)
		{
			cout << aString;
		}
		if(i % 9 == 0)
		{
			cout << aString;
		}
		printRow(i);
		cout << "\n";
	}
	cout << aString;
	cout << aString;
	return;
}
