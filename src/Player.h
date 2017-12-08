
#ifndef PLAYER_H_
#define PLAYER_H_
#include "ReversiBoard.h"

/**
 * the Player abstract class.
 */
class Player {

protected:
	ReversiBoard* gameBoard;
	int color;
	bool Ai;
public:
	bool isRemote() const;

protected:
	bool Remote;

public:
	Player(int color);
	virtual ~Player();
	int getColor() const;
	int getScore() const;

    virtual void playOneTurn();
	void setGameBoard(ReversiBoard* board);
	bool hasValidMoves();
	virtual Cell chooseMove() =0;

protected:
	void setAi(bool isAi);
	void setRemote(bool Remote);
};

#endif /* PLAYER_H_ */
