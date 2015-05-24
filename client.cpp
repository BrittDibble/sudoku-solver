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
	//easy level
	SudokuSolver game;
	game.enterNumber(0,0,6);
	game.enterNumber(2,0,7);
	game.enterNumber(3,0,4);
	game.enterNumber(6,0,5);
	game.enterNumber(7,0,9);
	game.enterNumber(2,1,9);
	game.enterNumber(3,1,5);
	game.enterNumber(5,1,8); 
	game.enterNumber(1,2,2);
	game.enterNumber(2,2,5);
	game.enterNumber(3,2,7);
	game.enterNumber(7,2,4);
	game.enterNumber(1,3,3);
	game.enterNumber(2,3,8);
	game.enterNumber(4,3,2);
	game.enterNumber(7,3,5);
	game.enterNumber(0,4,2);
	game.enterNumber(1,4,9);
	game.enterNumber(7,4,3);
	game.enterNumber(8,4,1);
	game.enterNumber(1,5,6);
	game.enterNumber(4,5,4);
	game.enterNumber(6,5,7);
	game.enterNumber(7,5,8);
	game.enterNumber(1,6,8);
	game.enterNumber(5,6,7);
	game.enterNumber(6,6,4);
	game.enterNumber(7,6,2);
	game.enterNumber(3,7,2);
	game.enterNumber(5,7,4);
	game.enterNumber(6,7,8);
	game.enterNumber(1,8,7);
	game.enterNumber(2,8,2);
	game.enterNumber(5,8,3);
	game.enterNumber(6,8,1);
	game.enterNumber(8,8,5);
	game.printBoard();
	cout << "\n";
	game.solve();
	game.printBoard();
	//medium level
	//hard level
	//extreme level
	//blank board
	return 0;
}
