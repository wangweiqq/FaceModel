#pragma once

#include <QWidget>
#include "ui_CenterWidget.h"

class CenterWidget : public QWidget
{
	Q_OBJECT

public:
	CenterWidget(QWidget *parent = Q_NULLPTR);
	~CenterWidget();

private:
	Ui::CenterWidget ui;
};
