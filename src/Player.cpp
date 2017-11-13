/******************************************
*Student name: Tal Pogorelis
*Student ID: 318225349
*Exercise #: 2
******************************************/

#include <limits>
#include "Player.h"
#include "ReversiBoard.h"
#include "Cell.h"

/**
 * the constructor method.
 * @param color - the player's color.
 */
Player::Player(int color) {
	this->color = color;
}

/**
 * the function returns the players color.
 * @return - the player's color.
 */
int Player::getColor() const{
	return this->color;
}

/**
 * the function returns the players score.
 * @return - an integer containing the player's score.
 */
int Player::getScore() const{
	int score=0;
	if(this->color == 0){
		score=this->gameBoard->countOCells();
	} else {
		score=this->gameBoard->countXCells();
	}
	return score;
}

/**
 * the function plays one turn.
 */
void Player::playOneTurn(){
	Cell x;
	char sign;
	//checking if player can move
	if(this->hasValidMoves()){
		if(this->color == 1) {
			sign = 'X';
		} else {
			sign = 'O';
		}
		std::cout << sign << ": It's your move." << std::endl;
		std::cout << "Your possible moves: ";


		Cell* array = this->gameBoard->possibleMoves(this->color);

		for(int i=0 ; i < (unsigned) sizeof(array);i++){
			if(!array[i].isEmpty()){
			std::cout << array[i];
			if(!array[i+1].isEmpty()){
			std::cout << ',';
			}
			}
		}
		std::cout << std::endl;
		std::cout << std::endl;
		bool acceptablemove = false;
		while(acceptablemove == false){
			x = this->chooseMove();
			if(!std::cin.fail() && this->gameBoard->isValidCell(x.getX()-1, x.getY()-1,this->color)){
				this->gameBoard->placePiece(this->color, x.getX(), x.getY());
				acceptablemove = true;
			}else{
				std::cout << "Error, not a valid move," << std::endl;
				std::cout << "Please choose one of the valid moves above." << std::endl;

				std::cin.clear(); // reset failbit
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input

			}
		}
		delete[] array;
	} else {
		//player has no valid moves.
		std::cout << sign << ": It's your move." << std::endl;
		std::cout << "No possible Moves. Play passes back to the other player."
				<< std::endl;
		return;
	}
	//printing the updated board.
	this->gameBoard->printBoard();
	std::cout << sign << " Played" <<"(" << x.getX() <<","<<x.getY() <<")"<<std::endl;


}

/**
 * the function checks if the user has any possible moves.
 * @return - a boolean.
 */
bool Player::hasValidMoves() {
	Cell* array;
	array = this->gameBoard->possibleMoves(this->color);
	if(array[0].isEmpty()){
		delete[] array;
		return false;
	}else{
		delete[] array;
		return true;
	}
}

/**
 * setting the game board.
 * @param board - the game board.
 */
void Player::setGameBoard(ReversiBoard* board){
	this->gameBoard = board;
}

/**
 * the destructor method.
 */
Player::~Player() {
	// TODO Auto-generated destructor stub
}
