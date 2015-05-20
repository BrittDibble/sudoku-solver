
struct Cell
{
  int elem;
  int pencil[9];
}; 
class SudokuSolver
{
	private:
	Cell gameBoard[9][9];

	public:
	
	SudokuSolver();
	~SudokuSolver();
	
	void enterNumber(int, int, int);
	
	void printBoard();
};
