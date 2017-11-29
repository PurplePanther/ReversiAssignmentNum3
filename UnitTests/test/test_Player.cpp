/*
 * test_Player.cpp
 *
*/
#include "gtest/gtest.h"
#include "Player.h"
#include "OfflinePlayer.h"
#include "ReversiBoard.h"
#include "Cell.h"

//Testing the Player's Constructor.
TEST(PlayerTest,checkConstructor){
	Player *test = new OfflinePlayer(1);
	EXPECT_EQ(test->getColor(),1);

	delete test;
}

//Testing the getColor method.
TEST(PlayerTest,checkGetColor){
	Player *test = new OfflinePlayer(1);
	Player *test2 = new OfflinePlayer(0);

	EXPECT_EQ(test->getColor(),1);
	EXPECT_EQ(test2->getColor(),0);

	delete test;
	delete test2;
}

//Testing the getScore method.
TEST(PlayerTest,checkGetScore){
	ReversiBoard* board = new ReversiBoard(8,8);
	Player *test= new OfflinePlayer(1);
	Player *test2= new OfflinePlayer(0);

	test->setGameBoard(board);
	test2->setGameBoard(board);

	EXPECT_EQ(test->getScore(),2);
	EXPECT_EQ(test2->getScore(),2);

	delete board;
	delete test;
	delete test2;
}

//Testing the playOneMove method.
TEST(PlayerTest,checkPlayOneMove){
	ReversiBoard* board= new ReversiBoard(8,8);
	Player *test = new OfflinePlayer(1);
	test->setGameBoard(board);
	EXPECT_EQ(test->getScore(),2);
	EXPECT_EQ(test->hasValidMoves(),true);

	delete board;
	delete test;
}

//Testing the hasValidMoves method.
TEST(PlayerTest,checkHasValidMoves){
	ReversiBoard* board= new ReversiBoard(4,4);
	Player *test= new OfflinePlayer(0);
	test->setGameBoard(board);
	EXPECT_EQ(test->hasValidMoves(),true);

	delete board;
	delete test;
}

//Testing the setGameBoard method.
TEST(PlayerTest,checkSetGameBoard){
	ReversiBoard *board= new ReversiBoard(4,4);
	Player *test= new OfflinePlayer(1);
	test->setGameBoard(board);
	if(test->getScore()==2){
		ASSERT_TRUE(true);
	}
	else{
		ASSERT_TRUE(false);
	}

	delete board;
	delete test;

}
