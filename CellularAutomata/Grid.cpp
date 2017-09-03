#include "Grid.h"
#include <iostream>
#include <SDL.h>



/*Esta clase se va a encargar de comprobar
vecinos y otros metodos dentro de la matriz
que quedaran enmascarados */


Grid::Grid(int definition, int* cellSize)
{
	this->definition = definition;
	this->cellSize = cellSize;

	for (int k = 0, i = 0, j = 0;k < definition*definition;k++, i++)
	{
		if (k != 0 && k%definition == 0)
		{
			j++;
			i = 0;
		}
		matrix.push_back(new Cell((i*(*cellSize)), *cellSize * j, cellSize, cellSize, 0.0f));
	}
}

Grid::Grid(int definition, int * cellSize, std::vector<float> values)
{
	this->definition = definition;
	this->cellSize = cellSize;

	for (int k = 0, i = 0, j = 0;k < definition*definition;k++, i++)
	{
		if (k != 0 && k%definition == 0)
		{
			j++;
			i = 0;
		}
		matrix.push_back(new Cell((i*(*cellSize)), *cellSize * j, cellSize, cellSize, values[i]));
	}
}

Cell* Grid::identifyCellByPos(int x, int y)
{
	return matrix[((y / *cellSize) * definition) + (x / *cellSize)];
}

std::string Grid::saveState()
{
	std::string saveString("DEFINITION$" + std::to_string(definition) + "#CELLSIZE$" + std::to_string(*cellSize) + "#VALUES$");

	for (int i = 0;i < matrix.size();i++)
	{
		saveString = saveString + std::to_string(matrix[i]->getValue()) + ";";
	}

	saveString = saveString + "#";

	return saveString;
}

void Grid::chargeState(std::string inString)
{


}

void Grid::clickOn(int x, int y)
{
	//Entonctrar casilla y cambiar valor
	identifyCellByPos(x, y)->witchIt();
}

void Grid::mouseOver(int x, int y)
{
	//Encontrar casilla y resaltar sobre la que estás 
	highlightedCell = identifyCellByPos(x, y);
}