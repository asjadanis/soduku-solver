#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>

class SodukuSolver
{
private: 
	int size;
	int min, max;
	int row, col;
	int** board;
public:
	SodukuSolver(int, int);
	SodukuSolver(int, int*);
	void initializeBoard(int, int);
	void initializeBoard(int, int*);
	bool solve();
	bool isMoveLeft();
	bool isValidMove(int, int, int);
	void printBoard();
	int randomNumberGenerator(int, int);
	void randomIndexGenerator(int, int, int*&, int*&);
	virtual ~SodukuSolver();
};

