
#include "Game.h"
#include "OfflinePlayer.h"
#include "ComputerAi.h"
#include "RemotePlayer.h"
#include <stdlib.h>

#define GAME_HAS_ENDED_SIGNAL -5

/**
 * The constructor method.
 * @param BoardWidth - Board Width.
 * @param BoardLength Board Length.
 */
Game::Game(int gameMode, int BoardWidth, int BoardLength) {
    this->gameMode = gameMode;
	this->gameBoard = new ReversiBoard(BoardWidth, BoardLength);
    this->gameClient = new Client();
    this->initialize();
}

/**
 * The init method, the function initializes the game.
 */
void Game::initialize(){
    //playing offline
    if(this->gameMode == 1){
        this->playerOne = new OfflinePlayer(1);
        this->playerTwo = new OfflinePlayer(0);
    }

    //playing against the AI.
    if(this->gameMode == 2){
        this->playerOne = new OfflinePlayer(1);
        this->playerTwo = new ComputerAi(0);
    }

    //playing against a remote player.
    if(this->gameMode == 3){

        //connecting to the game server
        try {
            gameClient->connectToServer();
        } catch (const char *msg){
            std::cout<<"Failed to connect to server. Reason:"<<msg<<std::endl;
            exit(-1);
        }

        //reading the players # & color.
        int result = this->gameClient->readIntFromServer();

        int playerColor = result;

        //player is X (black)
        if(playerColor == 1){
            this->playerOne = new OfflinePlayer(playerColor);
            this->playerTwo = new RemotePlayer(0,this->gameClient);
            std::cout << "Waiting for other player to join..." << std::endl;

            //reading from the server if the second player has connected.
            result = this->gameClient->readIntFromServer();

        }
        //player is O (white)
        if(playerColor == 2){
            this->playerOne = new RemotePlayer(1,this->gameClient);
            this->playerTwo = new OfflinePlayer(0);
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
void Game::gameLoop() {
    bool winCondition = false;
    while (!winCondition) {

        playOneTurn();
        bool bothPlayersCantMove = !this->playerOne->hasValidMoves()
                                   && !this->playerTwo->hasValidMoves();

        if (this->gameBoard->isFull() || bothPlayersCantMove) {
            chooseWinner();
            winCondition = true;

            //sending last played cell.
            if (this->gameMode == 3 && !this->playerTwo->isRemote()) {
                this->gameClient->writeCellToServer(this->gameBoard->getLastPlay());
            }
            //notifying the server that the game has ended.
            if(this->gameMode == 3){
                this->gameClient->writeCellToServer(Cell(GAME_HAS_ENDED_SIGNAL,0));
            }

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
    delete this->gameClient;
}

