#include "include/Figure.h"
#include <QDebug>

Figure::Figure(QObject* parent)
	: QObject(parent),
	  m_alive{true},
	  m_selected{false},
	  m_color{Figure::Color::WHITE}
	  {}

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

void Figure::move()
{
	qDebug() << "Figure::move";
}

Figure::Color Figure::color() const
{
	return m_color;
}

void Figure::setColor(Figure::Color newColor)
{
	m_color = newColor;
}
