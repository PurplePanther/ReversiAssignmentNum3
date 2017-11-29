/******************************************
*Student name: Tal Pogorelis
*Student ID: 318225349
*Exercise #: 2
******************************************/


#ifndef COMPUTERAI_H
#define COMPUTERAI_H


#include "Player.h"

class ComputerAi : virtual public Player {
public:
    //the constructor method.
    ComputerAi(int color);
    //the function calculates and returns a play for the machine.
    virtual Cell chooseMove();

};


#endif //COMPUTERAI_H
