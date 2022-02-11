#pragma once

//base unit in chess

#include <QObject>

class Figure : public QObject
{
	Q_OBJECT

	Q_PROPERTY(int  xBoard READ xBoard WRITE setX NOTIFY xChanged)
	Q_PROPERTY(int  yBoard READ yBoard WRITE setY NOTIFY yChanged)
	Q_PROPERTY(QString picture READ picture WRITE setPicture NOTIFY pictureChanged)
	Q_PROPERTY(bool alive READ isAlive WRITE setAlive NOTIFY AliveChanged)
	Q_PROPERTY(bool selected READ isSlected WRITE setSelected NOTIFY selectedChanged)
	Q_PROPERTY(Color color READ color  WRITE setColor CONSTANT)



public:
	enum Color
	{
		WHITE,
		BLACK,
		NOCOLOR
	};
	Q_ENUM(Color)

	Figure(QObject* parent = nullptr);
	virtual ~Figure(){};



	int xBoard() const;
	int yBoard() const;
	const QString& picture() const;
	bool isAlive() const;
	bool isSlected() const;
	Figure::Color color() const;

	void setX(int newX);
	void setY(int newY);
	void setAlive(bool newAlive);
	void setSelected(bool newSelected);
	void setPicture(QString picture);
	virtual void setColor(Figure::Color newColor);

	Q_INVOKABLE virtual void move();
	virtual void info();


signals:
	void xChanged();
	void yChanged();
	void AliveChanged();
	void selectedChanged();
	void pictureChanged();

private:
	int m_x;
	int m_y;
	QString m_picture;
	bool m_alive;
	bool m_selected;
	Color m_color;
};


