#pragma once

#include <QObject>
#include <include/BoardController.h>

class Game: public QObject
{
	Q_OBJECT
public:
	explicit Game(QObject *parent = nullptr);



private:
	void registrateObjects();
};

