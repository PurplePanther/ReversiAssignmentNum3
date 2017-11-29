#include "gtest/gtest.h"
#include "ComputerAi.h"
#include "Player.h"
#include "ReversiBoard.h"

TEST(ComputerAiTest, checkConstructor){
	Player* alfredTheAi = new ComputerAi(0);

	EXPECT_EQ(alfredTheAi->getColor(),0);

	delete alfredTheAi;
}

TEST(ComputerAiTest, checkChooseMove){

	Cell firstCell = Cell(1,3);
	Cell chosenCell;
	Player* alfredTheAi = new ComputerAi(0);
	ReversiBoard* testBoard = new ReversiBoard(4,4);

	alfredTheAi->setGameBoard(testBoard);
	chosenCell = alfredTheAi->chooseMove();

	EXPECT_EQ(chosenCell.getX(),firstCell.getX());
	EXPECT_EQ(chosenCell.getY(),firstCell.getY());


	delete alfredTheAi;
	delete testBoard;

}
