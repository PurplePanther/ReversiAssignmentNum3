#include "gtest/gtest.h"
#include "ComputerAi.h"
#include "Player.h"
#include "ReversiBoard.h"

TEST(ComputerAiTest, checkConstructor){
	Player* alfred = new ComputerAi(0);

	EXPECT_EQ(alfred->getColor(),0);

	delete alfred;
}

TEST(ComputerAiTest, checkChooseMove){

	Cell firstCell = Cell(1,3);
	Cell chosenCell;
	Player* alfred = new ComputerAi(0);
	ReversiBoard test = ReversiBoard(4,4);
	alfred->setGameBoard(&test);
	chosenCell = alfred->chooseMove();
	EXPECT_EQ(chosenCell.getX(),firstCell.getX());
	EXPECT_EQ(chosenCell.getY(),firstCell.getY());

	delete alfred;
	delete ReversiBoard;

}
