#include "include/Board.h"
#include <include/ChessArmy.h>
#include <include/VoidFigure.h>
#include <QVector>



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

	for(int i = Board::SIX; i >=Board::THREE ; i--)
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


int Board::rowCount(const QModelIndex& parent) const
{
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

}

QHash<int, QByteArray> Board::roleNames() const
{
	QHash<int, QByteArray> roles;
	roles[Qt::UserRole + 1] = "figure";
	return roles;
}

int Board::columnCount(const QModelIndex& parent) const
{
	return 8;
}