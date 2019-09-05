#pragma once

#include <QWidget>
#include "ui_Tool1.h"

class Tool1 : public QWidget
{
	Q_OBJECT

public:
	Tool1(QWidget *parent = Q_NULLPTR);
	~Tool1();

private:
	Ui::Tool1 ui;
};
