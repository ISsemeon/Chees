#include "include/ChessArmy.h"

#include <include/PawnFigure.h>
#include <include/KingFigure.h>
#include <include/BishopFigure.h>
#include <include/QueenFigure.h>
#include <include/KnightFigure.h>
#include <include/RookFigure.h>
#include <include/BoardController.h>

ChessArmy::ChessArmy(Figure::Color armyColor, Figure::ArmyPosition position)
{
	bool checkPositionDown = (position == Figure::DOWN );

	// add BishopFigure
	Figure* leftBishop = new BishopFigure();
	leftBishop->setX(BoardController::THREE);
	checkPositionDown ? leftBishop->setY(BoardController::EIGHT) : leftBishop->setY(BoardController::ONE);

	Figure* rightBishop = new BishopFigure();
	rightBishop->setX(BoardController::SIX);
	checkPositionDown ? rightBishop->setY(BoardController::EIGHT) : rightBishop->setY(BoardController::ONE);

	// add KnightFigure

	Figure* leftKnight = new KnightFigure();
	leftKnight->setX(BoardController::TWO);
	checkPositionDown ? leftKnight->setY(BoardController::EIGHT) : leftKnight->setY(BoardController::ONE);

	Figure* rightKnight = new KnightFigure();
	rightKnight->setX(BoardController::SEVEN);
	checkPositionDown ? rightKnight->setY(BoardController::EIGHT) : rightKnight->setY(BoardController::ONE);

	//add RookFigure

	Figure* leftRook = new RookFigure();
	leftRook->setX(BoardController::ONE);
	checkPositionDown ? leftRook->setY(BoardController::EIGHT) : leftRook->setY(BoardController::ONE);

	Figure* rightRook = new RookFigure();
	rightRook->setX(BoardController::EIGHT);
	checkPositionDown ? rightRook->setY(BoardController::EIGHT) : rightRook->setY(BoardController::ONE);

	//add Queen

	Figure* queen = new QueenFigure();
	queen->setX(BoardController::FOUR);
	checkPositionDown ? queen->setY(BoardController::EIGHT) : queen->setY(BoardController::ONE);

	//add King

	Figure* king = new KingFigure();
	king->setX(BoardController::FIVE);
	checkPositionDown ? king->setY(BoardController::EIGHT) : king->setY(BoardController::ONE);


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
		checkPositionDown ? figure->setY(BoardController::SEVEN) : figure->setY(BoardController::TWO);
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

	//==================	setColor(armyColor);
	setColor(armyColor);

	setPosition(position);

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

void ChessArmy::setPosition(Figure::ArmyPosition position)
{
	for(auto &i : m_army)
	{
		i->setPosition(position);
	}
}


void ChessArmy::info()
{
	for(auto &i : m_army)
	{
		i->info();
	}
}







