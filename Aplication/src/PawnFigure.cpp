#include "include/PawnFigure.h"
#include <QDebug>

PawnFigure::PawnFigure(QObject *parent)
	: Figure(parent)
{

}


QVector<Position> PawnFigure::getFreePositions()
{
	QVector<Position> result;

	bool leftBoard = xBoard() == 0;
	bool rightBoard = xBoard() == 7;

	bool topPosition = (position() == ArmyPosition::UP);
	bool topAvaliable = (topPosition ? yBoard() != 7 : yBoard() !=0);
	qDebug() << "topAvaliable" << topAvaliable;

	if(firstStep)
	{
		int y = topPosition ? yBoard() + 2 : yBoard() - 2;
		Position point;
		point.m_x = (xBoard());
		point.m_y = (y);
		result.push_back(point);
		firstStep = false;
	}

	//current position
	Position itselfPoint;
	itselfPoint.m_x = (xBoard());
	itselfPoint.m_y = (yBoard());
	result.push_back(itselfPoint);

	if(!topAvaliable){return {};}
	//front positions
	int y = topPosition ? yBoard() + 1 : yBoard() - 1;
	Position point;
	point.m_x = (xBoard());
	point.m_y = (y);
	result.push_back(point);

	if(!leftBoard)
	{
		Position point;
		point.m_x = (xBoard() - 1);
		point.m_y = (y);
		result.push_back(point);
	}
	if(!rightBoard)
	{
		Position point;
		point.m_x = (xBoard() + 1);
		point.m_y = (y);
		result.push_back(point);
	}

	for(auto &i : result)
	{
		qDebug() << "\nx: " << i.m_x << "y: " << i.m_y << "\n";
	}

	return result;
}

void PawnFigure::info()
{
	qDebug() << "PawnFigure";
}

void PawnFigure::setColor(Color newColor)
{
	Figure::setColor(newColor);

	(color() == Color::WHITE) ?
				setPicture("qrc:/qml/Pictures/whitePawn.svg"):
				setPicture("qrc:/qml/Pictures/blackPawn.svg");
}

QVector<Position> PawnFigure::getMoveablePositions(QVector<Position> pos)
{

}