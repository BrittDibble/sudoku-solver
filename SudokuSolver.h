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
	
	void rowOnlyOptionCheck(bool&, int);
	
	void columnOnlyOptionCheck(bool&, int);
	
	void squareOnlyOptionCheck(bool&, int);
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
	/* Purpose: Solve the current sudoku board.
	*/
	void solve();
	/* Purpose: Sets the entered bool to true if there are no 0 elements in the array. Sets to false otherwise.
	How to Call: Provide a bool to be set.
	*/
	void isFinished(bool&);
};
