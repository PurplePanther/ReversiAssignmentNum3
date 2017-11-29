/******************************************
*Student name: Tal Pogorelis
*Student ID: 318225349
*Exercise #: 2
******************************************/

#ifndef OFFLINEPLAYER_H_
#define OFFLINEPLAYER_H_
#include "Player.h"

/**
 * the offlinePlayer class.
 */
class OfflinePlayer : public Player {
public:
	OfflinePlayer(int color);
	virtual Cell chooseMove();
};

#endif /* OFFLINEPLAYER_H_ */
