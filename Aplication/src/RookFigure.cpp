#include "include/RookFigure.h"
#include <QDebug>

RookFigure::RookFigure(QObject *parent)
	: Figure(parent)
{
}


void RookFigure::move()
{
	qDebug("RookFigure move");
}

void RookFigure::info()
{
	Figure::info();
	qDebug() << "rank PawnFigure";
}

void RookFigure::setColor(Color newColor)
{
	Figure::setColor(newColor);

	(color() == Figure::WHITE) ?
				setPicture("qrc:/qml/Pictures/whiteRook.svg"):
				setPicture("qrc:/qml/Pictures/blackRook.svg");
}