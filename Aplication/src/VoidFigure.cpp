#include "include/VoidFigure.h"
#include <QDebug>

VoidFigure::VoidFigure(QObject *parent) : Figure(parent)
{
	setAlive(false);
	setColor(Figure::NOCOLOR);

}


QVector<Position> VoidFigure::getFreePositions()
{
	return {};
}

QVector<Position> VoidFigure::getMoveablePositions(QVector<Position> pos)
{

}

void VoidFigure::info()
{
	qDebug() << "Void Figure";
}