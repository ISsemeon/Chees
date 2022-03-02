#pragma once

#include <QVector>
#include <include/Figure.h>

class ChessArmy
{
public:

	ChessArmy(Color armyColor, ArmyPosition position);
	~ChessArmy();

	QVector<Figure*> getArmy();
	void info();

private:

	constexpr void setColor(Color  color);
	void setPosition(ArmyPosition position);

	QVector<Figure* > m_army;
};



