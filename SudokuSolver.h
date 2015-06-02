/* This is the header file for the Sudoku Solver
Compiler: g++
Author: Brittany Dibble 
*/
#include <iostream>
#include <string>
struct Cell
{
  int elem;
  int pencil[9];
}; 

class SudokuSolver
{
	private:
	Cell gameBoard[81];
	/* Purpose: To be used by the printBoard. Prints out the row of the board including pencil marks.
	How to Call: Provide the row number from 0 to 26.
	*/
	void printRow(int);
	/* Purpose: To be used by enterNumber. Updates the pencil marks in the square that enterNumber 
	belongs to.
	How to Call: Provide the x and y cords and then the number.
	*/
	void updateSquare(int&, int&, int&);
	/* Purpose: To be used by solve. Checks each element of the gameBoard one at a time to see if it
	only has one valid pencil mark. Returns true if it makes any changes.
	How to Call: Provide a boolean to be set to true if something is changed by this.
	*/
	void onlyOptionCheck(bool&);
	/* Purpose: To be used by solve. Checks each row to see if only one location is 
	possible for a certain number. Changes the given boolean to true if this function 
	enters any numbers onto the game board.
	How to Call: Provide a boolean and the row of the number being checked.
	*/
	void rowOnlyOptionCheck(bool&, int);
	/* Purpose: To be used by solve. Checks each column to see if only one location is possible for a certain number. 
	Changes a given boolean to true if this function enters any numbers into the board.
	How to Call: Provide a boolean and the column number to be checked.
	*/
	void columnOnlyOptionCheck(bool&, int);
	/* Purpose: To be used by solve. Checks each square section of the sudoku board to see if only one location can take a certain number. 
	Changes a given boolean to true if the function inputs any numbers onto the board.
	How to Call: Give a boolean and the number of the square that needs to be checked.
	*/
	void squareOnlyOptionCheck(bool&, int);
	/* Purpose: To be used by solve. It updates the pencil marks in case the only possibility for a certain number is in only one square.
	How to Call: provide a boolean that can be changed to true if the function changes anything.
	*/
	void pencilLogicUpdate(bool&);
	/* Purpose: To be used by pencilLogicUpdate. Checks the rows of a certain square for a number.
	How to Call: provide the square, the amount a number occurs, the number, and the boolean to be set.
	*/
	void checkAndUpdateSquareRows(int&, int&, int&, bool&);
	/* Purpose: To be used by pencilLogicUpdate. Checks the columns of a certain square for a number.
	How to Call: provide the square, the amount a number occurs, the number, and the boolean to be set.
	*/
	void checkAndUpdateSquareColumns(int&, int&, int&, bool&);
	/* Purpose: To be used by solve. Checks for twins in all of the rows, columns, and squares.
	How to Call: Provide a boolean to be set to true if the function can change anything.
	*/
	void twinTester(bool&);
	/* Purpose: To be used by solve. Checks for twins in the row of the number provided.
	How to Call: Provide a boolean to be set to true if the function can change anything and an int for the row being checked.
	*/
	void twinTesterRow(bool&, int);
	/* Purpose: To be used by solve. Checks for twins in the column of the number provided.
	How to Call: Provide a boolean to be set to true if the function can change anything and an int for the column being checked.
	*/
	void twinTesterColumn(bool&, int);
	/* Purpose: To be used by solve. Checks for twins in the square of the number provided.
	How to Call: Provide a boolean to be set to true if the function can change anything and an int for the square being checked.
	*/
	void twinTesterSquare(bool&, int);
	public:
	
	SudokuSolver(); //sets each element of the gameBoard to 0 and fills the pencil array with 1-9.
	~SudokuSolver(); //does nothing
	/* Purpose: Enters a number into the gameBoard given the row and column for the number. Will make a check
	that placing the number is legal and removed pencil marks in the square, row, and column.
	How to Call:Give the row, column  and the number.
	*/
	void enterNumber(int, int, int);
	/* Purpose: Prints out the gameBoard and the pencil marks in a readable format. 
	*/
	void printBoardWithPencil();
	/* Purpose: Solve the current sudoku board.
	*/
	void solve();
	/* Purpose: Sets the entered bool to true if there are no 0 elements in the array. Sets to false otherwise.
	How to Call: Provide a bool to be set.
	*/
	void isFinished(bool&);
	/* Purpose: Checks the element of the cells and each of the pencil marks. If they are not the same it returns false.
	This method returns true otherwise.
	How to Call: Give two cells to be compared.
	*/
	bool compairCells(Cell, Cell);
	
	void guessBranching(SudokuSolver&);
	
	void resetBoard();
	
	void printBoard();
};
