#include <QQmlEngine>
#include <QDebug>

#include "include/Game.h"
#include <include/Board.h>
#include<include/ChessArmy.h>

//figures
#include <include/PawnFigure.h>
#include <include/KingFigure.h>
#include <include/BishopFigure.h>
#include <include/QueenFigure.h>
#include <include/KnightFigure.h>
#include <include/RookFigure.h>




Game::Game(QObject* parent)
	: QObject(parent),
	board{new Board()}
{
	registrateObjects();
	auto  builder = std::make_unique<ChessArmyBuilder>();
	builder->newArmy(Figure::Color::BLACK, ChessArmyBuilder::ArmyPosition::DOWN);

	board->setArmy(builder->getArmy());

	builder->newArmy(Figure::Color::WHITE, ChessArmyBuilder::ArmyPosition::UP);

	board->setArmy(builder->getArmy());
}

void Game::registrateObjects()
{
//	qmlRegisterType<Figure> ("Figures", 1, 0, "BaseFigureQML" );
	qmlRegisterType<PawnFigure> ("Figures", 1, 0, "PawnFigure" );
	qmlRegisterType<KingFigure> ("Figures", 1, 0, "KingFigure" );
	qmlRegisterType<BishopFigure> ("Figures", 1, 0, "BishopFigure" );
	qmlRegisterType<QueenFigure> ("Figures", 1, 0, "QueenFigure" );
	qmlRegisterType<KnightFigure> ("Figures", 1, 0, "KnightFigure" );
	qmlRegisterType<RookFigure> ("Figures", 1, 0, "RookFigure" );
}
