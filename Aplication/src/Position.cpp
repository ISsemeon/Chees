#include "include/Position.h"

Position::Position():
m_avaliable{false}
{

}

Position::Position(const Position& other)
{
	m_avaliable = other.m_avaliable;
	m_x = other.m_x;
	m_y = other.m_y;
}
