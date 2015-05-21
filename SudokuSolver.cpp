/* This is the implementation file for the Sudoku Solver
Compiler: g++
Author: Brittany Dibble 
*/
using namespace std;
#include "SudokuSolver.h"
#include <iostream>

SudokuSolver::SudokuSolver() //sets each element of the gameBoard to 0 and fills the pencil array with 1-9.
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			gameBoard[i][j].elem = 0;
			for(int q = 0; q < 9;q++)
			{
				gameBoard[i][j].pencil[q] = q+1;
			}
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
	//check that the move is legal
	gameBoard[x-1][y-1].elem = number;
	//this then needs to check the square and the rows and remove pencil marks
}
/* Purpose: To be used by printRow. Prints out a small section of the row based on the column entered.
How to Call: Give the integer for the row and the column to be printed out.
*/
void SudokuSolver::printRowCol(int r, int c)
{
	int q;
	if(r <= 3)
	{
		q = 0;
	}
	if(r <= 6)
	{
		q = 1;
	}
	if(r <= 9)
	{
		q = 2;
	}
	if(gameBoard[r][c].elem == 0)
	{
		if(r%3 == 1)
		{
			cout << gameBoard[q][c].pencil[0] 
			<< gameBoard[q][c].pencil[1] 
			<< gameBoard[q][c].pencil[2];
		}
		if(r%3 == 2)
		{
			cout << gameBoard[q][c].pencil[3] 
			<< gameBoard[q][c].pencil[4] 
			<< gameBoard[q][c].pencil[5];
		}
		if(r%3 == 0)
		{
			cout << gameBoard[q][c].pencil[6] 
			<< gameBoard[q][c].pencil[7] 
			<< gameBoard[q][c].pencil[8];
		}
	}
	else
	{
		if(r%3 == 2)//the part of the row the shows the input if it exists
		{
			cout << " " << gameBoard[q][c].elem << " |";
		}
		else
		{
			cout << "   |";
		}
	}
	return;
}
/* Purpose: To be used by printBoard. Given the row number it prints out that row of the board.
How to Call: Give the integer of the row to be printed, starting from 1 and going to 9.
*/
void SudokuSolver::printRow(int r)
{
	printRowCol(r, 0);
	cout << "|";
	printRowCol(r, 1);
	cout << "|";
	printRowCol(r, 2);
	cout << "|";
	return;
}
/* Purpose: Prints out the gameBoard and the pencil marks in a readable format. 
*/
void SudokuSolver::printBoard()
{
	cout << "=|===|===|===|=\n";
	
	cout << "=|";
	printRow(1);
	cout << "=\n";
	cout << "=|";
	printRow(2);
	cout << "=\n";
	cout << "=|";
	printRow(3);
	cout << "=\n";
	
	cout << "=|===|===|===|=\n";
	
	cout << "=|";
	printRow(4);
	cout << "=\n";
	cout << "=|";
	printRow(5);
	cout << "=\n";
	cout << "=|";
	printRow(6);
	cout << "=\n";
	
	cout << "=|===|===|===|=\n";
	
	cout << "=|";
	printRow(7);
	cout << "=\n";
	cout << "=|";
	printRow(8);
	cout << "=\n";
	cout << "=|";
	printRow(9);
	cout << "=\n";
	
	cout << "=|===|===|===|=\n";
}
