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
 	virtual QVector<Position> getFreePositions() override;

	virtual void info() override;


	virtual void setColor(Color newColor) override;

	// Figure interface
public:
	virtual QVector<Position> getMoveablePositions(QVector<Position> pos) override;
};

