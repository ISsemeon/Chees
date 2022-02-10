#pragma once

#include "include/Figure.h"
#include <QObject>

class PawnFigure : public Figure
{
	Q_OBJECT
public:
	explicit PawnFigure(QObject *parent = nullptr);

	// Figure interface
public:
 	virtual void move() override;

	virtual void info() override;
};

