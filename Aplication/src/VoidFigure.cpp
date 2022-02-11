#include "include/VoidFigure.h"

VoidFigure::VoidFigure(QObject *parent) : Figure(parent)
{
	setAlive(false);
	setColor(Figure::NOCOLOR);

}
