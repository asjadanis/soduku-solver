#include "SodukuSolver.h"



SodukuSolver::SodukuSolver(int size, int emptyPos){
	if (size > 0) {
		srand(time(0));
		initializeBoard(size, emptyPos);
	}
	else {
		std::cout << "Invalid Input \n";
	}
}

SodukuSolver::SodukuSolver(int size, int* board){
	if (size > 0) {
		this->size = size;
		this->row = -1;
		this->col = -1;
		initializeBoard(size, board);
	}
}

void SodukuSolver::initializeBoard(int size, int* board) {
	this->board = new int* [size];
	for (int i = 0; i < size; i++) {
		this->board[i] = new int [size];
	}

	for (int i = 0, count = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			this->board[i][j] = *((board + count));
			count++;
		}
	}
}

bool SodukuSolver::solve() {
	int row	, col;
	if (!isMoveLeft()) {
		return true;
	}
	row = this->row;
	col = this->col;

	for (int i = 1; i <= size; i++) {
		if (isValidMove(i, row, col)) {
			board[row][col] = i;
			if (solve()) {
				return true;
			}
			board[row][col] = 0;
		}
	}
	return false;
}

bool SodukuSolver::isMoveLeft() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == 0) {
				this->row = i;
				this->col = j;
				return true;
			}
		}
	}
	return false;
}

bool SodukuSolver::isValidMove(int num, int row, int col) {
	for (int i = 0; i < size; i++) {
		if (board[row][i] == num || board[i][col] == num) {
			return false;
		}
	}
	
	row = row - row % 3;   // get the starting row of a 3x3 subgrid with index in bound hence the modulus
	col = col - col % 3;   // get the starting col of a 3x3 subgrid with index in bound hence the modulus

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i + row][j + col] == num) {
				return false;
			}
		}
	}

	return true;
}

void SodukuSolver::initializeBoard(int size, int emptyPos) {
	this->size = size;
	this->min = 1;
	this->max = size;
	board = new int*[size];
	for (int i = 0; i < size; i++) {
		board[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			board[i][j] = randomNumberGenerator(1,9);
		}
	}

	int* tempRow = NULL;
	int* tempCol = NULL;
	for (int i = 0; i < emptyPos; i++) {
		randomIndexGenerator(min, max, tempRow, tempCol);
		board[*tempRow][*tempCol] = 0;
		std::cout << *tempRow << *tempCol << std::endl;
	}
	
}
	

int SodukuSolver::randomNumberGenerator(int min, int max) {
	return ((rand() % max) + min);
}

void SodukuSolver::randomIndexGenerator(int min, int max, int*& row, int*& col) {
	int tempRow = randomNumberGenerator(min, max);
	int tempCol = randomNumberGenerator(min, max);
	row = &tempRow;
	col = &tempCol;
}

void SodukuSolver::printBoard() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << board[i][j] << "  ";
		}
		std::cout << "\n";
	}
	std::cout << "\n\n";
}

SodukuSolver::~SodukuSolver(){
}
