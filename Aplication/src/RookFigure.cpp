#include "include/RookFigure.h"
#include <QDebug>

RookFigure::RookFigure(QObject *parent)
	: Figure(parent)
{
}


QVector<Position> RookFigure::getFreePositions()
{
	return {};
}

void RookFigure::info()
{
	qDebug() << "RookFigure";
}

void RookFigure::setColor(Color newColor)
{
	Figure::setColor(newColor);

	(color() == Figure::WHITE) ?
				setPicture("qrc:/qml/Pictures/whiteRook.svg"):
				setPicture("qrc:/qml/Pictures/blackRook.svg");
}

QVector<Position> RookFigure::getMoveablePositions(QVector<Position> pos)
{
}