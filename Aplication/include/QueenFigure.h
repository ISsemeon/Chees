#pragma once

#include "include/Figure.h"
#include <QObject>

class QueenFigure : public Figure
{
	Q_OBJECT
public:
	explicit QueenFigure(QObject *parent = nullptr);

	// Figure interface
public:
 	virtual void move() override;

	virtual void info() override;
};

