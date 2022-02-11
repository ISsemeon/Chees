#include "include/PawnFigure.h"
#include <QDebug>

PawnFigure::PawnFigure(QObject *parent)
	: Figure(parent)
{

}


void PawnFigure::move()
{
	qDebug("PawnFigure move");
}

void PawnFigure::info()
{
	Figure::info();
	qDebug() << "rank PawnFigure";
}

void PawnFigure::setColor(Color newColor)
{
	Figure::setColor(newColor);

	(Figure::color() == Figure::WHITE) ?
				setPicture("qrc:/qml/Pictures/whitePawn.svg"):
				setPicture("qrc:/qml/Pictures/blackPawn.svg");
}