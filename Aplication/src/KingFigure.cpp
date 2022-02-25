#include "include/KingFigure.h"
#include <QDebug>

KingFigure::KingFigure(QObject *parent)
	: Figure(parent)
{}


QVector<Position> KingFigure::getFreePositions()
{
	QVector<Position> result;

	int x = xBoard();
	int y = yBoard();

	Position point;
	point.m_x = (x);
	point.m_y = (y);
	result.push_back(point);

	//check possible sides
	bool leftFree = x > 0;
	bool rightFree = x < 7;
	bool topFree = y > 0;
	bool bottomFree = y < 7;

	if(leftFree)
	{
		Position point;
		point.m_x = (x - 1);
		point.m_y = (y);
		result.push_back(point);
	}
	if(rightFree)
	{
		Position point;
		point.m_x = (x + 1);
		point.m_y = (y);
		result.push_back(point);
	}
	if(topFree)
	{
		Position point;
		point.m_x = (x);
		point.m_y = (y - 1);
		result.push_back(point);
	}
	if(bottomFree)
	{
		Position point;
		point.m_x = (x);
		point.m_y = (y + 1);
		result.push_back(point);
	}
	if(topFree && rightFree)
	{
		Position point;
		point.m_x = (x + 1);
		point.m_y = (y - 1);
		result.push_back(point);
	}
	if(topFree && leftFree)
	{
		Position point;
		point.m_x = (x - 1);
		point.m_y = (y - 1);
		result.push_back(point);
	}
	if(bottomFree && leftFree)
	{
		Position point;
		point.m_x = (x - 1);
		point.m_y = (y + 1);
		result.push_back(point);
	}
	if(bottomFree && rightFree)
	{
		Position point;
		point.m_x = (x + 1);
		point.m_y = (y + 1);
		result.push_back(point);
	}


	return result;
}

void KingFigure::info()
{
	qDebug() << "KingFigure";
}

void KingFigure::setColor(Color newColor)
{
	Figure::setColor(newColor);

	(color() == Figure::WHITE) ?
				setPicture("qrc:/qml/Pictures/whiteKing.svg"):
				setPicture("qrc:/qml/Pictures/blackKing.svg");
}

QVector<Position> KingFigure::getMoveablePositions(QVector<Position> pos)
{
}