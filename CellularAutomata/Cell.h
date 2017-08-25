#pragma once

class Cell {
private:
	//Variables
	bool status; //No seguro sobre esto - Not sure about this
	float value;

public:
	//Constructor
	Cell(int x, int y, int width, int height, bool status, float value);

	int x, y, width, height;
	void setStatus(bool value);
	bool getStatus(void);

	void setValue(float value);
	float getValue();
};