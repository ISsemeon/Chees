#pragma once

#include <QObject>
#include <include/Constants.h>

class Position
{
	Q_GADGET

public:
	Position();
	Position(const Position&other);

	Q_PROPERTY(int x MEMBER m_x)
	Q_PROPERTY(int y  MEMBER m_y)
	Q_PROPERTY(Color m_color MEMBER m_color)

	int m_x;
	int m_y;
	Color m_color = Color::NOCOLOR;
};

