/*
 * test_Menu.cpp
 */

#include "gtest/gtest.h"
#include "Menu.h"

//Testing the getGameMode method.
TEST(MenuTest,checkGetGameMode){
	Menu test=Menu();
	if((test.getGameMode() ==1) ||(test.getGameMode() ==2)){
		ASSERT_TRUE(true);
	}
	else{
		ASSERT_TRUE(false);
	}
}
//Testing the chooseGameMode method.
TEST(MenuTest,checkChooseGameMode){
	Menu test=Menu();
	test.chooseGameMode();
	if((test.getGameMode() ==1) ||(test.getGameMode() ==2)){
		ASSERT_TRUE(true);
	}
	else{
		ASSERT_TRUE(false);
	}
}

