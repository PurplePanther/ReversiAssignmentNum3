
#include <iostream>
#include <limits>
#include "Menu.h"

/**
 * The constructor function.
 */
Menu::Menu() {
    chooseGameMode();
}

/**
 * the function returns the gameMode.
 * @return - an integer containing the game mode choice of the player.
 */
int Menu::getGameMode() const{
    return this->gameMode;
}

/**
 * the function lets the player choose its gamemode.
 */
void Menu::chooseGameMode(){

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Welcome To" << std::endl;

    //adding some spice to the game with ascii art :) .

    std::string coolLogo = "  _____                         _ \n"
            " |  __ \\                       (_)\n"
            " | |__) |_____   _____ _ __ ___ _ \n"
            " |  _  // _ \\ \\ / / _ \\ '__/ __| |\n"
            " | | \\ \\  __/\\ V /  __/ |  \\__ \\ |\n"
            " |_|  \\_\\___| \\_/ \\___|_|  |___/_|\n"
            "                                  \n"
            "                                  \n"
            "";

    std::cout << coolLogo << std::endl;
    std::cout << "Coded & Developed by Tal & Natalie" << std::endl;
    std::cout << "Please choose one of the game modes below:" << std::endl;
    std::cout << "(1) Play against another Player Offline" << std::endl;
    std::cout << "(2) Play against the Computer | Ai" << std::endl;
    std::cout << "(3) Play Online Against A Remote Player" << std::endl;

    std::cout << std::endl;

    std::cout << "I would like to play: ";
    std::cin >> this->gameMode;

    //making sure input is a valid choice.
    bool validChoice = false;
    while(!validChoice){
        if(this->gameMode < 0 || this->gameMode > 3){
            std::cout << "Option is Unavailable, Please choose another option"<< std::endl;
            std::cout << "I would like to play: ";
            std::cin >> this->gameMode;
            std::cin.clear(); // reset input, handling situations where input leaks to next play.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else{
            validChoice = true;
            std::cin.clear(); // reset input, handling situations where input leaks to next play.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }


}
