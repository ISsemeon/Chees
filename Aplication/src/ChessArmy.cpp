#include "include/ChessArmy.h"

ChessArmyBuilder::ChessArmyBuilder()
{}

ChessArmyBuilder::~ChessArmyBuilder()
{
	for(auto &i : pawnFigures)
	{
		i = nullptr;
	}
	king = nullptr;
	queen = nullptr;

	bishopPair.first = nullptr;
	bishopPair.second = nullptr;

	knightPair.first = nullptr;
	knightPair.second = nullptr;

	rookPair.first = nullptr;
	rookPair.second = nullptr;
}

constexpr void ChessArmyBuilder::setPositions(ArmyPosition position)
{
	//set x  position on board
	for(int  i = 0; i < BoardSize; i++)
	{
		pawnFigures[i]->setX(i);
	}
	rookPair.first->setX(ONE);
	rookPair.second->setX(EIGHT);

	knightPair.first->setX(TWO);
	knightPair.second->setX(SEVEN);

	bishopPair.first->setX(THREE);
	bishopPair.second->setX(SIX);

	king->setX(FOUR);
	queen->setX(FIVE);

	//set y  position on board
	bool checkPositionDown = (position == ArmyPosition::DOWN );

	for(int  i = 0; i < 8; i++)
	{
		checkPositionDown ? pawnFigures[i]->setY(TWO) : pawnFigures[i]->setY(SEVEN);
	}

	checkPositionDown ? rookPair.first->setY(ONE) : rookPair.first->setY(EIGHT);
	checkPositionDown ? rookPair.second->setY(ONE) : rookPair.second->setY(EIGHT);

	checkPositionDown ? knightPair.first->setY(ONE) : knightPair.first->setY(EIGHT);
	checkPositionDown ? knightPair.second->setY(ONE) : knightPair.second->setY(EIGHT);

	checkPositionDown ? bishopPair.first->setY(ONE) : bishopPair.first->setY(EIGHT);
	checkPositionDown ? bishopPair.second->setY(ONE) : bishopPair.second->setY(EIGHT);

	checkPositionDown ? queen->setY(ONE) : queen->setY(EIGHT);
	checkPositionDown ? king->setY(ONE) : king->setY(EIGHT);

}

constexpr void ChessArmyBuilder::setColor(Figure::Color color)
{
	for(auto &i : pawnFigures)
	{
		i->setColor(color);
	}
	king->setColor(color);
	queen->setColor(color);

	bishopPair.first->setColor(color);
	bishopPair.second->setColor(color);

	knightPair.first->setColor(color);
	knightPair.second->setColor(color);

	rookPair.first->setColor(color);
	rookPair.second->setColor(color);
}

void ChessArmyBuilder::newArmy(Figure::Color armyColor, ChessArmyBuilder::ArmyPosition position)
{
	pawnFigures.reserve(8);
	for(int  i = 0; i < 8; i++)
	{
		pawnFigures.push_back(new PawnFigure());
	}
	pawnFigures.shrink_to_fit();

	bishopPair = std::make_pair(new BishopFigure, new BishopFigure);
	knightPair = std::make_pair(new KnightFigure, new KnightFigure);
	rookPair = std::make_pair(new RookFigure, new RookFigure);

	queen = new QueenFigure;
	king = new KingFigure;

	setColor(armyColor);
	setPositions(position);
}

std::vector<Figure*> ChessArmyBuilder::getArmy()
{
	std::vector<Figure*> buffer;
	buffer.reserve(16);

	buffer.push_back(king);
	buffer.push_back(queen);

	buffer.push_back(knightPair.first);
	buffer.push_back(knightPair.second);

	buffer.push_back(rookPair.first);
	buffer.push_back(rookPair.second);

	buffer.push_back(bishopPair.first);
	buffer.push_back(bishopPair.second);

	for(auto &i : pawnFigures)
	{
		buffer.push_back(i);
	}
	return buffer;
}

#ifdef DEBUG_MODE
void ChessArmyBuilder::info()
{
	king->info();
	queen->info();
	bishopPair.first->info();
	bishopPair.second->info();
	knightPair.first->info();
	knightPair.second->info();
	rookPair.first->info();
	rookPair.second->info();

	for(auto &i : pawnFigures)
	{
		i->info();
	}

}
#endif






