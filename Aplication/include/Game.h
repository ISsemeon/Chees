#pragma once

#include <QObject>

class Game: public QObject
{
public:
	Game(QObject *parent = nullptr);

private:
	void registrateObjects();

};

