#pragma once

#include <QVector>
#include <include/Figure.h>

class ChessArmy
{
public:
	enum ArmyPosition
	{
		UP,
		DOWN
	};

	ChessArmy(Figure::Color armyColor, ChessArmy::ArmyPosition position);
	~ChessArmy();

	QVector<Figure*> getArmy();
	void info();

private:

	constexpr void setColor(Figure::Color  color);

	QVector<Figure* > m_army;
};


