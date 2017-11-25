/******************************************
*Student name: Tal Pogorelis
*Student ID: 318225349
*Exercise #: 2
******************************************/


#include "ComputerAi.h"

/**
 * The constructor method.
 * @param color - the player's color
 */
ComputerAi::ComputerAi(int color) : Player(color) {
}


/**
 * The function computes the Ai's next move.
 * @return - a Cell containing the X,Y values of the next move.
 */
Cell ComputerAi::chooseMove() {

    int x, y;
    Cell possibleMove;
    ReversiBoard* board = this->gameBoard;
    int currentplayer = this->color;
    ReversiBoard* tempBoard;
    std::vector<Cell> possibleAIMoves = board->possibleMoves(currentplayer);
    for (int i = 0; i < sizeof(possibleAIMoves); ++i) {
        possibleMove = possibleAIMoves[i];
        tempBoard = new ReversiBoard();
        tempBoard = board;
        tempBoard->placePiece(currentplayer,possibleAIMoves[i].getX(),possibleAIMoves[i].getY());




        delete tempBoard;
    }

    Cell chosenXY = Cell(x,y);
    return chosenXY;

}
