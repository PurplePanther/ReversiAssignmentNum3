
#include "gtest/gtest.h"
#include "ReversiBoard.h"

//Testing the constructor method of ReversiBoard.
TEST(ReversiBoardTest, checkConstructor) {
	ReversiBoard test = ReversiBoard(8,8);

	EXPECT_EQ(test.getSizeX(),8);
	EXPECT_EQ(test.getSizeY(),8);

	//checking if The first four pieces are in the center.
	EXPECT_EQ(test.getBoard()[8/2-1][8/2-1].isEmpty(),false);
	EXPECT_EQ(test.getBoard()[8/2][8/2].isEmpty(),false);
	EXPECT_EQ(test.getBoard()[8/2-1][8/2].isEmpty(),false);
	EXPECT_EQ(test.getBoard()[8/2][8/2-1].isEmpty(),false);

	//checking if the first four pieces are indeed in the correct colors.
	EXPECT_EQ(test.getBoard()[8/2-1][8/2-1].getColor(),0);
	EXPECT_EQ(test.getBoard()[8/2][8/2].getColor(),0);
	EXPECT_EQ(test.getBoard()[8/2-1][8/2].getColor(),1);
	EXPECT_EQ(test.getBoard()[8/2][8/2-1].getColor(),1);

}

//Testing the board counting method.
TEST(ReversiBoardTest, checkCounting){
	ReversiBoard test = ReversiBoard(8,8);

	EXPECT_EQ(test.countOCells(),2);
	EXPECT_EQ(test.countXCells(),2);

	test.placePiece(0,1,1);
	test.placePiece(0,1,2);
	test.placePiece(1,7,7);

	EXPECT_EQ(test.countOCells(),4);
	EXPECT_EQ(test.countXCells(),3);

}

//checking if Place piece, flip cells function & connectionWith are working.
//Place piece function uses the flip cells function && the connectionWith function.
TEST(ReversiBoardTest, checkPlacePiece){
	ReversiBoard test = ReversiBoard(4,4);

	EXPECT_EQ(test.countOCells(),2);
	EXPECT_EQ(test.countXCells(),2);

	test.placePiece(0,2,4);


	EXPECT_EQ(test.countOCells(),4);
	EXPECT_EQ(test.countXCells(),1);

	test.placePiece(1,3,4);

	EXPECT_EQ(test.countOCells(),3);
	EXPECT_EQ(test.countXCells(),3);

}

//checking the possible moves function
TEST(ReversiBoardTest, checkPossibleMoves){
	ReversiBoard test = ReversiBoard(4,4);

	std::vector<Cell> possibleMovesForO;
	std::vector<Cell> TestPossibleMoves;

	TestPossibleMoves = test.possibleMoves(0);

	//inserting the possible moves for the O player.
	possibleMovesForO.push_back(Cell(0,2));
	possibleMovesForO.push_back(Cell(1,3));
	possibleMovesForO.push_back(Cell(2,0));
	possibleMovesForO.push_back(Cell(3,1));

	//checking if the returned moves from the function match the possible moves.
	bool expected = true;
    std::vector<Cell>::iterator it;
    int i = 0;
   	for ( it = TestPossibleMoves.begin(); it != TestPossibleMoves.end(); it++,i++){
   		if((TestPossibleMoves.at(i).getX() != possibleMovesForO.at(i).getX())
   				|| (TestPossibleMoves.at(i).getY() != possibleMovesForO.at(i).getY())){
   			expected = false;
   		}

   	}
   	possibleMovesForO.clear();
   	TestPossibleMoves.clear();
   	EXPECT_EQ(true,expected);


}


