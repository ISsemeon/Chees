#pragma once

//base unit in chess

#include <QObject>
#include <QVector>
#include <include/Position.h>
#include <include/Constants.h>



class Figure : public QObject
{
	Q_OBJECT

	Q_PROPERTY(int  xBoard READ xBoard WRITE setX NOTIFY xChanged)
	Q_PROPERTY(int  yBoard READ yBoard WRITE setY NOTIFY yChanged)
	Q_PROPERTY(QString picture READ picture WRITE setPicture NOTIFY pictureChanged)
	Q_PROPERTY(bool alive READ isAlive WRITE setAlive NOTIFY AliveChanged)
	Q_PROPERTY(bool itsTurn READ itsTurn WRITE setTurn NOTIFY itsTurnChanged)
	Q_PROPERTY(bool selected READ isSlected WRITE setSelected NOTIFY selectedChanged)
	Q_PROPERTY(Color color READ color  WRITE setColor NOTIFY colorChanged)
	Q_PROPERTY(bool lightning READ lightning WRITE setLightning NOTIFY lightningChanged)
	Q_PROPERTY(bool hovered READ hovered WRITE setHovered NOTIFY hoveredChanged)
	Q_PROPERTY(ArmyPosition position READ position WRITE setPosition CONSTANT)


public:

	Figure(QObject* parent = nullptr);
	//	Q_DISABLE_COPY(Figure)
	virtual ~Figure(){};

	int xBoard() const;
	int yBoard() const;
	const QString& picture() const;
	bool isAlive() const;
	bool isSlected() const;
	Color color() const;
	bool itsTurn() const;
	const bool& lightning() const;
	bool hovered() const;
	ArmyPosition position() const;

	void setX(int newX);
	void setY(int newY);
	void setAlive(bool newAlive);
	void setSelected(bool newSelected);
	void setPicture(QString picture);
	void setTurn(bool newItsTurn);
	virtual void setColor(Color newColor);
	void setHovered(bool newHovered);
	void setPosition(ArmyPosition newPosition);
	void setLightning(const bool& newLightning);

	virtual void info();

	virtual QVector<Position> getFreePositions() = 0;
	virtual QVector<Position> getMoveablePositions(QVector<Position> pos) = 0;

signals:
	void xChanged();
	void yChanged();
	void AliveChanged();
	void selectedChanged();
	void pictureChanged();
	void itsTurnChanged();
	void lightningChanged();
	void hoveredChanged();
	void colorChanged();

private:
	int m_x;
	int m_y;
	QString m_picture;
	bool m_alive;
	bool m_selected;
	Color m_color;
	bool m_itsTurn;
	bool m_lightning;
	bool m_hovered;
	ArmyPosition m_position;
};


