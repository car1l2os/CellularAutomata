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

	void Grid::SetMatrixAValues();
	void Grid::SetMatrixBValues();


	void GetAValues();
	void GetBValues();
	void SetAValues();
	void SetBValues();

	//Laplace
	float LaplaceA(Cell* currentCell, int index);
	float LaplaceB(Cell* currentCell, int index);


	//Simulation flag
	int simulation_flag = 2;

	//Values
	float dA = 1.0f;
	float dB = 0.5f;
	float FEED = 0.055;
	float KILL = 0.062;


public:
	// Constructor
	Grid(int definition, int* cellSize);
	Grid::Grid(const int* canvasSide); //Per pixel grid	


	//Var
	std::vector<Cell*> matrix; //Ma triz 
	std::vector<float> matrixAux;
	std::vector<float> matrixAuxB;
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
	const int REACTION_DIFFUSION = 2;


	//Simulations
	std::vector<Cell*> GetNeighbours(Cell* cell, int cellIndex);
	std::vector<Cell*> Grid::GetToroidalNeighbours(Cell * cell, int cellIndex);
	void ClearMatrix();
	void ChangeSimulation();
	void GameOfLiveSimulation();
	void WireWorldSimulation();
	void ReactionDifusionSimulation();
	void Simulate();
	void ChangeMatrixToPixel();

	//Geter & seter
	int getSimulationFlag();
	void setSimulationFlag(int value);


};