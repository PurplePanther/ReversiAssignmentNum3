/******************************************
*Student name: Tal Pogorelis
*Student ID: 318225349
*Exercise #: 2
******************************************/

#include "ReversiBoard.h"
#include <iostream>

/**
 * the constructor method.
 * @param x - the board's width.
 * @param y - the board's length.
 */
ReversiBoard::ReversiBoard(int x, int y) {
	this->sizeX = x;
	this->sizeY = y;

	//creating a new game board.
	this->gameBoard = new Cell*[x];
	for(int i = 0; i < x; ++i) {
		this->gameBoard[i] = new Cell[y];
	}

	//initializing board to default state.
	initBoard();

}


/**
 * the function initializes the board to the default state.
 */
void ReversiBoard::initBoard(){
	for(int i = 0; i < sizeX ; i++) {
		for(int j = 0; j < sizeY ; j++) {
			this->gameBoard[i][j] = Cell(i,j);
			this->gameBoard[i][j].setStatus(false);
			this->gameBoard[i][j].setColor(-1);
		}
	}
	int mid=sizeX/2;
	//starting position of O's
	this->gameBoard[mid-1][mid-1].setStatus(true);
	this->gameBoard[mid][mid].setStatus(true);
	this->gameBoard[mid-1][mid-1].setColor(0);
	this->gameBoard[mid][mid].setColor(0);

	//starting position of X's
	this->gameBoard[mid-1][mid].setStatus(true);
	this->gameBoard[mid][mid-1].setStatus(true);
	this->gameBoard[mid-1][mid].setColor(1);
	this->gameBoard[mid][mid-1].setColor(1);

}

/**
 * the function flips the cells between the input cells.
 * @param x - first Cell.
 * @param y - second Cell.
 */
void ReversiBoard::flipCellsBetween(const Cell &x, const Cell &y){
	// the directions we are going to flip the opposite cells.

	int directionX = 0;
	int directionY = 0;
	int cellXX = x.getX();
	int cellYX = y.getX();
	//getting direction X.
	if (cellXX > cellYX) {
		directionX = -1;
	} else if(cellXX < cellYX) {
		directionX = 1;
	} else {
		directionX = 0;
	}

	int cellXY = x.getY();
	int cellYY = y.getY();
	//getting direction Y.
	if (cellXY > cellYY) {
		directionY = -1;
	} else if(x.getY() < y.getY()) {
		directionY = 1;
	} else {
		directionY = 0;
	}

	while((cellYX != cellXX) || (cellXY != cellYY)) {
		cellXX+=directionX;
		cellXY+=directionY;
		if(x.getColor() == 1) {
			this->gameBoard[cellXX][cellXY].setColor(1);
		}else{
			this->gameBoard[cellXX][cellXY].setColor(0);
		}
	}
}



/**
 * returning a pointer to the gameBoard.
 * @return - a pointer to an array of pointers to cell arrays.
 */
Cell** ReversiBoard::getBoard() const{
	return this->gameBoard;
}

/**
 * the function adds a game piece to the game board.
 * @param color - the game's piece color.
 * @param positionX - the X coordinate.
 * @param positionY - the Y coordinate.
 */
void ReversiBoard::placePiece(const int &color,const int &positionX, const int &positionY) {
	Cell* arrayConnections = connectionsWith(gameBoard[positionX-1][positionY-1],color);

	this->gameBoard[positionX-1][positionY-1].setColor(color);
	this->gameBoard[positionX-1][positionY-1].setStatus(true);

	for (int i = 0; i < (signed)sizeof(arrayConnections); i++){
		if(!arrayConnections[i].isEmpty()){
			this->flipCellsBetween(gameBoard[positionX-1][positionY-1],arrayConnections[i]);
		}
	}
	delete[] arrayConnections;
}



/**
 * the function counts the cells containing 1 (a.k.a 'X').
 * @return - an integer containing the score of player X.
 */
int ReversiBoard::countXCells() const{
	int x = 0;
	for(int i = 0; i < this->sizeX ; ++i) {
		for(int j = 0; j < this->sizeY ; ++j) {
			if(!this->gameBoard[i][j].isEmpty()){
				if(this->gameBoard[i][j].getColor() == 1){
					x++;
				}
			}
		}
	}
	return x;
}

/**
 * the function counts the cells containing 0 (a.k.a 'O').
 * @return - an integer containing the score of player O.
 */
int ReversiBoard::countOCells() const{
	int x = 0;
	for(int i = 0; i < this->sizeX ; ++i) {
		for(int j = 0; j < this->sizeY ; ++j) {
			if(!this->gameBoard[i][j].isEmpty()){
				if(this->gameBoard[i][j].getColor() == 0){
					x++;
				}
			}
		}
	}
	return x;
}


/**
 * The function prints the board to the screen.
 */
void ReversiBoard::printBoard() const{
	std::cout << "Current board: " << std::endl;
	std::cout << std::endl;
	//printing the row #'s.
	std::cout << ' ' << "|";
	for (int i = 1; i <= this->sizeX ; ++i) {
		std::cout << i << "|";
	}
	//printing the line separation.
	std::cout << std::endl;
	for (int i = 0; i <= this->sizeX ; ++i){
	std::cout << "--";
	}
	std::cout << std::endl;


	char y;
	for (int i = 0; i < this->sizeX ; ++i) {
		std::cout << i+1 << "|";
			for (int j = 0; j < this->sizeY; ++j) {
				if(this->gameBoard[j][i].isEmpty()) {
					y = ' ';
				}else if(this->gameBoard[j][i].getColor() == 1) {
					y = 'X';
				}else{
					y = 'O';
				}
				std::cout << y << "|";
			}

		//printing the line separation.
		std::cout << std::endl;

		for (int i = 0; i <= this->sizeX ; ++i){
		std::cout << "--";
		}
		std::cout << std::endl;
		//printing the line separation.

		}
	return;
}


/**
 * The function checks if the board is full.
 * @return - returns a boolean.
 */
bool ReversiBoard::isFull() const{
	if(this->countOCells() + this->countXCells() == this->sizeX*this->sizeY) {
		return true;
	}
	return false;
}

/**
 * The function returns possible moves for certain sign.
 * @param sign - the player's color.
 * @return - an array of cells containing the possible move for the input player.
 */
Cell* ReversiBoard::possibleMoves(const int &sign) const{
	Cell* array = 	new Cell[20];
	int counter = 0;
	int checkSize = 20;

	// going over the entire board looking for possible moves.
	for (int i = 0; i < this->sizeX; i++) {
		for (int j = 0; j < this->sizeY; j++) {
			//checking is cell i,j is playable.
			if(this->isValidCell(i,j,sign)) {
				if(counter < checkSize - 1) {
					array[counter] = Cell(i,j);
					counter++;
				} else {
                    checkSize *= 2;
					Cell* temp = new Cell[checkSize];
					std::copy(array, array + checkSize, temp);
					delete [] array;
					array = temp;
				}
			}
		}
	}

	return array;
}


/**
 * The function checks if the point is inside the board boundaries.
 * @param x - the x coordinate of the point.
 * @param y - the y coordinate of the point.
 * @return - a boolean, true if point is inside the board boundaries.
 */
bool ReversiBoard::pointIsValid(const int &x, const int &y) const{

	if( x < 0 || y < 0 ||
			x >= this->sizeX || y >= this->sizeY){
		return false;
	}

	return true;
}



/**
 * The function checks if the cell is playable according to the game rules.
 * @param x - the X coordinate.
 * @param y - the Y coordinate.
 * @param sign - the player we are checking the cell for.
 * @return - a boolean containing true if cell is playable for the input player.
 */
bool ReversiBoard::isValidCell(const int &x, const int &y, const int &sign) const{
	//if the cell we are looking for is out of boundaries.
	if(!pointIsValid(x,y)) {
		return false;
	}else{

		int currentX = x;
		int currentY = y;
		//checking if the cell we are looking at is empty.
		if(this->gameBoard[currentX][currentY].isEmpty()) {

			//checking for surrounding cells.
			for (int i = -1; i <= 1 ; ++i){
				for (int j = -1; j <= 1; ++j){
					// check if surrounding cells are in the boundaries.
					if(!pointIsValid(currentX+i,currentY+j)) {
						continue;
					}
					//we are making sure the current neighbor cell we are looking at isn't empty.
					bool isNeighborEmpty = this->gameBoard[currentX+i][currentY+j].isEmpty();

					//if the neighbor cell is empty we move on to another neighbor cell.
					if(isNeighborEmpty) {
						continue;
					}
					//we are making sure the sign of the neighbor cell is different than ours.
					bool hasDiffSign = (this->gameBoard[currentX+i][currentY+j].getColor() != sign);
					if(!isNeighborEmpty && hasDiffSign){
						bool found = false;
						int posX = currentX+i+i;
						int posY = currentY+j+j;

						if(!pointIsValid(posX,posY)) {
								continue;
						}

						bool friendlyNeighbor = this->gameBoard[posX][posY].isEmpty();

						//checking if there is a piece that we can possibly connect with so we can flip.
						if(friendlyNeighbor) {
							continue;
						}
						//checking if possible connection Cell is friendly.
						bool hasSameSign = (this->gameBoard[posX][posY].getColor() == sign);
						if(!friendlyNeighbor && hasSameSign){

						// this cell can be played.
						return true;
						} else if (!hasSameSign) {
							while (!found){
								posX += i;
								posY += j;
								if(!pointIsValid(posX,posY)){
									break;
								}
								if(this->gameBoard[posX][posY].getColor() == sign) {
									return true;
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}


/**
 * the destructor method.
 */
ReversiBoard::~ReversiBoard() {
	for (int i = 0; i < sizeX; i++){
			delete[] gameBoard[i];
	}
	delete[] this->gameBoard;
}



/**
 * the function returns an array of all the possible connections with the specific cell.
 * @param x - the input cell we are looking at.
 * @param color - the color of the player we are looking for connections for.
 * @return - an array containing all the connections with the input cell.
 */
Cell* ReversiBoard::connectionsWith(const Cell &x,const int &color){

	//defining an array of cells.
	Cell* array= new Cell[10];
	int counter = 0;

	//checking if the cell is a valid cell.
	if(!this->isValidCell(x.getX(),x.getY(),color)){
		return array;
	} else {
		int currentX = x.getX();
		int currentY = x.getY();

		//checking if the cell we are looking at is currently empty.
		if(this->gameBoard[currentX][currentY].isEmpty()) {

			//checking for surrounding cells.
			for (int i = -1; i <= 1 ; ++i){
				for (int j = -1; j <= 1; ++j){
					// check if surrounding cells are in the boundaries.
					if(!this->pointIsValid(currentX+i,currentY+j)) {
						continue;
					}
					//we are making sure the current neighbor cell we are looking at isn't empty.
					bool isNeighborEmpty = this->gameBoard[currentX+i][currentY+j].isEmpty();

					//if the neighbor cell is empty we move on to another neighbor cell.
					if(isNeighborEmpty) {
						continue;
					}
					//we are making sure the sign of the neighbor cell is different than ours.
					bool hasDiffSign = (this->gameBoard[currentX+i][currentY+j].getColor() != color);

					if(!isNeighborEmpty && hasDiffSign){
						bool found = false;
						int posX = currentX+i+i;
						int posY = currentY+j+j;

						if(!pointIsValid(posX,posY)){
							continue; // testing continue v break;
						}
						bool friendlyNeighbor = this->gameBoard[posX][posY].isEmpty();
						//checking if there is a piece that we can possibly connect with so we can flip.
						if(friendlyNeighbor) {
							continue;
						}

						//checking if possible connection Cell is friendly.
						bool hasSameSign = (this->gameBoard[posX][posY].getColor() == color);
						if(!friendlyNeighbor && hasSameSign){

						// this cell can be played.
						array[counter] = Cell(posX,posY);
						counter++;
						} else if (!hasSameSign) {
							while (!found){
								posX = posX + i;
								posY = posY + j;

								if(!pointIsValid(posX,posY)){
									break;
								}
								if(this->gameBoard[posX][posY].getColor() == color) {
									array[counter] = Cell(posX,posY);
									counter++;
								}
							}
						}
					}
				}
			}
		}
	}
	return array;
}




