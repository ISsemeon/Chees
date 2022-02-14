#include "include/Board.h"
#include <include/ChessArmy.h>
#include <include/VoidFigure.h>
#include <QVector>

#include <iostream>



Board::Board(QObject* parent)
	: QAbstractListModel(parent)
{

	// dont change the order of calling methods in constructor!
	ChessArmy army1(Figure::Color::BLACK, ChessArmy::ArmyPosition::DOWN);
	ChessArmy army2(Figure::Color::WHITE, ChessArmy::ArmyPosition::UP);

	m_data.append(army2.getArmy());

	//add void cells

	QVector<Figure* > voidCells;
	voidCells.reserve(32);

	for(int i = Board::THREE; i <= Board::SIX ; i++)
	{
		for (int j = 0 ;j < 8 ; j++ )
		{
			Figure * vf= new VoidFigure();
			vf->setX(j);
			vf->setY(i);
			m_data.push_back(vf);
		}
	}
	m_data.append(army1.getArmy());

}

void Board::swapElements()
{

	showBoardOnConsole();


	auto firstElementIterator = std::find_if(m_data.begin(), m_data.end(), [&](Figure* element){return element->isSlected();});
	if(firstElementIterator== m_data.end()){return;}
	int firstElementIndex = std::distance(m_data.begin(), firstElementIterator);
	m_data[firstElementIndex]->setSelected(false);

	qDebug() << "fe: " << firstElementIndex;

	auto secondElementIterator = std::find_if(m_data.begin(), m_data.end(), [&](Figure* element){return element->isSlected();});
	if(secondElementIterator== m_data.end()){return;}
	int secondElementIndex = std::distance(m_data.begin(), secondElementIterator);
	m_data[secondElementIndex]->setSelected(false);

	qDebug() << "se: " << secondElementIndex;

	std::swap(m_data[firstElementIndex], m_data[secondElementIndex]);
	emit dataChanged(createIndex(0, 0), createIndex(boardSize, boardSize));



	showBoardOnConsole();
}

void Board::changeSelected()
{
	firstItemSelected = !firstItemSelected;
	qDebug() << "changeSelected";
}

bool Board::getSelected()
{
	return firstItemSelected;
}
void Board::showBoardOnConsole()
{

	std::cout << std::endl << "============" << std::endl;
	for(auto i : m_data)
	{
		if( i->xBoard() == 7)
		{
			std::cout << " ("<< i->yBoard() << ":" << i->xBoard()<< ")";
			std::cout << std::endl;
			continue;
		}
		std::cout << " ("<< i->yBoard() << ":" << i->xBoard()<< ")";

	}
}


int Board::rowCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent)
	return 8;
}

QVariant Board::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int column = index.column();

	int elIndex = (BoardSize * row ) + column ;

	switch (role)
	{
	case (Qt::UserRole + 1):
	{
		return QVariant::fromValue(static_cast<QObject *>(m_data[elIndex]));
	}


	}
	return {};
}

QHash<int, QByteArray> Board::roleNames() const
{
	QHash<int, QByteArray> roles;
	roles[Qt::UserRole + 1] = "figure";
	return roles;
}

int Board::columnCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent)
	return 8;
}