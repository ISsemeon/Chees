#pragma once

#include <include/Figure.h>
#include <QObject>

class VoidFigure : public Figure
{
	Q_OBJECT
public:
	explicit VoidFigure(QObject *parent = nullptr);
};

