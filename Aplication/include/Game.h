#pragma once

#include <QObject>

class Board;

class Game: public QObject
{
public:
	Game(QObject *parent = nullptr);

private:
	void registrateObjects();
	Board* board;

};

