#pragma once
#include <vector>
#include "Cell.h"
#include <string>

class Grid {
private:
	int definition;
	int* cellSize;
	Cell* identifyCellByPos(int x, int y);


public:
	//Constructor
	Grid(int definition, int* cellSize);

	std::vector<Cell*> matrix; //Matriz 

	void clickOn(int x, int y);
	void mouseOver(int x, int y);
};