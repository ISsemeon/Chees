#pragma once

#include <include/PawnFigure.h>
#include <include/KingFigure.h>
#include <include/BishopFigure.h>
#include <include/QueenFigure.h>
#include <include/KnightFigure.h>
#include <include/RookFigure.h>

#include <include/Figure.h>

#include <vector>

using pawnVector =std::vector<std::unique_ptr<PawnFigure>>;

template<class T>
using unitPair = std::pair<T , T>;

class ChessArmyBuilder
{
public:
	enum ArmyPosition
	{
		UP,
		DOWN
	};

	enum KEY_POSITION
	{
		A,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		BoardSize
	};

	enum NUMBER_POSITION
	{
		ONE,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT
	};

	ChessArmyBuilder();
	~ChessArmyBuilder();

	void newArmy(Figure::Color armyColor, ChessArmyBuilder::ArmyPosition position);

	std::vector<Figure*> getArmy();

#ifdef DEBUG_MODE
	void info();
#endif
private:

	KingFigure*                                    king;
	QueenFigure*                                queen;

	std::vector<PawnFigure*>            pawnFigures;

	unitPair<BishopFigure*>               bishopPair;
	unitPair<KnightFigure*>               knightPair;
	unitPair<RookFigure*>                  rookPair;

	constexpr void setPositions(ChessArmyBuilder::ArmyPosition position);
	constexpr void setColor(Figure::Color  color);



};


