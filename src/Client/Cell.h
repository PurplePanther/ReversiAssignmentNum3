
#ifndef CELL_H_
#define CELL_H_
#include <iostream>

/**
 * The Cell class represents a cell on the game board.
 */
class Cell {
private:
	// the X or O represented by an integer 1 for X 0 for O.
	int color;

	// a boolean, True if the cell is empty false otherwise.
	bool containsValue;

	//Cell's location on the board.
	int x, y;

public:
	//constructor method.
	Cell();

	//second constructor method.
	Cell(int x, int y);

	//get Cell's X value.
	int getX() const;

	//get Cell's Y value.
	int getY() const;

	// a public function which returns if the cell is empty.
	bool isEmpty() const;

	// a public function which returns the cells color (X or O).
	int getColor() const;

	// set functions to change the cells values.
	void setStatus(bool isEmpty);
	void setColor(int color);

	//set Cell's location.
	void setXY(int x, int y);

	Cell& operator=(const Cell &p);

	friend std::ostream& operator <<(std::ostream& out,const Cell &cell);

};

#endif /* CELL_H_ */
