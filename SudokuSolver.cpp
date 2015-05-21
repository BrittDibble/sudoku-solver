
using namespace std;
#include "SudokuSolver.h"
#include <iostream>

SudokuSolver::SudokuSolver()
{
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
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
//
void SudokuSolver::enterNumber(int x, int y, int number)
{
	gameBoard[x-1][y-1].elem = number;
}
//
void SudokuSolver::printBoard()
{
	cout << "This will be the board once it is done";
}