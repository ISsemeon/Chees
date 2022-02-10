#pragma once

#include "include/Figure.h"
#include <QObject>

class KingFigure : public Figure
{
	Q_OBJECT
public:
	explicit KingFigure(QObject *parent = nullptr);

	// Figure interface
public:
 	virtual void move() override;

	virtual void info() override;
};

