#pragma once

class Cell {
private:
	//Variables
	bool status; //No seguro sobre esto
	float value;
	int onColor, offColor;

public:
	//Constructor
	Cell(int x, int y, int width, int height, float value);
		
	int x, y, width, height;
	void setValue(float value);
	float getValue();
};