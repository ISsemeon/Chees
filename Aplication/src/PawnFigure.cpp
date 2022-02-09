#include "include/PawnFigure.h"
#include <QDebug>

PawnFigure::PawnFigure(QObject *parent)
: Figure(parent)
{
	(color() == Figure::WHITE) ?
	setPicture("qrc:/qml/Pictures/whitePawn.svg"):
	setPicture("qrc:/qml/Pictures/blackPawn.svg");
}


void PawnFigure::move()
{
	qDebug("PawnFigure move");
}