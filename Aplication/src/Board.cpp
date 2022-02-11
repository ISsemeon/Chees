#include "include/Board.h"
#include <include/ChessArmy.h>
#include <QVector>



Board::Board(QObject* parent)
	: QAbstractListModel(parent)
{

	ChessArmy army1(Figure::Color::BLACK, ChessArmy::ArmyPosition::DOWN);
	ChessArmy army2(Figure::Color::WHITE, ChessArmy::ArmyPosition::UP);


	m_data.append(army1.getArmy());
	m_data.append(army2.getArmy());

}


int Board::rowCount(const QModelIndex& parent) const
{
	return m_data.size();
}

QVariant Board::data(const QModelIndex& index, int role) const
{
	switch (role) {
	case (Qt::UserRole + 1):
	{
		return QVariant::fromValue(static_cast<QObject *>(m_data[index.row()]));
	}

	}

}

QHash<int, QByteArray> Board::roleNames() const
{
	QHash<int, QByteArray> roles;
	roles[Qt::UserRole + 1] = "figure";
	return roles;
}