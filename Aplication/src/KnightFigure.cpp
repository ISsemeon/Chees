#include "include/KnightFigure.h"
#include <QDebug>

KnightFigure::KnightFigure(QObject *parent)
	: Figure(parent)
{

}

QVector<Position> KnightFigure::getFreePositions()
{
	return {};
}



void KnightFigure::info()
{
	qDebug() << "KnightFigure";
}

void KnightFigure::setColor(Color newColor)
{
	Figure::setColor(newColor);

	(Figure::color() == Figure::WHITE) ?
				setPicture("qrc:/qml/Pictures/whiteKnight.svg"):
				setPicture("qrc:/qml/Pictures/blackKnight.svg");
}

QVector<Position> KnightFigure::getMoveablePositions(QVector<Position> pos)
{
}