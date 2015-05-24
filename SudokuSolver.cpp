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

/* Purpose: To be used by enterNumber. Updates the pencil marks in the square that enterNumber 
belongs to.
How to Call: Provide the x and y cords and then the number.
*/
void SudokuSolver::updateSquare(int& x, int& y, int& number)
{
	int index = x * 9 + y;
	int temp;
	for(int i = 0; i < 9; i++)
	{
		if(i < 3)
		{
			temp = i * 3;
		}
		else if (i < 6)
		{
			temp = 27 + (i-3)*3;
		}
		else if(i < 9)
		{
			temp = 54 + (i-3)*3;
		}
		if(index == 0 + temp | index == 1 +temp| index == 2 + temp
		| index == 9 + temp | index == 10 + temp | index == 11 + temp
		| index == 18 +  temp | index == 19 + temp | index == 20 +temp)
		{
			gameBoard[0 + temp].pencil[number - 1] = 0;
			gameBoard[1 + temp].pencil[number - 1] = 0;
			gameBoard[2 + temp].pencil[number - 1] = 0;
			gameBoard[9 + temp].pencil[number - 1] = 0;
			gameBoard[10 + temp].pencil[number - 1] = 0;
			gameBoard[11 + temp].pencil[number - 1] = 0;
			gameBoard[18 + temp].pencil[number - 1] = 0;
			gameBoard[19 + temp].pencil[number - 1] = 0;
			gameBoard[20 + temp].pencil[number - 1] = 0;
			return;
		}
	}
	return;
}
/* Purpose: Enters a number into the gameBoard given the row and column for the number. Will make a check
that placing the number is legal and removed pencil marks in the square, row, and column.
How to Call:Give the row, column  and the number.
*/
void SudokuSolver::enterNumber(int x, int y, int number)
{
	int index = x * 9 + y;
	if(x > 9 || y > 9 || x < 0 || y < 0 || gameBoard[index].pencil[number - 1] != number)//checks that the number can be placed here.
	{
		cout << "Invalid Location.\n";
		return;
	}
	gameBoard[index].elem = number;
	for(int i = 0; i < 9; i++)//sets all of the pencil marks in the location to 0 so no other numbers are placed.
	{
		gameBoard[index].pencil[i] = 0;
	}
	for(int i = 0; i < 9; i++)//removes the pencil marks on the row
	{
		gameBoard[x*9 + i].pencil[number - 1] = 0;
	}
	for(int i = 0; i < 9; i++)//removes the pencil marks on the column
	{
		gameBoard[i*9 + y].pencil[number - 1] = 0;
	}
	updateSquare(x, y, number);
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
		if(rowNumber % 3 == 0)
		{
			if(gameBoard[row*9 + i].elem != 0)
			{
				cout << "   |";
			}
			else
			{
				cout << gameBoard[row*9 + i].pencil[0]
				<< gameBoard[row*9 + i].pencil[1]
				<< gameBoard[row*9 + i].pencil[2]
				<< "|";
			}		
		}
		else if(rowNumber % 3 == 1)
		{
			if(gameBoard[row*9 + i].elem != 0)
			{
				cout << " " << gameBoard[row*9 + i].elem << " |";
			}
			else
			{
				cout << gameBoard[row*9 + i].pencil[3]
				<< gameBoard[row*9 + i].pencil[4]
				<< gameBoard[row*9 + i].pencil[5]
				<< "|";
			}
		}
		else if(rowNumber % 3 == 2)
		{
			if(gameBoard[row*9 + i].elem != 0)
			{
				cout << "   |";
			}
			else
			{
				cout << gameBoard[row*9 + i].pencil[6]
				<< gameBoard[row*9 + i].pencil[7]
				<< gameBoard[row*9 + i].pencil[8]
				<< "|";
			}
		}
	}
	cout << "|=\n";
	return;
}
/* Purpose: Prints out the gameBoard and the pencil marks in a readable format. 
*/
void SudokuSolver::printBoard()
{
	string aString = "=||=====================================||=\n";
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
	}
	cout << aString;
	cout << aString;
	return;
}
/* Purpose: Sets the entered bool to true if there are no 0 elements in the array. Sets to false otherwise.
How to Call: Provide a bool to be set.
*/
void SudokuSolver::isFinished(bool& aBool)
{
	for(int i = 0; i < 81; i++)
	{
		if(gameBoard[i].elem == 0)
		{
			aBool = false;
			return;
		}
	}
	aBool = true;
	return;
}
/* Purpose: Solve the current sudoku board.
*/
void SudokuSolver::solve()
{
	int counter = 0;
	bool temp = true;
	while(temp)
	{
		onlyOptionCheck(temp);
	}
	isFinished(temp);
	if(!temp)
	{
		cout << "Solve was unable to complete the puzzle.\n";
	}
	return;
}
/* Purpose: To be used by solve. Checks each element of the gameBoard one at a time to see if it
only has one valid pencil mark. Returns true if it makes any changes.
How to Call: Provide a boolean to be set to true if something is changed by this.
*/
void SudokuSolver::onlyOptionCheck(bool& aBool)
{
	int temp;
	aBool = false;
	for(int i = 0; i < 81; i++)
	{
		temp = 0;
		if(gameBoard[i].elem == 0)
		{
			for(int j = 0; j < 9; j++)
			{
				if(gameBoard[i].pencil[j] != 0)
				{
					temp++;
				}
			}
			if(temp == 1)
			{
				for(int j = 0; j < 9; j++)
				{
					if(gameBoard[i].pencil[j] != 0)
					{
						enterNumber((i/9),(i-((i/9)*9)),(j+1));
						aBool = true;
					}
				}	
			}
		}
		
	}
	return;
}
