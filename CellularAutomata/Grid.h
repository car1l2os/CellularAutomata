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

};