#include "include/QueenFigure.h"
#include <QDebug>

QueenFigure::QueenFigure(QObject *parent)
: Figure(parent)
{
	(color() == Figure::WHITE) ?
	setPicture("qrc:/qml/Pictures/whiteQueen.svg"):
	setPicture("qrc:/qml/Pictures/blackQueen.svg");
}


void QueenFigure::move()
{
	qDebug("QueenFigure move");
}