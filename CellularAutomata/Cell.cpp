#include "Cell.h"

Cell::Cell(int x, int y, int* width, int* height, float value, int* onColor, int* offColor)
{
	 this->x = x;
	 this->y = y;
	 this->width = width;
	 this->height = height;
	 this->value = value;
	 this->onColor = onColor;
	 this->offColor = offColor;
}
void Cell::setValue(float value) {
	this->value = value;
}
float Cell::getValue() {
	return value;
}
