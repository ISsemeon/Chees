#pragma once

#include "include/Figure.h"
#include <QObject>

class RookFigure : public Figure
{
	Q_OBJECT
public:
	explicit RookFigure(QObject *parent = nullptr);

	// Figure interface
public:
 	virtual void move() override;

	virtual void info() override;
};

