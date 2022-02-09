#include "include/RookFigure.h"
#include <QDebug>

RookFigure::RookFigure(QObject *parent)
: Figure(parent)
{
	(color() == Figure::WHITE) ?
	setPicture("qrc:/qml/Pictures/whiteRook.svg"):
	setPicture("qrc:/qml/Pictures/blackRook.svg");
}


void RookFigure::move()
{
	qDebug("RookFigure move");
}