#pragma once

#include <QWidget>
#include "ui_MyDockTitleWidget.h"
#include "Menu.h"
class MyDockTitleWidget : public QWidget
{
	Q_OBJECT
		
public:
	MyDockTitleWidget(QWidget *parent = Q_NULLPTR);
	~MyDockTitleWidget();
	/*void SetIcon(QString icon);
	void SetTitle(QString title);*/
protected:
	void resizeEvent(QResizeEvent *event) override;
public slots:
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
private:
	Ui::MyDockTitleWidget ui;
	//QMenu *menu1 = NULL;
	Menu* menu1 = NULL;
};
