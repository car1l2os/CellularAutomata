#pragma once
#include <vector>
#include "Cell.h"
#include <string>

class Grid {
private:
	int definition;
	int* cellSize;
	Cell* identifyCellByPos(int x, int y);
	std::vector<float> GetMatrixValues();
	void SetMatrixValues(std::vector<float> values);

	//Simulation flag
	int simulation_flag = 0;
	const int GAME_OF_LIVE = 0;
	const int WIRE_WORLD = 1;




public:
	//Constructor
	Grid(int definition, int* cellSize);

	//Var
	std::vector<Cell*> matrix; //Matriz 
	Cell* highlightedCell;

	//Mouse
	void clickOn(int x, int y);
	void mouseOver(int x, int y);

	//Save/load
	std::string saveState();
	void chargeState(std::string inString, int* cellSizeDirection);

	//Statics
	int const POS_VECTOR_DEFINITION = 0;
	int const POS_VECTOR_CELLSIZE = 1;
	int const POS_VECTOR_VALUES = 2;


	//Simulations
	std::vector<Cell*> GetNeighbours(Cell* cell, int cellIndex);
	void GameOfLiveSimulation();

	//Geter & seter
	int getSimulationFlag();
	void setSimulationFlag(int value);


};