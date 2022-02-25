#include "include/QueenFigure.h"
#include <QDebug>

QueenFigure::QueenFigure(QObject *parent)
	: Figure(parent)
{

}

QVector<Position> QueenFigure::getFreePositions()
{
	QVector<Position> result;

	Position point;
	point.m_x = (xBoard());
	point.m_y = (yBoard());
	result.push_back(point);

	//right
	for(int x = xBoard(); x < 8; x++)
	{
		Position point;
		point.m_x = (x);
		point.m_y = (yBoard());
		result.push_back(point);
	}

	//left
	for(int x = xBoard(); x >= 0; x--)
	{
		Position point;
		point.m_x = (x);
		point.m_y = (yBoard());
		result.push_back(point);
	}

	//top
	for(int y = yBoard(); y >= 0; y--)
	{
		Position point;
		point.m_x = (xBoard());
		point.m_y = (y);
		result.push_back(point);
	}

	//bottom
	for(int y = yBoard(); y < 8; y++)
	{
		Position point;
		point.m_x = (xBoard());
		point.m_y = (y);
		result.push_back(point);
	}

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


void QueenFigure::info()
{
	qDebug() << "QueenFigure";
}

void QueenFigure::setColor(Color newColor)
{
	Figure::setColor(newColor);

	(color() == Figure::WHITE) ?
				setPicture("qrc:/qml/Pictures/whiteQueen.svg"):
				setPicture("qrc:/qml/Pictures/blackQueen.svg");
}

QVector<Position> QueenFigure::getMoveablePositions(QVector<Position> pos)
{
}