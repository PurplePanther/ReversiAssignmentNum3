
#include "Game.h"
#include "OfflinePlayer.h"
#include "ComputerAi.h"



/**
 * The constructor method.
 * @param BoardWidth - Board Width.
 * @param BoardLength Board Length.
 */
Game::Game(int gameMode, int BoardWidth, int BoardLength) {
    this->gameMode = gameMode;
	this->gameBoard = new ReversiBoard(BoardWidth, BoardLength);
	this->initialize();
}

/**
 * The init method, the function initializes the game.
 */
void Game::initialize(){

	if(this->gameMode != 3) {
		this->playerOne = new OfflinePlayer(1);
		if (this->gameMode == 1) {
			this->playerTwo = new OfflinePlayer(0);
		} else {
			this->playerTwo = new ComputerAi(0);
		}
	}



	this->playerOne->setGameBoard(this->gameBoard);
	this->playerTwo->setGameBoard(this->gameBoard);

	gameBoard->printBoard();
}

/**
 * the function starts the game loop.
 */
void Game::start(){
	this->gameLoop();
}

/**
 * The function chooses a winner based on each player's score.
 */
void Game::chooseWinner() {
	int scoreX, scoreY;
	scoreX = this->playerOne->getScore();
	scoreY = this->playerTwo->getScore();
	if (scoreX > scoreY) {
		std::cout << "The Winner Is : X with "<<scoreX << "Points!" << std::endl;
	} else if (scoreX < scoreY) {
		std::cout << "The Winner Is : O with "<<scoreY << "Points!" << std::endl;
	} else {
		std::cout << "We Have a Draw!" << std::endl;
	}

}

/**
 * the function plays one game turn.
 */
void Game::playOneTurn() {
	this->playerOne->playOneTurn();
	this->playerTwo->playOneTurn();
}

/**
 * the game loop function which contains the logic of the game.
 */
void Game::gameLoop(){
	bool winCondition = false;
	while(!winCondition) {

		playOneTurn();
		bool bothPlayersCantMove = !this->playerOne->hasValidMoves()
				&& !this->playerTwo->hasValidMoves();

		if (this->gameBoard->isFull() || bothPlayersCantMove) {
			chooseWinner();
			winCondition = true;
		}
	}
}

/**
 * the destructor method which deletes allocated memory.
 */
Game::~Game() {
	delete this->playerOne;
	delete this->playerTwo;
	delete this->gameBoard;
}

