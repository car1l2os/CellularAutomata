#include "Cell.h"

Cell::Cell(int x, int y, int width, int height, float value)
{
	 this->x = x;
	 this->y = y;
	 this->width = width;
	 this->height = height;
	 this->value = value;
	 onColor = 0x00;
	 offColor = 0xFF;
}
void Cell::setValue(float value) {
	this->value = value;
}
float Cell::getValue() {
	return value;
}
