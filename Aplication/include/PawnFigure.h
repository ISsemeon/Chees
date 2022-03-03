#pragma once

#include "include/Figure.h"
#include <QObject>

class PawnFigure : public Figure
{
	Q_OBJECT
public:
	explicit PawnFigure(QObject *parent = nullptr);

	virtual QVector<Position> getFreePositions() override;

	virtual void info() override;

	virtual void setColor(Color newColor) override;

	virtual QVector<Position> getMoveablePositions(QVector<Position> pos) override;

private:
	bool firstStep = true;
};

