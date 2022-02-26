#include "include/PawnFigure.h"
#include <QDebug>

PawnFigure::PawnFigure(QObject *parent)
	: Figure(parent)
{

}


QVector<Position> PawnFigure::getFreePositions()
{
	QVector<Position> result;

	Position itselfPoint;
	itselfPoint.m_x = (xBoard());
	itselfPoint.m_y = (yBoard());
	result.push_back(itselfPoint);

	bool topPosition = (position() == Figure::ArmyPosition::UP);

	if(firstStep)
	{
		int y = topPosition ? yBoard() + 2 : yBoard() - 2;
		Position point;
		point.m_x = (xBoard());
		point.m_y = (y);
		result.push_back(point);
		firstStep = false;
	}

	int y = topPosition ? yBoard() + 1 : yBoard() - 1;
	Position point;
	point.m_x = (xBoard());
	point.m_y = (y);
	result.push_back(point);

	return result;
}

void PawnFigure::info()
{
	qDebug() << "PawnFigure";
}

void PawnFigure::setColor(Color newColor)
{
	Figure::setColor(newColor);

	(Figure::color() == Figure::WHITE) ?
				setPicture("qrc:/qml/Pictures/whitePawn.svg"):
				setPicture("qrc:/qml/Pictures/blackPawn.svg");
}

QVector<Position> PawnFigure::getMoveablePositions(QVector<Position> pos)
{
}