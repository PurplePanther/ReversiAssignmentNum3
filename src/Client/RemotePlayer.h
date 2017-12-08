
#ifndef ASS3_REMOTEPLAYER_H
#define ASS3_REMOTEPLAYER_H


#include "Player.h"
#include "Client.h"

class RemotePlayer : virtual public Player {

private:
    Client *gameClient;

public:
    RemotePlayer(int color, Client* gameClient);

    virtual Cell chooseMove();

    virtual void playOneTurn();

};


#endif //ASS3_REMOTEPLAYER_H
