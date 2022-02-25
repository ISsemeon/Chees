#include "include/BoardController.h"
#include <include/ChessArmy.h>
#include <include/VoidFigure.h>
#include <QVector>
#include <QDebug>

#include <iostream>

BoardController::BoardController(QObject* parent)
	: QAbstractListModel(parent)
{

	// dont change the order of calling methods in constructor!
	ChessArmy army1(Figure::Color::WHITE, Figure::ArmyPosition::DOWN);
	ChessArmy army2(Figure::Color::BLACK, Figure::ArmyPosition::UP);

	m_figures.append(army2.getArmy());

	//add void cells

	QVector<Figure* > voidCells;
	voidCells.reserve(32);

	for(int i = BoardController::THREE; i <= BoardController::SIX ; i++)
	{
		for (int j = 0 ;j < 8 ; j++ )
		{
			Figure * vf= new VoidFigure();
			vf->setX(j);
			vf->setY(i);
			m_figures.push_back(vf);
		}
	}
	m_figures.append(army1.getArmy());
}

void BoardController::tryMove()
{
	auto firstElementIterator = std::find_if(m_figures.begin(), m_figures.end(), [&](Figure* element){return element->isSlected();});
	if(firstElementIterator== m_figures.end()){return;}
	int firstElementIndex = std::distance(m_figures.begin(), firstElementIterator);
	m_figures[firstElementIndex]->setSelected(false);


	auto secondElementIterator = std::find_if(m_figures.begin(), m_figures.end(), [&](Figure* element){return element->isSlected();});
	if(secondElementIterator== m_figures.end()){return;}
	int secondElementIndex = std::distance(m_figures.begin(), secondElementIterator);
	m_figures[secondElementIndex]->setSelected(false);


	bool fromOthersArmyes =  m_figures[firstElementIndex]->color() != m_figures[secondElementIndex]->color();

	if(fromOthersArmyes)
	{
		bool firstTurn = m_figures[firstElementIndex]->itsTurn();
		bool secondTurn = m_figures[secondElementIndex]->itsTurn();
		bool bouthAlive = m_figures[firstElementIndex]->isAlive() && m_figures[secondElementIndex]->isAlive();

		if(firstTurn){m_figures[firstElementIndex]->setTurn(false);}
		if(secondTurn){m_figures[secondElementIndex]->setTurn(false);}

		// ---avoid abiliti to play void figure

		if(firstTurn &&  bouthAlive )
		{
			kill(secondElementIndex);
		}
		else if(secondTurn && bouthAlive)
		{
			kill(firstElementIndex);
		}



		swapPositions(firstElementIndex, secondElementIndex);
		std::swap(m_figures[firstElementIndex], m_figures[secondElementIndex]);
		emit dataChanged(createIndex(0, 0), createIndex(boardSize, boardSize));
	}
}

void BoardController::changeSelected()
{
	firstItemSelected = !firstItemSelected;
}

bool BoardController::getSelected()
{
	return firstItemSelected;
}

void BoardController::showPossiblePositions()
{
	auto elementIterator = std::find_if(m_figures.begin(), m_figures.end(), [&](Figure* element){return element->hovered();});
	if(elementIterator == m_figures.end()){return;}
	int elementIndex = std::distance(m_figures.begin(), elementIterator);


	QVector<Position>  freePositions = m_figures[elementIndex]->getFreePositions();

	for(auto &i: freePositions)
	{
		int recolorIndex =(i.m_y * 8) + i.m_x;
		m_figures[recolorIndex]->setLightning(true);
	}


	for(auto &itter : freePositions)
	{
		int indexChecker =  (itter.m_y * 8) + itter.m_x;
		if(checkPositionFree(indexChecker))
		{
			itter.m_avaliable = true;
		}
	}
	//QVector<Position>  moveablePositions = m_figures[index]->getMoveablePositions(freePositions);


}

void BoardController::turnOfLightning()
{
	for(auto &i : m_figures)
	{
		i->setLightning(false);
	}
}

void BoardController::showBoardOnConsole()
{

	std::cout << std::endl << "============" << std::endl;
	for(auto i : m_figures)
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

void BoardController::kill(int index)
{
	m_figures[index]->setAlive(false);

	Figure* diedFigure = m_figures[index];
	m_diedFigures.push_back(diedFigure);
}

void BoardController::swapPositions(int firstIndex, int secondIndex)
{
	int fx = m_figures[firstIndex]->xBoard();
	int fy = m_figures[firstIndex]->yBoard();
	int sx = m_figures[secondIndex]->xBoard();
	int sy = m_figures[secondIndex]->yBoard();

	m_figures[firstIndex]->setX(sx);
	m_figures[firstIndex]->setY(sy);

	m_figures[secondIndex]->setX(fx);
	m_figures[secondIndex]->setY(fy);
}

bool BoardController::checkPositionFree(int index)
{
	return !m_figures[index]->isAlive();
}


int BoardController::rowCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent)
	return 8;
}

QVariant BoardController::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int column = index.column();

	int elIndex = (BoardSize * row ) + column ;

	switch (role)
	{
	case (Qt::UserRole + 1):
	{
		return QVariant::fromValue(static_cast<QObject *>(m_figures[elIndex]));
	}


	}
	return {};
}

QHash<int, QByteArray> BoardController::roleNames() const
{
	QHash<int, QByteArray> roles;
	roles[Qt::UserRole + 1] = "figure";
	return roles;
}

int BoardController::columnCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent)
	return 8;
}