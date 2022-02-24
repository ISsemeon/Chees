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

	virtual void info() override;

	virtual void setColor(Color newColor) override;

	virtual QVector<Position> getFreePositions() override;

	virtual QVector<Position> getMoveablePositions(QVector<Position> pos) override;
};

