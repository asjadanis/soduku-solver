# soduku-solver

Solving [Soduku](https://en.wikipedia.org/wiki/Sudoku) using a [Backtracking algorithm](https://en.wikipedia.org/wiki/Backtracking)

# Approach

1. Find an empty position in the board.
2. If no empty position on board return true.
3. Place a number (1-9) at the empty position validating all the constraints.
   - If no constraints are voilated recursively fill in the rest of the grid.
   - If all grid poisitions are filled, return success. Puzzle Solved.
   - If it doesn't leads to a solution, then remove the digit from this position, backtrack and go to previous step and try the next number.
