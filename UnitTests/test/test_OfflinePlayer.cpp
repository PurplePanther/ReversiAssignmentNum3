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
