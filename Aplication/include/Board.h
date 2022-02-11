#pragma once
#include <QObject>
#include <include/Figure.h>
#include<QVector>
#include<QAbstractListModel>




class Board : public QAbstractListModel
{
	Q_OBJECT
public:
	Board(QObject* parent = nullptr);

	static constexpr  int boardSize {8};

	enum KEY_POSITION
	{
		A,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		BoardSize
	};

	enum NUMBER_POSITION
	{
		ONE,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT
	};

private:
	QVector<Figure*> m_data;

public:
	virtual int rowCount(const QModelIndex& parent) const override;
	virtual QVariant data(const QModelIndex& index, int role) const override;
	virtual QHash<int, QByteArray> roleNames() const override;
	virtual int columnCount(const QModelIndex& parent) const override;
};

