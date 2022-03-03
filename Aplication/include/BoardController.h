#pragma once
#include <QObject>
#include <include/Figure.h>
#include<QVector>
#include<QAbstractListModel>
#include <include/Position.h>




class BoardController : public QAbstractListModel
{
	Q_OBJECT
public:
	BoardController(QObject* parent = nullptr);

	static constexpr  int boardSize {8};

	Q_INVOKABLE void tryMove();

	Q_INVOKABLE void changeSelected();
	Q_INVOKABLE bool getSelected();

	Q_INVOKABLE void showPossiblePositions();

	Q_INVOKABLE void turnOfLightning();


	enum KEY_POSITION
	{
		A,
		B,
		C,
		D,
		E,
		F,
		G,
		H
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

public:
	virtual int rowCount(const QModelIndex& parent) const override;
	virtual QVariant data(const QModelIndex& index, int role) const override;
	virtual QHash<int, QByteArray> roleNames() const override;
	virtual int columnCount(const QModelIndex& parent) const override;
	void showBoardOnConsole();
private:
	QVector<Figure*> m_figures;
	QVector<Figure*> m_diedFigures;
	bool firstItemSelected = false;



	//game controlling
	void kill(int index);
	void swapPositions(int firstIndex, int secondIndex);
	bool positionContainsFigure(int index);
};

