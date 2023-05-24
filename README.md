# Sudoku-solver
designed a sudoku solver in C++ using backtracking

The code aims to solve a Sudoku puzzle using a recursive backtracking algorithm

Sudoku is a number placement puzzle where you fill a 9x9 grid with digits from 1 to 9, ensuring each row, column, and 3x3 subgrid contains all digits without repetition.

The main program reads the initial Sudoku grid from the user, calls the solver function, and prints the solved grid if a solution exists.

The "sudoku_solver" function recursively solves the puzzle by iterating over each cell, trying values, and backtracking if a solution is not found.

The "tests_passed" function checks if a value can be placed in a position without violating Sudoku rules.
