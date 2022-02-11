#include "include/QueenFigure.h"
#include <QDebug>

QueenFigure::QueenFigure(QObject *parent)
	: Figure(parent)
{

}


void QueenFigure::move()
{
	qDebug("QueenFigure move");
}

void QueenFigure::info()
{
	Figure::info();
	qDebug() << "rank QueenFigure";
}

void QueenFigure::setColor(Color newColor)
{
	Figure::setColor(newColor);

	(color() == Figure::WHITE) ?
				setPicture("qrc:/qml/Pictures/whiteQueen.svg"):
				setPicture("qrc:/qml/Pictures/blackQueen.svg");
}