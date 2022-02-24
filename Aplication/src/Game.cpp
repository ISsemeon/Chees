#include <QQmlEngine>
#include <QDebug>

#include "include/Game.h"
#include <include/BoardController.h>
#include<include/ChessArmy.h>

//figures
#include <include/PawnFigure.h>
#include <include/KingFigure.h>
#include <include/BishopFigure.h>
#include <include/QueenFigure.h>
#include <include/KnightFigure.h>
#include <include/RookFigure.h>




Game::Game(QObject* parent)
	: QObject(parent)
{
	registrateObjects();
}



void Game::registrateObjects()
{
//    qmlRegisterType<Figure> ("Figures", 1, 0, "BaseFigureQML" );
//	qmlRegisterType<PawnFigure> ("Figures", 1, 0, "PawnFigure" );
//	qmlRegisterType<KingFigure> ("Figures", 1, 0, "KingFigure" );
//	qmlRegisterType<BishopFigure> ("Figures", 1, 0, "BishopFigure" );
//	qmlRegisterType<QueenFigure> ("Figures", 1, 0, "QueenFigure" );
//	qmlRegisterType<KnightFigure> ("Figures", 1, 0, "KnightFigure" );
//	qmlRegisterType<RookFigure> ("Figures", 1, 0, "RookFigure" );
	qmlRegisterType<BoardController> ("Figures", 1, 0, "Board" );
}


