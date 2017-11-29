
#ifndef MENU_H
#define MENU_H

/**
 * The menu class.
 */
class Menu {

public:
    //the constructor method.
    Menu();

    //the function returns the game mode that was chosen by the player.
    int getGameMode() const;
private:
    // 1 represents Offline, 2 represents against the machine
    // 3 represents Online(aka multiplayer).
    int gameMode;

    //letting the player choose the gameMode.
    void chooseGameMode();


};


#endif //MENU_H
