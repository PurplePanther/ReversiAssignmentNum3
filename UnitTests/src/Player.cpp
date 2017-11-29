/******************************************
*Student name: Tal Pogorelis
*Student ID: 318225349
*Exercise #: 2
******************************************/

#include <limits>
#include "Player.h"


/**
 * the constructor method.
 * @param color - the player's color.
 */
Player::Player(int color) {
	this->color = color;
	this->Ai = false;
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

    if(this->color == 1) {
        sign = 'X';
    } else {
        sign = 'O';
    }

    if(this->hasValidMoves()){

		std::cout << sign << ": It's your move." << std::endl;
		std::cout << "Your possible moves: ";


		std::vector<Cell> possibleMovesVector = this->gameBoard->possibleMoves(this->color);
        std::vector<Cell>::iterator it;
        int i = 0;
		for(it = possibleMovesVector.begin() ; it < possibleMovesVector.end() ; it++,i++){

			if(possibleMovesVector.at(i).isEmpty()){
                std::cout << possibleMovesVector.at(i);
			if((it+1) != possibleMovesVector.end()){
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

				if(!this->Ai) {
					std::cin.clear(); // reset input, handling situations where input leaks to next play.
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
            }else{
				std::cout << "Error, not a valid move," << std::endl;
				std::cout << "Please choose one of the valid moves above." << std::endl;

				std::cin.clear(); // reset failbit
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input

			}
		}
		possibleMovesVector.clear();
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
	std::vector<Cell> vector;
	vector = this->gameBoard->possibleMoves(this->color);

	if(vector.empty()){
		vector.clear();
		return false;
	}

	if(vector.at(0).isEmpty()){
		vector.clear();
		return true;
	}

	vector.clear();
	return false;

}

/**
 * The function sets if the player is an Ai.
 * @param isAi - a bool containing true if the player is an Ai.
 */
void Player::setAi(bool isAi){
	this->Ai = isAi;
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
