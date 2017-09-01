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

Cell* Grid::identifyCellByPos(int x, int y)
{
	int debug = ((y / *cellSize) * definition) + (x / *cellSize);
	return matrix[debug];
}


void Grid::clickOn(int x, int y)
{
	identifyCellByPos(x, y)->witchIt();
	//Entonctrar casilla y cambiar valor
}

void Grid::mouseOver(int x, int y)
{
	//Encontrar casilla y resaltar sobre la que estás 

}