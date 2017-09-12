#include "Grid.h"
#include <iostream>
#include <SDL.h>



/*Esta clase se va a encargar de comprobar
vecinos y otros metodos  dentro de la matriz
que quedaran enmascarados */


Grid::Grid(int definition, int* cellSize)
{
	matrix.clear();
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
Grid::Grid(int* canvasSide)
{
	matrix.clear(); //No se si tengo que hacer esto.
	for (int i=0; i<*canvasSide * *canvasSide;i++)
	{
		matrix.push_back(new Cell(0.0f,0.0f));
	}
}

Cell* Grid::identifyCellByPos(int x, int y)
{
	return matrix[((y / *cellSize) * definition) + (x / *cellSize)];
}

void Grid::GetMatrixValues()
{
	matrixAux.clear();

	for (int i = 0;i < matrix.size();i++)
	{
		matrixAux.push_back(matrix.at(i)->getValue());
	}
}
void Grid::SetMatrixValues()
{
	if (matrix.size() == matrixAux.size())
	{
		for (int i = 0;i < matrixAux.size();i++)
		{
			matrix.at(i)->setValue(matrixAux[i]);
		}
	}
}

void Grid::GetAValues()
{
	matrixAux.clear();

	for (int i = 0;i < matrix.size();i++)
	{
		matrixAux.push_back(matrix.at(i)->getA());
	}
}
void Grid::GetBValues() 
{
	matrixAuxB.clear();

	for (int i = 0;i < matrix.size();i++)
	{
		matrixAuxB.push_back(matrix.at(i)->getB());
	}
}
void Grid::SetAValues()
{
	if (matrix.size() == matrixAux.size())
	{
		for (int i = 0;i < matrixAux.size();i++)
		{
			matrix.at(i)->setA(matrixAux[i]);
		}
	}
}
void Grid::SetBValues()
{
	if (matrix.size() == matrixAuxB.size())
	{
		for (int i = 0;i < matrixAuxB.size();i++)
		{
			matrix.at(i)->setB(matrixAuxB[i]);
		}
	}
}

float Grid::LaplaceA()
{
	return 0.0f;
}

float Grid::LaplaceB()
{
	return 0.0f;
}

std::string Grid::saveState()
{
	std::string saveString("#DEFINITION$" + std::to_string(definition) + "#CELLSIZE$" + std::to_string(*cellSize) + "#VALUES$");

	for (int i = 0;i < matrix.size();i++)
	{
		saveString = saveString + std::to_string(matrix[i]->getValue()) + ";";
	}

	saveString = saveString + "#";

	return saveString;
}

void Grid::chargeState(std::string inString, int* cellSizeDirection)
{

	int n_definition = -1;
	int n_cellSize = -1;

	//std::vector<float> n_values;
	int valuesIndex = 0;
	std::string readed("");

	for (std::string::size_type i = 0; i < inString.size();i++)
	{
		std::cout << i << std::endl;

		if (inString[i] == '$') //Star reading value
		{
			i++; //Pasamos a los valores 

			if (readed == "DEFINITION") //Almacenar  en ultima posicion del vector 
			{
				readed = "";
				while (inString[i] != '#') //Hasta que no encuentres otro parametro a leer	
				{
					readed += inString[i];
					i++;
				}
				n_definition = atoi(readed.c_str());
				readed = "";
			}
			else if (readed == "VALUES") //Almacenar en un vector 
			{
				readed = "";
				while (inString[i] != '#') //Hasta que no encuentres otro parametro a leer	
				{
					while (inString[i] != ';')
					{
						readed += inString[i];
						i++;
					}
					matrixAux.push_back(std::stof(readed));
					valuesIndex++;
					readed = "";
					i++;
				}
			}
			else if (readed == "CELLSIZE")
			{
				readed = "";
				while (inString[i] != '#') //Hasta que no encuentres otro parametro a leer	
				{
					readed += inString[i];
					i++;
				}
				n_cellSize = atoi(readed.c_str());
				readed = "";
			}
		}
		else if (inString[i] == '#') //Change parameter
		{
			readed = "";
		}
		/*else if (inString[i] == ';') //Change value of Cell
		{

		}*/
		else //Reading 
		{
			readed += inString[i];
		}

	}

	std::cout << "SALE DEL FOR" << std::endl;

	*cellSizeDirection = n_cellSize;
	definition = n_definition;
	SetMatrixValues();
	matrixAux.clear();



	//return new Grid(n_definition, cellSizeDirection, n_values);
}

std::vector<Cell*> Grid::GetNeighbours(Cell * cell, int cellIndex)
{
	std::vector<Cell*> neighbours;

	if ((cell->getY() / *(cell->getHeight())) == 0) //Franja superior
	{
		if ((cell->getX() / *(cell->getWidth())) == 0) //Esquina superior izquierda
		{
			neighbours.push_back(matrix.at(1));
			neighbours.push_back(matrix.at(definition));
			neighbours.push_back(matrix.at(definition + 1));
		}
		else if ((cell->getX() / *(cell->getWidth())) == definition - 1) //Esquina superior derecha
		{
			neighbours.push_back(matrix.at(definition - 2));
			neighbours.push_back(matrix.at((definition * 2) - 1));
			neighbours.push_back(matrix.at((definition * 2) - 2));
		}
		else
		{
			neighbours.push_back(matrix.at(cellIndex - 1));
			neighbours.push_back(matrix.at(cellIndex + 1));

			neighbours.push_back(matrix.at(cellIndex + definition - 1));
			neighbours.push_back(matrix.at(cellIndex + definition));
			neighbours.push_back(matrix.at(cellIndex + definition + 1));
		}
	}
	else if ((cell->getX() / *(cell->getWidth())) == 0) //Franja izquierda
	{
		if ((cell->getY() / *(cell->getHeight())) == (definition - 1)) //Esquina inferior izquierda
		{
			neighbours.push_back(matrix.at((definition*(definition - 2))));
			neighbours.push_back(matrix.at((definition*(definition - 2)) + 1));
			neighbours.push_back(matrix.at((definition*(definition - 1)) + 1));
		}
		else
		{
			neighbours.push_back(matrix.at(cellIndex - definition));
			neighbours.push_back(matrix.at(cellIndex - definition + 1));

			neighbours.push_back(matrix.at(cellIndex + 1));

			neighbours.push_back(matrix.at(cellIndex + definition));
			neighbours.push_back(matrix.at(cellIndex + definition + 1));
		}
	}
	else if ((cell->getY() / *(cell->getHeight())) == (definition - 1)) //Franja inferior
	{
		if ((cell->getX() / *(cell->getWidth())) == (definition - 1)) //Esquina inferior derecha
		{
			neighbours.push_back(matrix.at((definition*(definition - 1)) + (definition - 1) - 1)); //Anterior
			neighbours.push_back(matrix.at((definition*(definition - 2)) + (definition - 1))); //Una fila por encima
			neighbours.push_back(matrix.at((definition*(definition - 2)) + (definition - 1) - 1)); //Fila por encima una columna menos 
		}
		else
		{
			neighbours.push_back(matrix.at(cellIndex - definition - 1));
			neighbours.push_back(matrix.at(cellIndex - definition));
			neighbours.push_back(matrix.at(cellIndex - definition + 1));

			neighbours.push_back(matrix.at(cellIndex - 1));
			neighbours.push_back(matrix.at(cellIndex + 1));




		}
	}
	else if ((cell->getX() / *(cell->getWidth())) == (definition - 1)) //Franja derecha
	{
		neighbours.push_back(matrix.at(cellIndex - definition - 1));
		neighbours.push_back(matrix.at(cellIndex - definition));

		neighbours.push_back(matrix.at(cellIndex - 1));

		neighbours.push_back(matrix.at(cellIndex + definition - 1));
		neighbours.push_back(matrix.at(cellIndex + definition));
	}
	else //Caso general
	{
		neighbours.push_back(matrix.at(cellIndex - definition - 1));
		neighbours.push_back(matrix.at(cellIndex - definition));
		neighbours.push_back(matrix.at(cellIndex - definition + 1));

		neighbours.push_back(matrix.at(cellIndex - 1));
		neighbours.push_back(matrix.at(cellIndex + 1));

		neighbours.push_back(matrix.at(cellIndex + definition - 1));
		neighbours.push_back(matrix.at(cellIndex + definition));
		neighbours.push_back(matrix.at(cellIndex + definition + 1));
	}


	return neighbours;
}

std::vector<Cell*> Grid::GetToroidalNeighbours(Cell * cell, int cellIndex) //No tengo muy claras comportamiento en las esquinas
{
	std::vector<Cell*> neighbours;

	if ((cell->getY() / *(cell->getHeight())) == 0) //Franja superior
	{
		if ((cell->getX() / *(cell->getWidth())) == 0) //Esquina superior izquierda
		{
			neighbours.push_back(matrix.at(1));
			neighbours.push_back(matrix.at(definition));
			neighbours.push_back(matrix.at(definition + 1));
		}
		else if ((cell->getX() / *(cell->getWidth())) == definition - 1) //Esquina superior derecha
		{
			neighbours.push_back(matrix.at(definition - 2));
			neighbours.push_back(matrix.at((definition * 2) - 1));
			neighbours.push_back(matrix.at((definition * 2) - 2));
		}
		else
		{
			neighbours.push_back(matrix.at(cellIndex - 1));
			neighbours.push_back(matrix.at(cellIndex + 1));

			neighbours.push_back(matrix.at(cellIndex + definition - 1));
			neighbours.push_back(matrix.at(cellIndex + definition));
			neighbours.push_back(matrix.at(cellIndex + definition + 1));
		}
	}
	else if ((cell->getX() / *(cell->getWidth())) == 0) //Franja izquierda
	{
		if ((cell->getY() / *(cell->getHeight())) == (definition - 1)) //Esquina inferior izquierda
		{
			neighbours.push_back(matrix.at((definition*(definition - 2))));
			neighbours.push_back(matrix.at((definition*(definition - 2)) + 1));
			neighbours.push_back(matrix.at((definition*(definition - 1)) + 1));
		}
		else
		{
			neighbours.push_back(matrix.at(cellIndex - definition));
			neighbours.push_back(matrix.at(cellIndex - definition + 1));

			neighbours.push_back(matrix.at(cellIndex + 1));

			neighbours.push_back(matrix.at(cellIndex + definition));
			neighbours.push_back(matrix.at(cellIndex + definition + 1));
		}
	}
	else if ((cell->getY() / *(cell->getHeight())) == (definition - 1)) //Franja inferior
	{
		if ((cell->getX() / *(cell->getWidth())) == (definition - 1)) //Esquina inferior derecha
		{
			neighbours.push_back(matrix.at((definition*(definition - 1)) + (definition - 1) - 1)); //Anterior
			neighbours.push_back(matrix.at((definition*(definition - 2)) + (definition - 1))); //Una fila por encima
			neighbours.push_back(matrix.at((definition*(definition - 2)) + (definition - 1) - 1)); //Fila por encima una columna menos 
		}
		else
		{
			neighbours.push_back(matrix.at(cellIndex - definition - 1));
			neighbours.push_back(matrix.at(cellIndex - definition));
			neighbours.push_back(matrix.at(cellIndex - definition + 1));

			neighbours.push_back(matrix.at(cellIndex - 1));
			neighbours.push_back(matrix.at(cellIndex + 1));
		}
	}
	else if ((cell->getX() / *(cell->getWidth())) == (definition - 1)) //Franja derecha
	{
		neighbours.push_back(matrix.at(cellIndex - definition - 1));
		neighbours.push_back(matrix.at(cellIndex - definition));

		neighbours.push_back(matrix.at(cellIndex - 1));

		neighbours.push_back(matrix.at(cellIndex + definition - 1));
		neighbours.push_back(matrix.at(cellIndex + definition));
	}
	else //Caso general
	{
		neighbours.push_back(matrix.at(cellIndex - definition - 1));
		neighbours.push_back(matrix.at(cellIndex - definition));
		neighbours.push_back(matrix.at(cellIndex - definition + 1));

		neighbours.push_back(matrix.at(cellIndex - 1));
		neighbours.push_back(matrix.at(cellIndex + 1));

		neighbours.push_back(matrix.at(cellIndex + definition - 1));
		neighbours.push_back(matrix.at(cellIndex + definition));
		neighbours.push_back(matrix.at(cellIndex + definition + 1));
	}

	return neighbours;
}

void Grid::ClearMatrix()
{
	for (int i = 0; i < matrix.size(); i++)
	{
		matrix.at(i)->setValue(0.0f);
	}
}

void Grid::ChangeSimulation()
{
	if (simulation_flag == GAME_OF_LIVE)
		simulation_flag = WIRE_WORLD;
	else if (simulation_flag == WIRE_WORLD)
		simulation_flag = GAME_OF_LIVE;

	ClearMatrix();
}

void Grid::GameOfLiveSimulation()
{
	GetMatrixValues(); //Guarda valores en aux

	for (int i = 0; i < matrix.size(); i++)
	{
		std::vector<Cell*> aux = GetNeighbours(matrix.at(i), i);
		int count = 0;

		if (matrix.at(i)->getValue() == 1.0f) //Si viva
		{
			for (int j = 0; j < aux.size();j++)
			{
				if (aux.at(j)->getValue() == 1.0f)
					count++;
			}

			if (count != 2 && count != 3)
				matrixAux[i] = 0.0f; //Matada
		}
		else if (matrix.at(i)->getValue() == 0.0f) //Si muerta
		{
			for (int j = 0; j < aux.size();j++)
			{
				if (aux.at(j)->getValue() == 1.0f)
					count++;
			}

			if (count == 3)
				matrixAux[i] = 1.0f; //Nacida
		}

	}

	SetMatrixValues();
	matrixAux.clear();

	//Hay que destruir matrixAux
}

void Grid::WireWorldSimulation()
{
	GetMatrixValues();

	for (int i = 0; i < matrix.size(); i++)
	{
		if (matrix.at(i)->getValue() == 0.75)
		{
			std::vector<Cell*> aux = GetNeighbours(matrix.at(i), i);
			int count = 0;

			for (int j = 0; j < aux.size(); j++)
			{
				if (aux.at(j)->getValue() == 0.25f)
					count++;
			}

			if (count == 1 || count == 2)
				matrixAux[i] = 0.25f; //Helectron head
		}
		else if (matrix.at(i)->getValue() == 0.5 || matrix.at(i)->getValue() == 0.25) //Not != 0.0f to control extrange values
		{
			matrixAux[i] += 0.25f;
		}
	}

	SetMatrixValues();
	matrixAux.clear();
}

void Grid::ReactionDifusionSimulation()
{
	GetAValues();
	GetBValues();

	for (int i = 0; i < matrix.size(); i++)
	{
		float a = matrix.at(i)->getA();
		float b = matrix.at(i)->getB();

		matrixAux[i] = a + (dA * LaplaceA()) - (a*b*b) + (FEED * (1 - a));
		matrixAuxB[i] = b + (dB * LaplaceB()) + (a*b*b) - ((KILL + FEED) * b);

	}

}

void Grid::Simulate()
{
	if (simulation_flag == GAME_OF_LIVE)
		GameOfLiveSimulation();
	else if (simulation_flag == WIRE_WORLD)
		WireWorldSimulation();
}

void Grid::ChangeMatrixToPixel()
{
	matrix.clear();
}

int Grid::getSimulationFlag()
{
	return simulation_flag;
}
void Grid::setSimulationFlag(int value)
{
	simulation_flag = value;
}

void Grid::clickOn(int x, int y)
{
	//Entonctrar casilla y cambiar valor

	if (simulation_flag == GAME_OF_LIVE)
		identifyCellByPos(x, y)->switchIt();

	else if (simulation_flag == WIRE_WORLD)
		identifyCellByPos(x, y)->nextValue();
}

void Grid::mouseOver(int x, int y)
{
	//Encontrar casilla y resaltar sobre la que estás 
	highlightedCell = identifyCellByPos(x, y);
}