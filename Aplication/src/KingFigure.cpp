#include "include/KingFigure.h"
#include <QDebug>

KingFigure::KingFigure(QObject *parent)
: Figure(parent)
{
	(color() == Figure::WHITE) ?
	setPicture("qrc:/qml/Pictures/whiteKing.svg"):
	setPicture("qrc:/qml/Pictures/blackKing.svg");
}


void KingFigure::move()
{
	qDebug("KingFigure move");
}