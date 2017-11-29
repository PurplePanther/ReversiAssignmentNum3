/*
 * test_Cell.cpp
 */
#include "gtest/gtest.h"
#include "Cell.h"

//Checking if the Cell's Constructor works properly.
TEST(CellTest,checkConstructor){
	Cell test= Cell(2,4);
	EXPECT_EQ(test.x,2);
	EXPECT_EQ(test.y,4);
}
//Checking that getX function truly returns the cell's x value.
TEST(CellTest,check_getX){
	Cell test= Cell(2,4);
	EXPECT_EQ(test.x,test.getX());
}
//Checking that getY function truly returns the cell's y value.
TEST(CellTest,check_getY){
	Cell test= Cell(2,4);
	EXPECT_EQ(test.y,test.getY());
}
//Checking that setXY function truly sets the cell's x,y values.
TEST(CellTest,check_setXY){
	Cell test= Cell(2,4);
	test.setXY(3,5);
	EXPECT_EQ(test.x,3);
	EXPECT_EQ(test.y,5);
}
//Checking that setStatus function truly sets the cell's status.
TEST(CellTest,check_setStatus){
	Cell test= Cell(2,4);
	test.setStatus(true);
	EXPECT_EQ(test.containsValue,true);
	test.setStatus(false);
	EXPECT_EQ(test.containsValue,false);
}
//Checking that setColor function truly sets the cell's color.
TEST(CellTest,check_setColor){
	Cell test= Cell(2,4);
	test.setColor(1);
	EXPECT_EQ(test.color,1);
}
//Checking that isEmpty function truly returns the cell's status.
TEST(CellTest,check_isEmpty){
	Cell test= Cell(2,4);
	test.setStatus(true);
	EXPECT_EQ(test.isEmpty(),false);
}
//Checking that getColor function truly returns the cell's color.
TEST(CellTest,check_getColor){
	Cell test=Cell(2,4);
	EXPECT_EQ(test.color,test.getColor());
}
