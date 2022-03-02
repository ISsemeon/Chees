#include "include/BishopFigure.h"
#include <QDebug>

BishopFigure::BishopFigure(QObject *parent)
	: Figure(parent)
{

}


QVector<Position> BishopFigure::getFreePositions()
{
	QVector<Position> result;
	//up right


	for(int y = yBoard(), x = xBoard(); x <= 7 && y >=0 ;x++, y--)
	{
		Position point;
		point.m_x = (x);
		point.m_y = (y);
		result.push_back(point);
	}

	// up left
	for(int y = yBoard(), x = xBoard(); y >=0 && x >= 0 ; x--, y--)
	{
		Position point;
		point.m_x = (x);
		point.m_y = (y);
		result.push_back(point);
	}

	// down right
	for(int y = yBoard(), x = xBoard(); y <= 7 && x <= 7 ; x++, y++)
	{
		Position point;
		point.m_x = (x);
		point.m_y = (y);
		result.push_back(point);
	}
	// down left
	for(int y = yBoard(), x = xBoard(); y <= 7 && x >= 0 ; x--, y++)
	{
		Position point;
		point.m_x = (x);
		point.m_y = (y);
		result.push_back(point);
	}

	return result;
}

void BishopFigure::info()
{
	qDebug() << "BishopFigure";
}

void BishopFigure::setColor(Color newColor)
{
	Figure::setColor(newColor);

	(color() == Color::WHITE) ?
				setPicture("qrc:/qml/Pictures/whiteBishop.svg"):
				setPicture("qrc:/qml/Pictures/blackBishop.svg");
}

QVector<Position> BishopFigure::getMoveablePositions(QVector<Position> pos)
{
	return pos;
}