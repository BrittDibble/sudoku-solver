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
	cout << "Easy\n";
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
	cout << "medium\n";
	SudokuSolver game1;
	game1.enterNumber(5,0,2);
	game1.enterNumber(7,0,9);
	game1.enterNumber(2,1,8);
	game1.enterNumber(4,1,5);
	game1.enterNumber(5,1,4);
	game1.enterNumber(0,2,1);
	game1.enterNumber(6,2,7);
	game1.enterNumber(1,3,6);
	game1.enterNumber(6,3,1);
	game1.enterNumber(7,3,3);
	game1.enterNumber(8,3,9);
	game1.enterNumber(0,4,8);
	game1.enterNumber(3,4,6);
	game1.enterNumber(5,4,1);
	game1.enterNumber(8,4,5);
	game1.enterNumber(0,5,9);
	game1.enterNumber(1,5,1);
	game1.enterNumber(2,5,4);
	game1.enterNumber(7,5,2);
	game1.enterNumber(2,6,6);
	game1.enterNumber(8,6,7);
	game1.enterNumber(3,7,2);
	game1.enterNumber(4,7,4);
	game1.enterNumber(6,7,6);
	game1.enterNumber(1,8,4);
	game1.enterNumber(3,8,5);
	game1.printBoard();
	cout << "\n";
	game1.solve();
	game1.printBoard();
	//hard level
	cout << "hard\n";
	SudokuSolver game2;
	game2.enterNumber(0,0,2);
	game2.enterNumber(4,0,6);
	game2.enterNumber(1,1,6);
	game2.enterNumber(3,1,3);
	game2.enterNumber(8,1,8);
	game2.enterNumber(5,2,7);
	game2.enterNumber(6,2,1);
	game2.enterNumber(0,3,1);
	game2.enterNumber(2,3,4);
	game2.enterNumber(3,3,8);
	game2.enterNumber(7,3,6);
	game2.enterNumber(2,4,7);
	game2.enterNumber(3,4,4);
	game2.enterNumber(5,4,2);
	game2.enterNumber(6,4,9);
	game2.enterNumber(1,5,8);
	game2.enterNumber(5,5,1);
	game2.enterNumber(6,5,5);
	game2.enterNumber(8,5,4);
	game2.enterNumber(2,6,6);
	game2.enterNumber(3,6,1);
	game2.enterNumber(0,7,8);
	game2.enterNumber(5,7,5);
	game2.enterNumber(7,7,9);
	game2.enterNumber(4,8,8);
	game2.enterNumber(8,8,5);
	game2.printBoard();
	cout << "\n";
	game2.solve();
	game2.printBoard();
	/*//extreme level
	cout << "extreme\n";
	SudokuSolver game3;
	game3.enterNumber(,,);
	game3.printBoard();
	cout << "\n";
	game3.solve();
	game3.printBoard(); */
	return 0;
}
