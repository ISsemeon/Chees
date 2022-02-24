#include "include/KingFigure.h"
#include <QDebug>

KingFigure::KingFigure(QObject *parent)
	: Figure(parent)
{}


QVector<Position> KingFigure::getFreePositions()
{
	return {};
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