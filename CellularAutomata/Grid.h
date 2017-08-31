#pragma once
#include <vector>
#include "Cell.h"

class Grid {
private:
	int definition;
	

public:
	//Constructor
	Grid(int definition, int* cellSize);

	std::vector<Cell*> matrix; //Matriz 

	void clickOn(int x, int y);
	void mouseOver(int x, int y);
};