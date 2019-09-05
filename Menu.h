#pragma once

#include <QMenu>

class Menu : public QMenu
{
	Q_OBJECT

public:
	explicit Menu(QWidget *parent);
	explicit Menu(const QString & title);
	~Menu();
	void init();
protected:
	virtual bool event(QEvent *event);

};
