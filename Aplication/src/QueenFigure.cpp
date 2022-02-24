#include "include/QueenFigure.h"
#include <QDebug>

QueenFigure::QueenFigure(QObject *parent)
	: Figure(parent)
{

}

QVector<Position> QueenFigure::getFreePositions()
{
return {};
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