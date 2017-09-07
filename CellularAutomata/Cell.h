#pragma once

class Cell {
private:
	//Variables
	bool status; //No seguro sobre esto
	float value;
	int x, y;
	int* width;
	int* height;

public:
	//Constructor
	Cell(int x, int y, int* width, int* height, float value);
		
	//Getters 
	bool getStatus();
	float getValue();
	int getX();
	int getY();
	int* getWidth();
	int* getHeight();

	//Setters
	void setValue(float value);

	//Functions
	void Cell::switchIt();
	void Cell::nextValue();

};