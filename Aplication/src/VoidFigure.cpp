#include "include/VoidFigure.h"
#include <QDebug>

VoidFigure::VoidFigure(QObject *parent) : Figure(parent)
{
	setAlive(false);
	setColor(Color::NOCOLOR);
}


QVector<Position> VoidFigure::getFreePositions()
{
	return {};
}

QVector<Position> VoidFigure::getMoveablePositions(QVector<Position> pos)
{
	Q_UNUSED(pos)
	return {};
}

void VoidFigure::info()
{
	qDebug() << "Void Figure";
}