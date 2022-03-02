#include "include/RookFigure.h"
#include <QDebug>

RookFigure::RookFigure(QObject *parent)
	: Figure(parent)
{
}


QVector<Position> RookFigure::getFreePositions()
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

	return result;
}

void RookFigure::info()
{
	qDebug() << "RookFigure";
}

void RookFigure::setColor(Color newColor)
{
	Figure::setColor(newColor);

	(color() == Color::WHITE) ?
				setPicture("qrc:/qml/Pictures/whiteRook.svg"):
				setPicture("qrc:/qml/Pictures/blackRook.svg");
}

QVector<Position> RookFigure::getMoveablePositions(QVector<Position> pos)
{
}