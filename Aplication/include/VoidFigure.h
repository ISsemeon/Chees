#pragma once

#include <include/Figure.h>
#include <QObject>

class VoidFigure : public Figure
{
	Q_OBJECT
public:
	explicit VoidFigure(QObject *parent = nullptr);

	virtual QVector<Position> getFreePositions() override;
	virtual QVector<Position> getMoveablePositions(QVector<Position> pos) override;

	virtual void info() override;
};

