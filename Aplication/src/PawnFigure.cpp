#include "include/PawnFigure.h"
#include <QDebug>

PawnFigure::PawnFigure(QObject *parent)
	: Figure(parent)
{

}


QVector<Position> PawnFigure::getFreePositions()
{
	QVector<Position> result;

	bool leftBoard = xBoard() == 0;
	bool rightBoard = xBoard() == 7;

	bool topPosition = (position() == ArmyPosition::UP);
	bool topAvaliable = (topPosition ? yBoard() != 7 : yBoard() !=0);

	if(firstStep)
	{
		int y = topPosition ? yBoard() + 2 : yBoard() - 2;
		Position point;
		point.m_x = (xBoard());
		point.m_y = (y);
		result.push_back(point);
		firstStep = false;
	}

	//current position
	Position itselfPoint;
	itselfPoint.m_x = (xBoard());
	itselfPoint.m_y = (yBoard());
	result.push_back(itselfPoint);

	if(!topAvaliable){return {};}
	//front positions
	int y = topPosition ? yBoard() + 1 : yBoard() - 1;
	Position point;
	point.m_x = (xBoard());
	point.m_y = (y);
	result.push_back(point);

	if(!leftBoard)
	{
		Position point;
		point.m_x = (xBoard() - 1);
		point.m_y = (y);
		result.push_back(point);
	}
	if(!rightBoard)
	{
		Position point;
		point.m_x = (xBoard() + 1);
		point.m_y = (y);
		result.push_back(point);
	}

	return result;
}

void PawnFigure::info()
{
	qDebug() << "PawnFigure";
}

void PawnFigure::setColor(Color newColor)
{
	Figure::setColor(newColor);

	(color() == Color::WHITE) ?
				setPicture("qrc:/qml/Pictures/whitePawn.svg"):
				setPicture("qrc:/qml/Pictures/blackPawn.svg");
}

QVector<Position> PawnFigure::getMoveablePositions(QVector<Position> pos)
{
	bool topPosition = (position() == ArmyPosition::UP);

	// check possibility going strait
	int y = topPosition ? yBoard() + 1 : yBoard() - 1;
	Position point;
	point.m_x = (xBoard());
	point.m_y = (y);

	auto removeTopPosition = std::remove_if(pos.begin(), pos.end(), [&](Position val)
	{
			return val.m_x == point.m_x &&
			val.m_y == point.m_y &&
			val.m_color != Color::NOCOLOR;
});
	//remove the ability of the pawn to step over the enemy figure on the first move
	if(removeTopPosition != pos.end())
	{
		int y2= topPosition ? yBoard() + 2 : yBoard() - 2;
		Position point;
		point.m_x = (xBoard());
		point.m_y = (y2);

		auto removeStepOverPosition = std::remove_if(pos.begin(), pos.end(), [&](Position val)
		{
				return val.m_x == point.m_x &&
				val.m_y == point.m_y;
	});
		pos.erase(removeStepOverPosition, pos.end());
	}
	pos.erase(removeTopPosition, pos.end());

	// check possibility going strait left
	Position topLeft;
	topLeft.m_x = (xBoard() - 1);
	topLeft.m_y = (y);

	auto removeTopLeftPosition = std::remove_if(pos.begin(), pos.end(), [&](Position val)
	{
			return val.m_x == topLeft.m_x &&
			val.m_y == topLeft.m_y &&
			(val.m_color == color() || val.m_color == Color::NOCOLOR);
});
	pos.erase(removeTopLeftPosition, pos.end());

	// check possibility going strait right
	Position topRight;
	topRight.m_x = (xBoard() + 1);
	topRight.m_y = (y);

	auto removeTopRightPosition =std::remove_if(pos.begin(), pos.end(), [&](Position val)
	{
			return val.m_x == topRight.m_x &&
			val.m_y == topRight.m_y &&
			(val.m_color == color() || val.m_color == Color::NOCOLOR);
});
	pos.erase(removeTopRightPosition, pos.end());

	// removal of the ability to move to a piece through 2 cells on the first move
	int y2= topPosition ? yBoard() + 2 : yBoard() - 2;
	Position doubleTop;
	topRight.m_x = (xBoard() + 1);
	topRight.m_y = (y2);

	auto removeDoubleTopPosition =std::remove_if(pos.begin(), pos.end(), [&](Position val)
	{
			return val.m_x == topRight.m_x &&
			val.m_y == topRight.m_y &&
			color() != Color::NOCOLOR;
});
	pos.erase(removeDoubleTopPosition, pos.end());

	return pos;
}