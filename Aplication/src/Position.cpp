#include "include/Position.h"

Position::Position()
{

}

Position::Position(const Position& other)
{
	m_color = other.m_color;
	m_x = other.m_x;
	m_y = other.m_y;
}
