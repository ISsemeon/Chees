#include "include/Board.h"
#include <include/ChessArmy.h>
#include <vector>



Board::Board(QObject* parent)
: QObject(parent)
{

}

void Board::setArmy(std::vector<Figure*> army)
{
	for(auto &i : army)
	{
		i->info();
	}
}
