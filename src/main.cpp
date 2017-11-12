/******************************************
*Student name: Tal Pogorelis
*Student ID: 318225349
*Exercise #: 2
******************************************/

#include "Game.h"

/**
 * the main function.
 * @return - an integer.
 */
int main(){
	Game* reversi = new Game(8,8);
	reversi->start();
	delete reversi;
	return 0;
}

