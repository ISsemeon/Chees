#include "include/Figure.h"
#include <QDebug>

Figure::Figure(QObject* parent)
	: QObject(parent),
	  m_alive{true},
	  m_selected{false},
	  m_color{Figure::Color::WHITE},
	  m_lightning{false},
	  m_hovered{false}{}


int Figure::xBoard() const
{
	return m_x;
}

void Figure::setX(int newX)
{
	if (m_x == newX)
		return;
	m_x = newX;
	emit xChanged();
}

int Figure::yBoard() const
{
	return m_y;
}

void Figure::setY(int newY)
{
	if (m_y == newY)
		return;
	m_y = newY;
	emit yChanged();
}

const QString& Figure::picture() const
{
	return m_picture;
}

bool Figure::isAlive() const
{
	return m_alive;
}

void Figure::setAlive(bool newAlive)
{
	if (m_alive == newAlive)
		return;
	m_alive = newAlive;
	emit AliveChanged();
}

bool Figure::isSlected() const
{
	return m_selected;
}

void Figure::setSelected(bool newSelected)
{
	if (m_selected == newSelected)
		return;
	m_selected = newSelected;
	emit selectedChanged();
}

void Figure::setPicture(QString picture)
{
	if (m_picture == picture)
		return;
	m_picture = picture;
	emit pictureChanged();
}


void Figure::info()
{
	qDebug() << "x : " << xBoard();
	qDebug() << "y : " << yBoard();

	color() == Color::WHITE ? qDebug() << "color White" : 	qDebug() << "color Black";
	qDebug() << "alive " << isAlive();
}



Figure::Color Figure::color() const
{
	return m_color;
}

void Figure::setColor(Figure::Color newColor)
{
	m_color = newColor;
}

bool Figure::itsTurn() const
{
	return m_itsTurn;
}

void Figure::setTurn(bool newItsTurn)
{
	if (m_itsTurn == newItsTurn)
		return;
	m_itsTurn = newItsTurn;
	emit itsTurnChanged();
}

const bool& Figure::lightning() const
{
	return m_lightning;
}

void Figure::setLightning(const bool& newLightning)
{
	if (m_lightning == newLightning)
		return;
	m_lightning = newLightning;
	emit lightningChanged();
}

bool Figure::hovered() const
{
	return m_hovered;
}

void Figure::setHovered(bool newHovered)
{
	if (m_hovered == newHovered)
		return;
	m_hovered = newHovered;
	emit hoveredChanged();
}
