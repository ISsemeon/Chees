#pragma once

#include <QObject>
#include <include/Board.h>

class Game: public QObject
{
	Q_OBJECT
public:
	Q_PROPERTY(Board* model READ model CONSTANT FINAL )
	explicit Game(QObject *parent = nullptr);
	 Q_DISABLE_COPY(Game)

	const Board& model() const;
	void setModel(const Board& newModel);
	Board* model();

private:
	void registrateObjects();
	Board* m_model;
};

