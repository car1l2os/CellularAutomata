#include "Cell.h"

Cell::Cell(int x, int y, int width, int height, bool status, float value)
{
	 this->x = x;
	 this->y = y;
	 this->width = width;
	 this->height = height;
	 this->status = status;
	 this->value = value;
}
void Cell::setStatus(bool value)	{
	status = value;	
}
bool Cell::getStatus()				{
	return status;
}
void Cell::setValue(float value) {
	this->value = value;
}
float Cell::getValue() {
	return value;
}