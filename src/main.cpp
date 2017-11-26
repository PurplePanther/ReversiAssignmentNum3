/******************************************
*Student name: Tal Pogorelis
*Student ID: 318225349
*Exercise #: 2
******************************************/

#include "Game.h"
#include "Menu.h"

/**
 * the main function.
 * @return - an integer.
 */
int main(){
    //choosing gameMode.
    Menu* mainMenu = new Menu();
    int gameMode = mainMenu->getGameMode();


	Game* reversi = new Game(gameMode,8,8);
	reversi->start();
	delete reversi;
	delete mainMenu;
	return 0;
}

