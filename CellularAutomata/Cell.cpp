class Cell {
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