#include "Grid.h"
#include <iostream>
#include <SDL.h>



/*Esta clase se va a encargar de comprobar
vecinos y otros metodos dentro de la matriz
que quedaran enmascarados */


Grid::Grid(int definition, int* cellSize)
{
	this->definition = definition;

	for (int k=0, i =0, j=0 ;k < definition*definition;k++,i++)
	{
		if ( k!= 0 && k%definition == 0)
		{
			j++;
			i = 0;
		}

		if(i%2 == 0)
			matrix.push_back(new Cell((i*(*cellSize)), *cellSize * j,cellSize, cellSize, 1.0f));
		else
		{
			matrix.push_back(new Cell((i*(*cellSize)), *cellSize * j, cellSize, cellSize, 0.0f));
		}
	}
}


