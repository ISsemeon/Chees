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
 	virtual QVector<Position> getFreePositions() override;

	void info()override;

	virtual void setColor(Color newColor) override;

	virtual QVector<Position> getMoveablePositions(QVector<Position> pos) override;
};

