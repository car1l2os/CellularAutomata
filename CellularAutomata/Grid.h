#pragma once
#include <vector>
#include "Cell.h"
#include <string>

class Grid {
private:
	int definition;
	int* cellSize;
	Cell* identifyCellByPos(int x, int y);
	void GetMatrixValues();
	void SetMatrixValues();

	//Simulation flag
	int simulation_flag = 0;





public:
	//Constructor
	Grid(int definition, int* cellSize);

	//Var
	std::vector<Cell*> matrix; //Ma triz 
	std::vector<float> matrixAux;
	Cell* highlightedCell;

	//Mouse
	void clickOn(int x, int y);
	void mouseOver(int x, int y);

	//Save/load
	std::string saveState();
	void chargeState(std::string inString, int* cellSizeDirection);

	//Statics
	const int  POS_VECTOR_DEFINITION = 0;
	const int  POS_VECTOR_CELLSIZE = 1;
	const int  POS_VECTOR_VALUES = 2;

	const int GAME_OF_LIVE = 0;
	const int WIRE_WORLD = 1;


	//Simulations
	std::vector<Cell*> GetNeighbours(Cell* cell, int cellIndex);
	void ClearMatrix();
	void ChangeSimulation();
	void GameOfLiveSimulation();
	void WireWorldSimulation();
	void Simulate();

	//Geter & seter
	int getSimulationFlag();
	void setSimulationFlag(int value);


};