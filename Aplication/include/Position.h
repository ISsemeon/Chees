#pragma once

#include <QObject>

class Position
{
	Q_GADGET

public:
	Position();
	Position(const Position&other);

	Q_PROPERTY(int x MEMBER m_x)
	Q_PROPERTY(int y  MEMBER m_y)
	Q_PROPERTY(int m_avaliable MEMBER m_avaliable)


	int m_x;
	int m_y;
	bool m_avaliable = false;

};

