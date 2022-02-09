#include "include/KnightFigure.h"
#include <QDebug>

KnightFigure::KnightFigure(QObject *parent)
: Figure(parent)
{
	(color() == Figure::WHITE) ?
	setPicture("qrc:/qml/Pictures/whiteKnight.svg"):
	setPicture("qrc:/qml/Pictures/blackKnight.svg");
}


void KnightFigure::move()
{
	qDebug("KnightFigure move");
}