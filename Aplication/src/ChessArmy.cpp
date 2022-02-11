#include "include/ChessArmy.h"

#include <include/PawnFigure.h>
#include <include/KingFigure.h>
#include <include/BishopFigure.h>
#include <include/QueenFigure.h>
#include <include/KnightFigure.h>
#include <include/RookFigure.h>
#include <include/Board.h>

ChessArmy::ChessArmy(Figure::Color armyColor, ChessArmy::ArmyPosition position)
{
	bool checkPositionDown = (position == ArmyPosition::DOWN );

	m_army.reserve(16);

	//add  PawnFigures
	for(int  i = 0; i < 8; i++)
	{
		m_army.push_back(new PawnFigure());
		m_army[i]->setX(i);
		checkPositionDown ? m_army[i]->setY(Board::TWO) : m_army[i]->setY(Board::SEVEN);
	}

	// add BishopFigure
	Figure* leftBishop = new BishopFigure();
	leftBishop->setX(Board::THREE);
	checkPositionDown ? leftBishop->setY(Board::ONE) : leftBishop->setY(Board::EIGHT);

	Figure* rightBishop = new BishopFigure();
	rightBishop->setX(Board::SIX);
	checkPositionDown ? rightBishop->setY(Board::ONE) : rightBishop->setY(Board::EIGHT);

	m_army.push_back(leftBishop);
	m_army.push_back(rightBishop);

	// add KnightFigure

	Figure* leftKnight = new KnightFigure();
	leftKnight->setX(Board::TWO);
	checkPositionDown ? leftKnight->setY(Board::ONE) : leftKnight->setY(Board::EIGHT);

	Figure* rightKnight = new KnightFigure();
	rightKnight->setX(Board::SEVEN);
	checkPositionDown ? rightKnight->setY(Board::ONE) : rightKnight->setY(Board::EIGHT);

	m_army.push_back(leftKnight);
	m_army.push_back(rightKnight);

	//add RookFigure

	Figure* leftRook = new RookFigure();
	leftRook->setX(Board::ONE);
	checkPositionDown ? leftRook->setY(Board::ONE) : leftRook->setY(Board::EIGHT);

	Figure* rightRook = new RookFigure();
	rightRook->setX(Board::EIGHT);
	checkPositionDown ? rightRook->setY(Board::ONE) : rightRook->setY(Board::EIGHT);

	m_army.push_back(leftRook);
	m_army.push_back(rightRook);

	//add Queen

	Figure* queen = new QueenFigure();
	queen->setX(Board::FIVE);
	checkPositionDown ? queen->setY(Board::ONE) : queen->setY(Board::EIGHT);

	m_army.push_back(queen);

	//add King

	Figure* king = new KingFigure();
	king->setX(Board::FOUR);
	checkPositionDown ? king->setY(Board::ONE) : king->setY(Board::EIGHT);

	m_army.push_back(queen);

	m_army.shrink_to_fit();

//==================
	setColor(armyColor);
}

ChessArmy::~ChessArmy()
{
}

QVector<Figure*> ChessArmy::getArmy()
{
	return m_army;
}



constexpr void ChessArmy::setColor(Figure::Color color)
{
	for(auto &i : m_army)
	{
		i->setColor(color);
	}
}


void ChessArmy::info()
{
		for(auto &i : m_army)
	{
		i->info();
	}
}







