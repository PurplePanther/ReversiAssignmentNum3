/*
 * test_OfflinePlayer.cpp
 */

#include "gtest/gtest.h"
#include "OfflinePlayer.h"

//Checking if the OfflinePlayer's Constructor works properly.
TEST(OfflinePlayerTest,checkConstructor){
	OfflinePlayer test= OfflinePlayer(1);
	EXPECT_EQ(test.color,1);
}
//Checking correct inputs for the chooseMove function.
TEST(OfflinePlayerTest,checkChooseMove){
	ReversiBoard testBoard=ReversiBoard(8,8);
	OfflinePlayer testPlayer= OfflinePlayer(1);
	Cell testCell=testlayer.chooseMove();
	//Checking if the x value is in the possible range.
	if((testCell.getX()<=8)&&(testCell.getX()>0)){
		ASSERT_TRUE(true);
	}
	else{
		ASSERT_TRUE(false);
	}
	//Checking if the y value is in the possible range.
	if((testCell.getY()<=8)&&(testCell.getY()>0)){
		ASSERT_TRUE(true);
	}
	else{
		ASSERT_TRUE(false);
	}
}
