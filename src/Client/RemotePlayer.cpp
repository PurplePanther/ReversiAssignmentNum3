
#include "RemotePlayer.h"


using namespace std;

/**
 * The constructor method.
 * @param color - the players color.
 * @param gameClient  - the game's client.
 */
RemotePlayer::RemotePlayer(int color, Client* gameClient) : Player(color){
        this->gameClient = gameClient;
        this->setRemote(true);
}

/**
 * the choose move method.
 * @return - returning a cell.
 */
Cell RemotePlayer::chooseMove() {
}

/**
 * The function sends the offline player's play to the server,
 * and then waits for the remote player to send his play back through the server.
 * this function then proceeds to play the remote player's play on the board.
 */
void RemotePlayer::playOneTurn() {

    //the remote player's sign.
    char sign;
    if(this->color == 1) {
        sign = 'X';
    } else {
        sign = 'O';
    }

    //first thing, we update the server about the last play.
    Cell lastPlayed;
    lastPlayed = this->gameBoard->getLastPlay();
    if(lastPlayed.getX()!=-1) {
        this->gameClient->writeCellToServer(lastPlayed);
    }


    cout << "Waiting for other player's move..." << endl;

    //getting the Remote Player's play
    Cell enemyPlay = this->gameClient->readCellFromServer();

    //checking if the returned cell is valid.
    if(enemyPlay.getX() > -1) {
        this->gameBoard->placePiece(this->color, enemyPlay.getX(), enemyPlay.getY());
        //printing the updated board.
        this->gameBoard->printBoard();
        std::cout << sign << " Played" <<"(" << enemyPlay.getX() <<
                  ","<<enemyPlay.getY() <<")"<<std::endl;
    } else {
        //printing the updated board.
        this->gameBoard->printBoard();
        std::cout << "No possible Moves. Play passes back to the other player."
                  << std::endl;
    }


    //setting the last placed piece.
    this->gameBoard->setLastPlay(enemyPlay);




}


