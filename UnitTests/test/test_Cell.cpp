/*
 * test_Cell.cpp
 */
#include "gtest/gtest.h"
#include "Cell.h"

//Checking if the Cell's Constructor works properly.
TEST(CellTest,checkConstructor){
	Cell test= Cell(2,4);
	EXPECT_EQ(test.getX(),2);
	EXPECT_EQ(test.getY(),4);
}

//Checking that setXY function truly sets the cell's x,y values.
TEST(CellTest,check_setXY){
	Cell test= Cell(2,4);
	test.setXY(3,5);
	EXPECT_EQ(test.getX(),3);
	EXPECT_EQ(test.getY(),5);
}
//Checking that setStatus function truly sets the cell's status.
TEST(CellTest,check_setStatus){
	Cell test= Cell(2,4);
	test.setStatus(true);
	EXPECT_EQ(test.isEmpty(),false);
	test.setStatus(false);
	EXPECT_EQ(test.isEmpty(),true);
}
//Checking that setColor function truly sets the cell's color.
TEST(CellTest,check_setColor){
	Cell test= Cell(2,4);
	test.setColor(1);
	EXPECT_EQ(test.getColor(),1);
}
//Checking that isEmpty function truly returns the cell's status.
TEST(CellTest,check_isEmpty){
	Cell test= Cell(2,4);
	test.setStatus(true);
	EXPECT_EQ(test.isEmpty(),false);
}
