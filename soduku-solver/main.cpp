#include <iostream>
#include "SodukuSolver.h"

int main() {
	const int size = 9;

	int board[size][size] = {
		{ 3, 0, 6, 5, 0, 8, 4, 0, 0 },
		{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
		{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
		{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
		{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
		{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
		{ 0, 0, 5, 2, 0, 6, 3, 0, 0 }
	};

	SodukuSolver solver = SodukuSolver(size, (int *)board);
	std::cout << "Soduku Board: \n\n";
	solver.printBoard();
	bool result = solver.solve();
	if (result) {
		std::cout << "---------------------------------------\n";
		std::cout << "Solution: \n\n";
		solver.printBoard();
		std::cout << "---------------------------------------\n";
		return 0;
	}
	std::cout << "No solution exists \n";
}