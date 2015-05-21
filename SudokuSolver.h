/* This is the header file for the Sudoku Solver
Compiler: g++
Author: Brittany Dibble 
*/

struct Cell
{
  int elem;
  int pencil[9];
}; 

class SudokuSolver
{
	private:
	Cell gameBoard[3][3];
	
	/* Purpose: To be used by printBoard. Given the row number it prints out that row of the board.
	How to Call: Give the integer of the row to be printed, starting from 1 and going to 9.
	*/
	void printRow(int);
	/* Purpose: To be used by printRow. Prints out a small section of the row based on the column entered.
	How to Call: Give the integer for the row and the column to be printed out.
	*/
	void printRowCol(int, int);

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
	void printBoard();
};
