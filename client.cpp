/* This is the client file for the Sudoku Solver
Compiler: g++
Author: Brittany Dibble 
This client file runs 4 tests on the solve function and reports if it worked.
*/
using namespace std;
#include "SudokuSolver.h"
#include <iostream>
int main()
{
	bool continueLoop, puzzleLoop, puzzleCompeate;
	int x,y, enteredNumber;
	char entered;
	SudokuSolver aSolver;
	
	continueLoop = true;
	while(continueLoop)
	{
		cout << "Would you like to enter the numbers for your Sudoku Puzzle? (y/n)\n";
		cin >> entered;
		if(entered == 'y' || entered == 'Y')
		{
			puzzleLoop = true;
			while(puzzleLoop)
			{
				cout << "Enter all 0s to stop entering.\n";
				cout << "Enter the Row Number(1-9): ";
				cin >> x;
				cout << "Enter the Column Number(1-9): ";
				cin >> y;
				cout << "Enter the Number(1-9): ";
				cin >> enteredNumber;
				if(x == 0 && y == 0 && enteredNumber == 0)
				{
					puzzleLoop = false;
					aSolver.solve();
					aSolver.isFinished(puzzleCompeate);
					if(!puzzleCompeate)
					{
						aSolver.guessBranching(aSolver);
						aSolver.isFinished(puzzleCompeate);
						if(!puzzleCompeate)
						{
							cout << "Solver was not able to complete the puzzle.\n";
						}
					}
					aSolver.printBoard();
				}
				else if( x > 9 || x < 1 || y > 9 || y < 1 || enteredNumber > 9 || enteredNumber < 1)
				{
					cout << "Invalid Entry.\n";
				}
				else
				{
					x = x - 1;
					y = y - 1;
					aSolver.enterNumber(x, y, enteredNumber);
					aSolver.printBoard();
				}
			}
		}
		else
		{
			continueLoop = false;
		}
		aSolver.resetBoard();
	}
	cout << "Good Bye!\n";
	return 0;
}
