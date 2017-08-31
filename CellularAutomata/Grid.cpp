#include "Grid.h"

/*Esta clase se va a encargar de comprobar
vecinos y otros metodos dentro de la matriz
que quedaran enmascarados */


Grid::Grid(int definition, int* cellSize)
{
	this->definition = definition;

	for (int i = 0;i < definition*definition;i++)
	{
		matrix.push_back(new Cell(0+(i*(*cellSize)), 0,cellSize, cellSize, 1.0f));
	}
}



