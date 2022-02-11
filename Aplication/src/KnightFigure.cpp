#include "include/KnightFigure.h"
#include <QDebug>

KnightFigure::KnightFigure(QObject *parent)
	: Figure(parent)
{

}


void KnightFigure::move()
{
	qDebug("KnightFigure move");
}

void KnightFigure::info()
{
	Figure::info();
	qDebug() << "rank KnightFigure";
}

void KnightFigure::setColor(Color newColor)
{
	Figure::setColor(newColor);

	(Figure::color() == Figure::WHITE) ?
				setPicture("qrc:/qml/Pictures/whiteKnight.svg"):
				setPicture("qrc:/qml/Pictures/blackKnight.svg");
}