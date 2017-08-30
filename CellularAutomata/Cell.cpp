#include "Cell.h"

//Constructor
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

//Getters
bool Cell::getStatus() {
	return value;
}
float Cell::getValue() {
	return value;
}
int* Cell::getOnColor() {
	return onColor;
}
int* Cell::getOffColor() {
	return offColor;
}
int Cell::getX() {
	return x;
}
int Cell::getY() {
	return y;
}
int* Cell::getHeight() {
	return height;
}
int* Cell::getWidth() {
	return width;
}

//Setters	
void Cell::setValue(float value) {
	this->value = value;
}
