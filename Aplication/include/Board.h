#pragma once
#include <QObject>



class ChessArmyBuilder;
class Figure;
class Board : public QObject
{
	Q_OBJECT
private:

public:
	Board(QObject* parent = nullptr);

	 static constexpr  int boardSize {8};

	void setArmy(std::vector<Figure*> army);

};

