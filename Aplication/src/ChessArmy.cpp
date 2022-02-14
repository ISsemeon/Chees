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
	checkPositionDown ? leftBishop->setY(Board::EIGHT) : leftBishop->setY(Board::ONE);

	Figure* rightBishop = new BishopFigure();
	rightBishop->setX(Board::SIX);
	checkPositionDown ? rightBishop->setY(Board::EIGHT) : rightBishop->setY(Board::ONE);

	// add KnightFigure

	Figure* leftKnight = new KnightFigure();
	leftKnight->setX(Board::TWO);
	checkPositionDown ? leftKnight->setY(Board::EIGHT) : leftKnight->setY(Board::ONE);

	Figure* rightKnight = new KnightFigure();
	rightKnight->setX(Board::SEVEN);
	checkPositionDown ? rightKnight->setY(Board::EIGHT) : rightKnight->setY(Board::ONE);

	//add RookFigure

	Figure* leftRook = new RookFigure();
	leftRook->setX(Board::ONE);
	checkPositionDown ? leftRook->setY(Board::EIGHT) : leftRook->setY(Board::ONE);

	Figure* rightRook = new RookFigure();
	rightRook->setX(Board::EIGHT);
	checkPositionDown ? rightRook->setY(Board::EIGHT) : rightRook->setY(Board::ONE);

	//add Queen

	Figure* queen = new QueenFigure();
	queen->setX(Board::FOUR);
	checkPositionDown ? queen->setY(Board::EIGHT) : queen->setY(Board::ONE);

	//add King

	Figure* king = new KingFigure();
	king->setX(Board::FIVE);
	checkPositionDown ? king->setY(Board::EIGHT) : king->setY(Board::ONE);


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
	for(int  i = 7; i >= 0; i--)
	{
		Figure* figure = new PawnFigure();
		figure->setX(i);
		checkPositionDown ? figure->setY(Board::SEVEN) : figure->setY(Board::TWO);
		pawn_vector.push_back(figure);
	}


	// for correction creation
	if(checkPositionDown)
	{
	for(int  i = 0; i < 8; i++)
	{
		m_army.push_front(pawn_vector[i]);
	}
	}
	else
	{
	for(int  i = 0; i < 8; i++)
	{
		m_army.append(pawn_vector[7 - i]);
		}
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







