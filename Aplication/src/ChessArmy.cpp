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

	// add BishopFigure
	Figure* leftBishop = new BishopFigure();
	leftBishop->setX(Board::THREE);
	checkPositionDown ? leftBishop->setY(Board::ONE) : leftBishop->setY(Board::EIGHT);

	Figure* rightBishop = new BishopFigure();
	rightBishop->setX(Board::SIX);
	checkPositionDown ? rightBishop->setY(Board::ONE) : rightBishop->setY(Board::EIGHT);

	// add KnightFigure

	Figure* leftKnight = new KnightFigure();
	leftKnight->setX(Board::TWO);
	checkPositionDown ? leftKnight->setY(Board::ONE) : leftKnight->setY(Board::EIGHT);

	Figure* rightKnight = new KnightFigure();
	rightKnight->setX(Board::SEVEN);
	checkPositionDown ? rightKnight->setY(Board::ONE) : rightKnight->setY(Board::EIGHT);

	//add RookFigure

	Figure* leftRook = new RookFigure();
	leftRook->setX(Board::ONE);
	checkPositionDown ? leftRook->setY(Board::ONE) : leftRook->setY(Board::EIGHT);

	Figure* rightRook = new RookFigure();
	rightRook->setX(Board::EIGHT);
	checkPositionDown ? rightRook->setY(Board::ONE) : rightRook->setY(Board::EIGHT);

	//add Queen

	Figure* queen = new QueenFigure();
	queen->setX(Board::FIVE);
	checkPositionDown ? queen->setY(Board::ONE) : queen->setY(Board::EIGHT);



	//add King

	Figure* king = new KingFigure();
	king->setX(Board::FOUR);
	checkPositionDown ? king->setY(Board::ONE) : king->setY(Board::EIGHT);


	//add figures in order
	m_army.push_back(leftRook);
	m_army.push_back(leftKnight);
	m_army.push_back(leftBishop);

	m_army.push_back(queen);
	m_army.push_back(king);

	m_army.push_back(rightBishop);
	m_army.push_back(rightKnight);
	m_army.push_back(rightRook);

	QVector<Figure*> pawn_vector;

	//add  PawnFigures
	for(int  i = 0; i < 8; i++)
	{
		Figure* figure = new PawnFigure();
		figure->setX(i);
		checkPositionDown ? figure->setY(Board::TWO) : figure->setY(Board::SEVEN);
		pawn_vector.push_back(figure);
	}


	// for correction creation
	if(checkPositionDown)
	{
	for(int  i = 7; i >= 0; i--)
	{
		m_army.push_front(pawn_vector[i]);
	}
	}
	else
	{
		m_army.append(pawn_vector);
	}

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







