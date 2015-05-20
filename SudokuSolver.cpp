
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
	bool noPencilOne = true;
	bool noPencilTwo = true;
	bool noPencilThree = true;
	cout << "= === = === = === =\n"
	for(int j = 0; j < 9; j ++)
	{
		for(int i = 0; i < 9; i++)
		{
			cout << "= "
			if(gameBoard[i][j].elem != 0)
			{
				cout << gameBoard[i][j].elem;
				cout << gameBoard[i][j].elem;
				cout << gameBoard[i][j].elem;
				cout << " ";
			}
			else
			{
				if(i == 0 || i == 1 || i == 2)
				{
					if(!(gameBoard[i][j].pencil[0] != 0 || gameBoard[i][j].pencil[0] != NULL))
					{
						cout << gameBoard[i][j].pencil[0];
					}
					else
					{
						cout << " ";
					}
					if(!(gameBoard[i][j].pencil[1] != 0 || gameBoard[i][j].pencil[1] != NULL))
					{
						cout << gameBoard[i][j].pencil[1];
					}
					else
					{
						cout << " ";
					}
					if(!(gameBoard[i][j].pencil[2] != 0 || gameBoard[i][j].pencil[2] != NULL))
					{
						cout << gameBoard[i][j].pencil[2];
						cout << " ";
					}
					else
					{
						cout << "  ";
					}
				}
				else if(i == 3 || i == 4 || i == 5)
				{
					if(!(gameBoard[i][j].pencil[3] != 0 || gameBoard[i][j].pencil[3] != NULL))
					{
						cout << gameBoard[i][j].pencil[3];
					}
					else
					{
						cout << " ";
					}
					if(!(gameBoard[i][j].pencil[4] != 0 || gameBoard[i][j].pencil[4] != NULL))
					{
						cout << gameBoard[i][j].pencil[4];
					}
					else
					{
						cout << " ";
					}
					if(!(gameBoard[i][j].pencil[5] != 0 || gameBoard[i][j].pencil[5] != NULL))
					{
						cout << gameBoard[i][j].pencil[5];
						cout << " ";
					}
					else
					{
						cout << "  ";
					}
				}
				else
				{
					if(!(gameBoard[i][j].pencil[6] != 0 || gameBoard[i][j].pencil[6] != NULL))
					{
						cout << gameBoard[i][j].pencil[6];
					}
					else
					{
						cout << " ";
					}
					if(!(gameBoard[i][j].pencil[7] != 0 || gameBoard[i][j].pencil[7] != NULL))
					{
						cout << gameBoard[i][j].pencil[7];
					}
					else
					{
						cout << " ";
					}
					if(!(gameBoard[i][j].pencil[8] != 0 || gameBoard[i][j].pencil[8] != NULL))
					{
						cout << gameBoard[i][j].pencil[8];
						cout << " ";
					}
					else
					{
						cout << "  ";
					}
				}
			}
		}
		cout << "=\n"
	}
}