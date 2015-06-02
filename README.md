# sudoku-solver
A sudoku solver written in C++.

Complier used was g++.

Solver first uses logic to solve the puzzle. If the puzzle is not finished it will then find board cells with only two options that cen be entered. It will then guess a single number and continue to solve, until the puzzle is done. If the puzzle is not compleated, it likly had more than one solution and can not be solved by this solver. If this uncompleated puzzle has only one solution, please create an issue to bring attention to this.
