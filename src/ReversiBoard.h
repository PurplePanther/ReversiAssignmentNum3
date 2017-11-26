/******************************************
*Student name: Tal Pogorelis
*Student ID: 318225349
*Exercise #: 2
******************************************/

#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_

//including the object Cell.
#include <vector>
#include "Cell.h"

/**
 * The ReversiBoard Class containing the board logic,
 * and determinates the outcome of the plays.
 */
class ReversiBoard {

private:
	//board size X*Y.
	int sizeX, sizeY;
public:
    int getSizeX() const;

    int getSizeY() const;

private:

    //2D array of Cells.
	Cell** gameBoard;

	void initBoard();

	//checks if the point is inside the board boundaries.
	bool pointIsValid(const int &pointX, const int &pointY) const;


public:

	//constructor method.
	ReversiBoard(int x=8,int y=8);

    //constructor method.
    void copyBoard(Cell** board);

	//destructor method.
	virtual ~ReversiBoard();

	//The function returns a pointer to a specific cell in the board.
	void flipCellsBetween(const Cell &x, const Cell &y);

	//finding all the friendly cells connecting to a specific cell.
	std::vector<Cell> connectionsWith(const Cell &x, const int &color);

	//The function returns the gameBoard.
	Cell** getBoard() const;

	//The function adds a game piece to the game board.
	void placePiece(const int &color,const int &positionX,const int &positionY);

	//The function counts the cells containing X.
	int countXCells() const;

	//The function counts the cells containing O.
	int countOCells() const;

	//The function prints the board to the screen.
	void printBoard() const;

	//The function checks if the board is full.
	bool isFull() const;

	//The function returns possible moves for certain sign.
	std::vector<Cell> possibleMoves(const int &sign) const;

	//The function checks if the cell is playable according to the game rules.
	bool isValidCell(const int &x, const int &y, const int &sign) const;


};

#endif /* REVERSIBOARD_H_ */
