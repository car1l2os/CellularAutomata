#pragma once

class Cell {
private:
	//Variables
	bool status; //No seguro sobre esto
	float value;
	int* onColor; //No en uso temporalmente - Coloreo siempre del mismo color 
	int* offColor; //No en uso temporalmente - Coloreo siempre del mismo color 
	int x, y;
	int* width;
	int* height;

public:
	//Constructor
	Cell(int x, int y, int* width, int* height, float value, int* onColor, int* offColor);
		
	//Getters 
	bool getStatus();
	float getValue();
	int* getOnColor();
	int* getOffColor();
	int getX();
	int getY();
	int* getWidth();
	int* getHeight();

	//Setters
	void setValue(float value);
};