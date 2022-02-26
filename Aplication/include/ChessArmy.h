#pragma once

#include <QVector>
#include <include/Figure.h>

class ChessArmy
{
public:

	ChessArmy(Figure::Color armyColor, Figure::ArmyPosition position);
	~ChessArmy();

	QVector<Figure*> getArmy();
	void info();

private:

	constexpr void setColor(Figure::Color  color);
	void setPosition(Figure::ArmyPosition position);

	QVector<Figure* > m_army;
};


