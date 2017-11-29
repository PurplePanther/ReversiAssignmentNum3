
#include "gtest/gtest.h"
#include "ReversiBoard.h"
#include "Cell.h"

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
//Testing the initBoard method.
TEST(ReversiBoardTest, checkInitBoard){
	ReversiBoard test = ReversiBoard(8,8);
	EXPECT_EQ(test[3][3].getStatus(),true);
	EXPECT_EQ(test[4][4].getStatus(),true);

	EXPECT_EQ(test[3][3].getColor(),0);
	EXPECT_EQ(test[4][4].getColor(),0);

	EXPECT_EQ(test[3][4].getStatus(),true);
	EXPECT_EQ(test[4][3].getStatus(),true);

	EXPECT_EQ(test[3][4].getColor(),1);
	EXPECT_EQ(test[4][3].getColor(),1);
}

//Testing the flipCellsBetween method.
TEST(ReversiBoardTest, checkFlipCellsBetween){
	ReversiBoard test = ReversiBoard(8,8);
	Cell A=Cell(2,3);
	Cell B=Cell(4,3);
	Cell C=Cell(4,2);
	Cell D=Cell(4,4);
	A.setColor(1);
	test.flipCellsBetween(&A,&B);
	EXPECT_EQ(test[3][3].getColor(),1);//Testing if it flips for color 1.
	C.setColor(0);
	test.flipCellsBetween(&C,&D);
	EXPECT_EQ(test[4][3].getColor(),0);//Testing if it flips for color 0.
}

//Testing the getBoard method.
TEST(ReversiBoardTest, checkGetBoard){
	ReversiBoard test = ReversiBoard(8,8);
	ReversiBoard check=test.getBoard();
	//Checking if the new Board sizes are equal to the original board sizes.
	EXPECT_EQ(check.getSizeX(),8);
	EXPECT_EQ(check.getSizeY(),8);
}

//Testing the isFull method.
TEST(ReversiBoardTest, checkIsFull){
	ReversiBoard test = ReversiBoard(4,4);
	EXPECT_EQ(test.isFull(),false);
	//Filling every cell in the board.
	for(int i=1;i<5:i++){
		for(int j=1:j<5:j++){
			test[i][j]=0;
		}
	}
	EXPECT_EQ(test.isFull(),true);
}
//Testing the pointIsValid method.
TEST(ReversiBoardTest, checkPointIsValid){
	ReversiBoard test = ReversiBoard(8,8);
	EXPECT_EQ(test.pointIsValid(9,4),false);
	EXPECT_EQ(test.pointIsValid(4,9),false);
	EXPECT_EQ(test.pointIsValid(9,9),false);
	EXPECT_EQ(test.pointIsValid(4,4),true);
	EXPECT_EQ(test.pointIsValid(1,8),true);
	EXPECT_EQ(test.pointIsValid(10,-4),false);
	EXPECT_EQ(test.pointIsValid(-9,4),false);
	EXPECT_EQ(test.pointIsValid(-9,-4),false);
}
//Testing the isValidCell method.
TEST(ReversiBoardTest, checkIsValidCell){
	ReversiBoard test = ReversiBoard(8,8);
	EXPECT_EQ(test.isValidCell(3,5,0),true);
	EXPECT_EQ(test.isValidCell(4,2,1),true);
	EXPECT_EQ(test.isValidCell(5,5,0),false);
	EXPECT_EQ(test.isValidCell(3,2,1),true);
	EXPECT_EQ(test.isValidCell(4,5,1),true);
	EXPECT_EQ(test.isValidCell(1,1,1),false);

}
//Testing the connectionsWith method.
TEST(ReversiBoardTest, checkConnectionsWith){
	ReversiBoard test = ReversiBoard(4,4);
	Cell A=Cell(2,2);
	Cell B=Cell(2,4);
	Cell C=Cell(4,2);
	std::vector<cell> connections=test.connectionsWith(&A,0);
	//If the vector is empty.
	if(connections.size()==0){
		ASSERT_TRUE(false);
	}
	connections.push_back(B);
	connections.push_back(C);
	EXPECT_EQ(connections.size(),2);
}
//Testing the getSizeX method.
TEST(ReversiBoardTest, checkGetSizeX){
	ReversiBoard test = ReversiBoard(8,8);
	EXPECT_EQ(test.getSizeX(),8);
}
//Testing the getSizeY method.
TEST(ReversiBoardTest, checkGetSizeY){
	ReversiBoard test = ReversiBoard(8,8);
	EXPECT_EQ(test.getSizeY(),8);
}
//Testing the copyBoard method.
TEST(ReversiBoardTest, checkCopyBoard){
	ReversiBoard test = ReversiBoard(8,8);
	ReversiBoard copy=ReversiBoard(8,8);
	copy[1][1].setColor(1);
	copy[4][7].setColor(1);
	copy[8][8].setColor(0);
	copy[8][1].setColor(0);

	test.copyBoard(copy);
	EXPECT_EQ(test[1][1].getColor(),1);
	EXPECT_EQ(test[4][7].getColor(),1);
	EXPECT_EQ(test[8][8].getColor(),0);
	EXPECT_EQ(test[8][1].getColor(),0);
}

