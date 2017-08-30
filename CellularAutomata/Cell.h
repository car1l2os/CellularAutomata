#pragma once

class Cell {
private:
	//Variables
	bool status; //No seguro sobre esto
	float value;
	int* onColor; //No en uso temporalmente - Coloreo siempre del mismo color 
	int* offColor; //No en uso temporalmente - Coloreo siempre del mismo color 

public:
	//Constructor
	Cell(int x, int y, int* width, int* height, float value, int* onColor, int* offColor);
		
	int x, y;
	int* width;
	int* height;
	void setValue(float value);
	float getValue();
};