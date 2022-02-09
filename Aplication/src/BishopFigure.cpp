#include "include/BishopFigure.h"
#include <QDebug>

BishopFigure::BishopFigure(QObject *parent)
: Figure(parent)
{
	(color() == Figure::WHITE) ?
	setPicture("qrc:/qml/Pictures/whiteBishop.svg"):
	setPicture("qrc:/qml/Pictures/blackBishop.svg");
}


void BishopFigure::move()
{
	qDebug("move");
}