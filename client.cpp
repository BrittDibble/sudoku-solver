/* This is the client file for the Sudoku Solver
Compiler: g++
Author: Brittany Dibble 
This client file prints out the empty gameBoard.
*/
using namespace std;
#include "SudokuSolver.h"
#include <iostream>
int main()
{
	bool cont = true; //continue
	
	int counter = 0;
	int x;
	int y;
	int number;
	
	SudokuSolver game;
	
	while(cont && counter < 100)
	{
		game.printBoard();//prints out the board
		cout << "Please enter the x, y, and the number in that order and pressing enter in-between.\n";
		cout << "Enter 0 for the last to exit.\n";
		cin >> x;
		cin >> y;
		cin >> number;
		x--;
		y--;
		game.enterNumber(x,y,number);
		if(number == 0)
		{
			cont = false;
		}
		counter ++;
	}
}
