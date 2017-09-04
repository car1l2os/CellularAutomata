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
	Grid(int definition, int* cellSize, std::vector<float> values); //Para crear una grid ya "existente" 

	//Var
	std::vector<Cell*> matrix; //Matriz 
	Cell* highlightedCell;

	//Mouse
	void clickOn(int x, int y);
	void mouseOver(int x, int y);
	
	//Save/load
	std::string saveState();
	Grid* chargeState(std::string inString, int* cellSizeDirection);

	//Statics
	int const POS_VECTOR_DEFINITION = 0;
	int const POS_VECTOR_CELLSIZE = 1;
	int const POS_VECTOR_VALUES = 2;


	//Simulations
	std::vector<Cell*> getNeighbours(Cell* cell, int cellIndex);
	void GameOfLiveSimulation();
};