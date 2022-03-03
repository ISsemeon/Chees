#include "include/KnightFigure.h"
#include <QDebug>

KnightFigure::KnightFigure(QObject *parent)
	: Figure(parent)
{

}

QVector<Position> KnightFigure::getFreePositions()
{
	QVector<Position> result;

	int x = xBoard();
	int y = yBoard();

	// center side

	// rigght top
	if((x + 2) < 8 && (y - 1) >= 0)
	{
		Position point;
		point.m_x = (x + 2);
		point.m_y = (y - 1);
		result.push_back(point);
	}
	// rigght bot
	if((x + 2) < 8 && (y + 1) < 8)
	{
		Position point;
		point.m_x = (x + 2);
		point.m_y = (y + 1);
		result.push_back(point);
	}

	// left top
	if((x - 2) >= 0 && (y - 1) >= 0)
	{
		Position point;
		point.m_x = (x - 2);
		point.m_y = (y - 1);
		result.push_back(point);
	}
	// left bot
	if((x - 2) >= 0 && (y + 1) < 8)
	{
		Position point;
		point.m_x = (x - 2);
		point.m_y = (y + 1);
		result.push_back(point);
	}

	// -------------------- top side

	// top right
	if((x + 1) <= 8 && (y - 2) >= 0)
	{
		Position point;
		point.m_x = (x + 1);
		point.m_y = (y - 2);
		result.push_back(point);
	}

	// top left
	if((x - 1) <= 8 && (y - 2) >= 0)
	{
		Position point;
		point.m_x = (x - 1);
		point.m_y = (y - 2);
		result.push_back(point);
	}

	// bot right
	if((x + 1) <= 8 && (y + 2) < 8)
	{
		Position point;
		point.m_x = (x + 1);
		point.m_y = (y + 2);
		result.push_back(point);
	}

	// bot left
	if((x - 1) <= 8 && (y + 2) < 8)
	{
		Position point;
		point.m_x = (x - 1);
		point.m_y = (y + 2);
		result.push_back(point);
	}


	return result;
}



void KnightFigure::info()
{
	qDebug() << "KnightFigure";
}

void KnightFigure::setColor(Color newColor)
{
	Figure::setColor(newColor);

	(color() == Color::WHITE) ?
				setPicture("qrc:/qml/Pictures/whiteKnight.svg"):
				setPicture("qrc:/qml/Pictures/blackKnight.svg");
}

QVector<Position> KnightFigure::getMoveablePositions(QVector<Position> pos)
{
	return pos;
}