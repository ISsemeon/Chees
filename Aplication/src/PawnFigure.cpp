#include "include/PawnFigure.h"
#include <QDebug>

PawnFigure::PawnFigure(QObject *parent)
	: Figure(parent)
{

}


QVector<Position> PawnFigure::getFreePositions()
{
	return {};
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