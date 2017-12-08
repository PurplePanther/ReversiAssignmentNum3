
#include "Cell.h"

/**
 * basic constructor method.
 */
Cell::Cell() {
	this->containsValue = false;
	this->color = -1;
	this->x = -1;
	this->y = -1;
}

/**
 * constructor method that gets the Cell's X & Y values.
 */
Cell::Cell(int x, int y) {
	//converting from board to array values.
	this->containsValue = false;
	this->x = x;
	this->y = y;
	this->color = -1;
}

/**
 * the function returns the cell's X value.
 * @return - an integer containing the X value.
 */
int Cell::getX() const{
	return this->x;
}

/**
 * the function returns the cell's Y value.
 * @return - an integer containing the Y value.
 */
int Cell::getY() const{
	return this->y;
}

/**
 * the function sets the cell's X&Y values.
 * @param x - the cell's X parameter.
 * @param y - the cell's Y parameter.
 */
void Cell::setXY(int x, int y) {
	this->x = x;
	this->y = y;
}

/**
 * set function to change the cells value.
 * @param isEmpty - a boolean containing the cell's value.
 */
void Cell::setStatus(bool isEmpty) {
	this->containsValue = isEmpty;
}

/**
 * set function to change the cells color value.
 * @param color -
 */
void Cell::setColor(int color) {
	this->color = color;
}

/**
 * The function returns true if the cell is empty, False - if the cell contains a value.
 * @return - a boolean containing true if the cell contains a value.
 */
bool Cell::isEmpty() const {
	return !this->containsValue;
}

/**
 * a function which returns the color of the cell as an int (1=X or 0=O).
 * @return - an integer containing the cell's color.
 */
int Cell::getColor() const {
	return this->color;
}

/**
 * overload for the "=" operator.
 * @param p - a pointer to a cell object.
 * @return - returns this Cell with the values of the inputed Cell.
 */
Cell& Cell::operator=(const Cell &p) {
		if (this!= &p) {
			this->x = p.x;
			this->y = p.y;
			this->color = p.color;
			this->containsValue = true;
		}
		return *this;
	}

/**
 * overload for the "<<" operator.
 * @param out - the output stream.
 * @param cell - the cell we want to print.
 * @return - a stream containing the cell's print form.
 */
std::ostream &operator <<(std::ostream& out,const Cell &cell) {
	out << "(" << cell.x + 1 << ","<< cell.y + 1 << ")";
	return out;
}


