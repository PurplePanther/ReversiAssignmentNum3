
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

	Game* reversi = new Game(gameMode);
	reversi->start();

	delete reversi;
	delete mainMenu;
	return 0;
}

