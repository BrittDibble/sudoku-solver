/* This is the implementation file for the Sudoku Solver
Compiler: g++
Author: Brittany Dibble 
*/
using namespace std;
#include "SudokuSolver.h"

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
		else
		{
			temp = 54 + (i-6)*3;
		}
		if(index == temp | index == 1 +temp| index == 2 + temp
		| index == 9 + temp | index == 10 + temp | index == 11 + temp
		| index == 18 +  temp | index == 19 + temp | index == 20 +temp)
		{
			gameBoard[temp].pencil[number - 1] = 0;
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
void SudokuSolver::printBoardWithPencil()
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
/* Purpose: To be used by solve. It updates the pencil marks in case the only possibility for a certain number is in only one square.
How to Call: provide a boolean that can be changed to true if the function changes anything.
*/
void SudokuSolver::pencilLogicUpdate(bool& somethingWasChanged)
{
	int numberOfTimes;
	int xOffset;
	int rowAndColumnNumber;
	for(int numberBeingChecked = 0; numberBeingChecked < 9; numberBeingChecked++)
	{
		for(int squareBeingChecked = 0; squareBeingChecked < 9; squareBeingChecked++)
		{
			numberOfTimes = 0;
			if(squareBeingChecked < 3)
			{
				xOffset = 0;
			}
			else if(squareBeingChecked < 6)
			{
				xOffset =27;
			}
			else
			{
				xOffset = 54;
			}
			for(int i = 0; i < 3; i++)
			{
				if(gameBoard[xOffset + i + (squareBeingChecked % 3) * 3].pencil[numberBeingChecked] != 0)
				{
					numberOfTimes++;
				}
				if(gameBoard[9 + xOffset + i + (squareBeingChecked % 3) * 3].pencil[numberBeingChecked] != 0)
				{
					numberOfTimes++;
				}
				if(gameBoard[18 + xOffset + i + (squareBeingChecked % 3) * 3].pencil[numberBeingChecked] != 0)
				{
					numberOfTimes++;
				}
			}
			if(numberOfTimes < 4 && numberOfTimes != 0)
			{
				checkAndUpdateSquareColumns(squareBeingChecked, numberBeingChecked, numberOfTimes, somethingWasChanged);
				checkAndUpdateSquareRows(squareBeingChecked, numberBeingChecked, numberOfTimes, somethingWasChanged);
			}
		}
	}
}
/* Purpose: To be used by pencilLogicUpdate. Checks the rows of a certain square for a number.
How to Call: provide the square, the amount a number occurs, the number, and the boolean to be set.
*/
void SudokuSolver::checkAndUpdateSquareRows(int& square, int& number, int& occurence, bool& somethingChanged)
{
	int counter;
	int offset;
	int row;
	int index;
	if(square < 3)
	{
		offset = 0;
		row = 0;
	}
	else if(square < 6)
	{
		offset = 27;
		row = 3;
	}
	else
	{
		offset = 54;
		row = 6;
	}
	for(int rowNumber = 0; rowNumber < 3; rowNumber++)
	{
		counter = 0;
		for(int i = 0; i < 3; i++)
		{
			if(gameBoard[i + offset + (square%3)*3 + rowNumber * 9].pencil[number] !=0)
			{
				counter++;
			}//else nothing
		}
		if(counter > 0 && counter < occurence)
		{
			return;//nothing can be done by this function in this case
		}
		else if(counter == occurence)
		{
			row = row + rowNumber;
			
			for(int i = 0; i < 9; i++)
			{
				index = row * 9 + i;
				if(gameBoard[index].pencil[number] != 0 
				&& (index != (offset + (square%3)*3 + rowNumber * 9) 
				&& index != (1 + offset + (square%3)*3 + rowNumber * 9) 
				&& index != (2 + offset + (square%3)*3 + rowNumber * 9 )))
				{
					somethingChanged = true;
					gameBoard[index].pencil[number] = 0; 
				}
			}
			return;
		}
		//else, loops
	}
	return;
}
/* Purpose: To be used by pencilLogicUpdate. Checks the columns of a certain square for a number.
How to Call: provide the square, the amount a number occurs, the number, and the boolean to be set.
*/
void SudokuSolver::checkAndUpdateSquareColumns(int& square, int& number, int& occurence, bool& somethingChanged)
{
	int counter;
	int offset;
	int column;
	int index;
	if(square < 3)
	{
		offset = 0;
	}
	else if(square < 6)
	{
		offset = 27;
	}
	else
	{
		offset = 54;
	}
	for(int columnNumber = 0; columnNumber < 3; columnNumber++)
	{
		counter = 0;
		for(int i = 0; i < 3; i++)
		{
			if(gameBoard[i * 9 + columnNumber + (square % 3) * 3 + offset].pencil[number] !=0)
			{
				counter++;
			}//else nothing
		}
		if(counter > 0 && counter < occurence)
		{
			return;//nothing can be done by this function in this case
		}
		else if(counter == occurence)
		{
			column = (square % 3) * 3 + columnNumber;
			for(int i = 0; i < 9; i++)
			{
				index = column + i * 9;
				if(gameBoard[index].pencil[number] != 0
				&& index != offset + column
				&& index != 9 + offset + column
				&& index != 18 + offset + column)
				{
					somethingChanged = true;
					gameBoard[index].pencil[number] = 0; 
				}
			}
			return;
		}
		//else, loops
	}
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
	int i;
	bool temp = true;
	while(temp)
	{
		temp = false;
		onlyOptionCheck(temp);
		for(i = 0; i < 9; i++)
		{
			rowOnlyOptionCheck(temp, i);
			columnOnlyOptionCheck(temp, i);
			squareOnlyOptionCheck(temp, i);
		}
		pencilLogicUpdate(temp);
		twinTester(temp);
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
/* Purpose: To be used by solve. Checks each row to see if only one location is 
possible for a certain number. Changes the given boolean to true if this function 
enters any numbers onto the game board.
How to Call: Provide a boolean and the row of the number being checked.
*/
void SudokuSolver::rowOnlyOptionCheck(bool& aBool, int row)
{
	int numberOfTimesNumberIsInRow;
	for(int numberBeingChecked = 0; numberBeingChecked < 9; numberBeingChecked++)
	{
		numberOfTimesNumberIsInRow = 0;
		for(int i = 0; i < 9; i++)
		{
			if(gameBoard[i + row * 9].pencil[numberBeingChecked] != 0)
			{
				numberOfTimesNumberIsInRow ++;
			}
		}
		if(numberOfTimesNumberIsInRow == 1)
		{
			aBool = true;
			for(int i = 0; i < 9; i++)
			{
				if(gameBoard[i + row * 9].pencil[numberBeingChecked] != 0)
				{
					enterNumber(row, i, numberBeingChecked + 1);
				}
			}
		}
	}
	return;
}
/* Purpose: To be used by solve. Checks each column to see if only one location is possible for a certain number. 
Changes a given boolean to true if this function enters any numbers into the board.
How to Call: Provide a boolean and the column number to be checked.
*/	
void SudokuSolver::columnOnlyOptionCheck(bool& somethingWasChanged, int column)
{
	int numberOfTimesNumberIsInColumn;
	for(int numberBeingChecked = 0; numberBeingChecked < 9; numberBeingChecked++)
	{
		numberOfTimesNumberIsInColumn = 0;
		for(int i = 0; i < 9; i++)
		{
			if(gameBoard[i * 9 + column].pencil[numberBeingChecked] != 0)
			{
				numberOfTimesNumberIsInColumn ++;
			}
		}
		if(numberOfTimesNumberIsInColumn == 1)
		{
			somethingWasChanged = true;
			for(int i = 0; i < 9; i++)
			{
				if(gameBoard[i * 9 + column].pencil[numberBeingChecked] != 0)
				{
					enterNumber(i, column, numberBeingChecked + 1);
				}
			}
		}
	}
	return;
}
/* Purpose: To be used by solve. Checks each square section of the sudoku board to see if only one location can take a certain number. 
Changes a given boolean to true if the function inputs any numbers onto the board.
How to Call: Give a boolean and the number of the square that needs to be checked.
*/
void SudokuSolver::squareOnlyOptionCheck(bool& somethingWasChanged, int square)
{
	int numberOfTimesNumberIsInSquare;
	int offset;
	int index;
	if(square < 3)
	{
		offset = 0;
	}
	else if(square < 6)
	{
		offset = 27;
	}
	else
	{
		offset = 54;
	}
	for(int numberBeingChecked = 0; numberBeingChecked < 9; numberBeingChecked++)
	{
		numberOfTimesNumberIsInSquare = 0;
		for(int i = 0; i < 3; i++)
		{
			if(gameBoard[offset + 3*(square%3) + i].pencil[numberBeingChecked] != 0)
			{
				numberOfTimesNumberIsInSquare ++;
			}
			if(gameBoard[9 + offset + 3*(square%3) + i].pencil[numberBeingChecked] != 0)
			{
				numberOfTimesNumberIsInSquare ++;
			}
			if(gameBoard[18 + offset + 3*(square%3) + i].pencil[numberBeingChecked] != 0)
			{
				numberOfTimesNumberIsInSquare ++;
			}
		}
		if(numberOfTimesNumberIsInSquare == 1)
		{
			somethingWasChanged = true;
			for(int i = 0; i < 3; i++)
			{
				if(gameBoard[offset + 3*(square%3) + i].pencil[numberBeingChecked] != 0)
				{
					index = offset + 3*(square%3) + i;
					enterNumber((index/9),(index-((index/9)*9)),numberBeingChecked + 1);
					somethingWasChanged = true;
				}
				if(gameBoard[9 + offset + 3*(square%3) + i].pencil[numberBeingChecked] != 0)
				{
					index = 9 + offset + 3*(square%3) + i;
					enterNumber((index/9),(index-((index/9)*9)),numberBeingChecked + 1);
					somethingWasChanged = true;
				}
				if(gameBoard[18 + offset + 3*(square%3) + i].pencil[numberBeingChecked] != 0)
				{
					index = 18 + offset + 3*(square%3) + i;
					enterNumber((index/9),(index-((index/9)*9)),numberBeingChecked + 1);
					somethingWasChanged = true;
				}
			}
		}
	}
	return;
}
/* Purpose: To be used by solve. Checks for twins in all of the rows, columns, and squares.
How to Call: Provide a boolean to be set to true if the function can change anything.
*/
void SudokuSolver::twinTester(bool& wasSomethingChanged)
{
	for(int i = 0; i < 9; i++)
	{
		twinTesterRow(wasSomethingChanged, i);
		twinTesterColumn(wasSomethingChanged, i);
		twinTesterSquare(wasSomethingChanged, i);
	}
	return;
}
/* Purpose: To be used by solve. Checks for twins in the row of the number provided.
How to Call: Provide a boolean to be set to true if the function can change anything and an int for the row being checked.
*/
void SudokuSolver::twinTesterRow(bool& wasSomethingChanged, int row)//this mess needs to be redone
{
	int counter = 0;//temporary counter.
	for(int i = 0; i < 9; i++)//checks to see if more that 2 squares are open.
	{
		if(gameBoard[i + row * 9].elem == 0)
		{
			counter ++;
		}
	}
	if(counter > 2)
	{
		for(int i = 0; i < 8; i++)//finds if any of the places in the row only have two options.
		{
			counter = 0;
			for(int numberBeingChecked = 0; numberBeingChecked < 9; numberBeingChecked++)
			{
				if(gameBoard[i + row * 9].pencil[numberBeingChecked] != 0)
				{
					counter ++;
				}
			}
			if(counter == 2)//finds out if any other square share the same two.
			{
				for(int restOfTheRow = i + 1; restOfTheRow < 9; restOfTheRow++)
				{
					if(compairCells(gameBoard[i + row * 9], gameBoard[restOfTheRow + row * 9]))
					{
						wasSomethingChanged = true;
						for(int number = 0; number < 9; number++)
						{
							if(gameBoard[i + row * 9].pencil[number] != 0)
							{
								for(int rowCellBeingUpdated = 0; rowCellBeingUpdated < 9; rowCellBeingUpdated++)
								{
									if(rowCellBeingUpdated + row * 9 != i + row * 9 && rowCellBeingUpdated + row * 9 != restOfTheRow + row * 9)
									{
										gameBoard[rowCellBeingUpdated + row * 9].pencil[number] = 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return;
}
/* Purpose: To be used by solve. Checks for twins in the column of the number provided.
How to Call: Provide a boolean to be set to true if the function can change anything and an int for the column being checked.
*/
void SudokuSolver::twinTesterColumn(bool& wasSomethingChanged, int column)
{
	int counter = 0;//temporary counter.
	for(int i = 0; i < 9; i++)//checks to see if more that 2 squares are open.
	{
		if(gameBoard[i * 9 + column].elem == 0)
		{
			counter ++;
		}
	}
	if(counter > 2)
	{
		for(int i = 0; i < 8; i++)//finds if any of the places in the column only have two options.
		{
			counter = 0;
			for(int numberBeingChecked = 0; numberBeingChecked < 9; numberBeingChecked++)
			{
				if(gameBoard[i * 9 + column].pencil[numberBeingChecked] != 0)
				{
					counter ++;
				}
			}
			if(counter == 2)//finds out if any other square share the same two.
			{
				for(int restOfTheColumn = i + 1; restOfTheColumn < 9; restOfTheColumn++)
				{
					if(compairCells(gameBoard[i * 9 + column], gameBoard[restOfTheColumn * 9 + column]))
					{
						wasSomethingChanged = true;
						for(int number = 0; number < 9; number++)
						{
							if(gameBoard[i * 9 + column].pencil[number] != 0)
							{
								for(int columnCellBeingUpdated = 0; columnCellBeingUpdated < 9; columnCellBeingUpdated++)
								{
									if(columnCellBeingUpdated * 9 + column != i * 9 + column && columnCellBeingUpdated * 9 + column != restOfTheColumn * 9 + column)
									{
										gameBoard[columnCellBeingUpdated * 9 + column].pencil[number] = 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return;
}
/* Purpose: To be used by solve. Checks for twins in the square of the number provided.
How to Call: Provide a boolean to be set to true if the function can change anything and an int for the square being checked.
*/
void SudokuSolver::twinTesterSquare(bool& wasSomethingChanged, int square)
{
	int counter = 0;//temporary counter.
	int offset;
	if(square < 3)
	{
		offset = 0;
	}
	else if(square < 6)
	{
		offset = 27;
	}
	else
	{
		offset = 54;
	}
	for(int i = 0; i < 9; i++)//checks to see if more that 2 squares are open.
	{
		if(gameBoard[offset + (square % 3) * 3 + (i / 3) * 9 + i % 3].elem == 0)
		{
			counter ++;
		}
	}
	if(counter > 2)
	{
		for(int i = 0; i < 8; i++)//finds if any of the places in the square only have two options.
		{
			counter = 0;
			for(int numberBeingChecked = 0; numberBeingChecked < 9; numberBeingChecked++)
			{
				if(gameBoard[offset + (square % 3) * 3 + (i / 3) * 9 + i % 3].pencil[numberBeingChecked] != 0)
				{
					counter ++;
				}
			}
			if(counter == 2)//finds out if any other square share the same two.
			{
				for(int restOfTheSquare = i + 1; restOfTheSquare < 9; restOfTheSquare++)
				{
					if(compairCells(gameBoard[offset + (square % 3) * 3 + (i / 3) * 9 + i % 3], gameBoard[offset + (square % 3) * 3 + (restOfTheSquare / 3) * 9 + restOfTheSquare % 3]))
					{
						wasSomethingChanged = true;
						for(int number = 0; number < 9; number++)
						{
							if(gameBoard[offset + (square % 3) * 3 + (i / 3) * 9 + i % 3].pencil[number] != 0)
							{
								for(int squareCellBeingUpdated = 0; squareCellBeingUpdated < 9; squareCellBeingUpdated++)
								{
									if(offset + (square % 3) * 3 + (squareCellBeingUpdated / 3) * 9 + squareCellBeingUpdated % 3 != offset + (square % 3) * 3 + (i / 3) * 9 + i % 3 && offset + (square % 3) * 3 + (squareCellBeingUpdated / 3) * 9 + squareCellBeingUpdated % 3 != offset + (square % 3) * 3 + (restOfTheSquare / 3) * 9 + restOfTheSquare % 3)
									{
										gameBoard[offset + (square % 3) * 3 + (squareCellBeingUpdated / 3) * 9 + squareCellBeingUpdated % 3].pencil[number] = 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return;
}
/* Purpose: Checks the element of the cells and each of the pencil marks. If they are not the same it returns false.
This method returns true otherwise.
How to Call: Give two cells to be compared.
*/
bool SudokuSolver::compairCells(Cell fristCell, Cell secondCell)
{
	if(fristCell.elem != secondCell.elem)
	{
		return false;
	}
	for(int i = 0; i < 9; i++)
	{
		if(fristCell.pencil[i] != secondCell.pencil[i])
		{
			return false;
		}
	}
	return true;
}

void SudokuSolver::guessBranching(SudokuSolver& aSolver)
{
	SudokuSolver tempSolver = aSolver;
	int counter;
	bool checkedIfDone;
	for(int i = 0; i < 81; i++)//goes though the entire array.
	{
		if(tempSolver.gameBoard[i].elem == 0)
		{
			counter = 0;
			for(int number = 0; number < 9;  number++)
			{
				if(tempSolver.gameBoard[i].pencil[number] != 0)
				{
					counter++;
				}
			}
			if(counter == 2)
			{
				for(int guessedNumber = 0; guessedNumber < 9; guessedNumber++)
				{
					if(tempSolver.gameBoard[i].pencil[guessedNumber] != 0)
					{
						tempSolver.enterNumber(i/9,i%9, guessedNumber+1);
						tempSolver.solve();
						tempSolver.isFinished(checkedIfDone);
						if(checkedIfDone)
						{
							aSolver = tempSolver;
							return;
						}
						else
						{
							tempSolver = aSolver;
						}
					}
				}
			}
		}
	}
}

void SudokuSolver::resetBoard()
{
	for(int i = 0; i < 81; i++)
	{
		gameBoard[i].elem = 0;
		for(int number = 0; number < 9; number++)
		{
			gameBoard[i].pencil[number] = number + 1;
		}
	}
}

void SudokuSolver::printBoard()
{
	string aString;
	aString = "=============\n";
	for(int i = 0; i < 81; i++)
	{
		if(i == 0 || i == 27 || i == 54)
		{
			cout << aString;
		}
		if(i%3 == 0)
		{
			cout << "|";
		}
		cout << gameBoard[i].elem;
		if(i%9 == 8)
		{
			cout << "|\n";
		}
	}
	cout << aString;
}
