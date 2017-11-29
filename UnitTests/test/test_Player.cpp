/*
 * test_Player.cpp
 *
*/
#include "gtest/gtest.h"
#include "Player.h"
#include "ReversiBoard.h"
#include "Cell.h"

//Testing the Player's Constructor.
TEST(PlayerTest,checkConstructor){
	Player test= Player(1);
	EXPECT_EQ(test.getColor(),1);
}

//Testing the getColor method.
TEST(PlayerTest,checkGetColor){
	Player test= Player(1);
	Player test2= Player(0);

	EXPECT_EQ(test.getColor(),1);
	EXPECT_EQ(test.getColor(),0);
}

//Testing the getScore method.
TEST(PlayerTest,checkGetScore){
	ReversiBoard board=ReversiBoard(8,8);
	Player test= Player(1);
	Player test2= Player(0);

	test.setGameBoard(board);
	test.setGameBoard(board);

	EXPECT_EQ(test.getScore(),2);
	EXPECT_EQ(test2.getScore(),2);
}

//Testing the playOneMove method.
TEST(PlayerTest,checkPlayOneMove){
	ReversiBoard board=ReversiBoard(8,8);
	Player test= Player(1);
	test.setGameBoard(board);
	EXPECT_EQ(test.getScore(),2);
	if(test.hasValidMoves()){
		test.playOneMove();
		EXPECT_EQ(test.getScore(),3);
	}
	else{
		test.playOneMove();
		EXPECT_EQ(test.getScore(),2);
	}
}

//Testing the hasValidMoves method.
TEST(PlayerTest,checkHasValidMoves){
	ReversiBoard board=ReversiBoard(4,4);
	Player test= Player(0);
	test.setGameBoard(board);
	EXPECT_EQ(test.hasValidMoves(),true);
	board[2][1]=1;
	board[4][3]=1;
	test.setGameBoard(board);
	EXPECT_EQ(test.hasValidMoves(),false);
}

//Testing the setGameBoard method.
TEST(PlayerTest,checkSetGameBoard){
	ReversiBoard board=ReversiBoard(4,4);
	Player test= Player(1);
	test.setGameBoard(board);
	if(test.getScore()==2){
		ASSERT_TRUE(true);
	}
	else{
		ASSERT_TRUE(false);
	}
}
