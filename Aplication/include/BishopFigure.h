#pragma once

#include "include/Figure.h"
#include <QObject>

class BishopFigure : public Figure
{
	Q_OBJECT
public:
	explicit BishopFigure(QObject *parent = nullptr);

	// Figure interface
public:
 	virtual void move() override;



private:
};

