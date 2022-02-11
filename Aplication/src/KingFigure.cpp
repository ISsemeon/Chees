#include "include/KingFigure.h"
#include <QDebug>

KingFigure::KingFigure(QObject *parent)
	: Figure(parent)
{}


void KingFigure::move()
{
	qDebug("KingFigure move");
}

void KingFigure::info()
{
	Figure::info();
	qDebug() << "rank KingFigure";
}

void KingFigure::setColor(Color newColor)
{
	Figure::setColor(newColor);

	(color() == Figure::WHITE) ?
				setPicture("qrc:/qml/Pictures/whiteKing.svg"):
				setPicture("qrc:/qml/Pictures/blackKing.svg");
}