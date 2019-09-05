#pragma execution_character_set("utf-8")
#include "FaceModel.h"
#include "CenterWidget.h"
#include <QTextEdit>
#include <QDockWidget>
#include "myDockTitleBar.h"
#include "MyDockTitleWidget.h"
FaceModel::FaceModel(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->setCentralWidget(new CenterWidget());

	setDockOptions(AnimatedDocks | AllowNestedDocks  | ForceTabbedDocks);

	setWindowTitle(tr("Dock Windows")); 
	QTextEdit*edt = new QTextEdit(tr("Main Window"), this); 
	setCentralWidget(edt);

	//this->setStyleSheet("QDockWidget > QWidget { border: 0px solid gray;}");
	this->setStyleSheet("border: 0px solid gray;");

	//Í£¿¿´°¿Ú3£º 
	QDockWidget*dockWidget6 = new QDockWidget(tr("Dock Window 6"), this);
	/*QWidget* title = dockWidget3->titleBarWidget();
	delete title;*/
	QWidget* lEmptyWidget6 = new QWidget();
	dockWidget6->setTitleBarWidget(lEmptyWidget6);
	dockWidget6->setFeatures(QDockWidget::NoDockWidgetFeatures);
	//QLabel* edt6 = new QLabel("±êÌâÐÅÏ¢");
	//edt6->setAlignment(Qt::AlignCenter);
	//edt6->setStyleSheet("background-color: rgb(33, 150, 243);color: rgb(255, 255, 255);font: 20pt \"Î¢ÈíÑÅºÚ\";padding: 0px 0px 0px 20px;");
	//dockWidget6->setWidget(edt6);
	dockWidget6->setWidget(new MyDockTitleWidget());
	dockWidget6->setFixedHeight(70);
	//dockWidget6->setStyleSheet("background-color: rgb(33, 150, 243);color: rgb(255, 255, 255);font: 20pt \"Î¢ÈíÑÅºÚ\";margin 20 0 0 0;border: 0px solid red;");
	addDockWidget(Qt::TopDockWidgetArea, dockWidget6);

	//°ÑedtÉèÖÃÎªÖÐÐÄ¿Ø¼þ //Í£¿¿´°¿Ú1£º 
	QDockWidget*dockWidget1 =new QDockWidget(tr("Dock Window 1"),this); 
	dockWidget1->setFeatures(QDockWidget::DockWidgetMovable);
	dockWidget1->setAllowedAreas(Qt::LeftDockWidgetArea); 
	dockWidget1->setTitleBarWidget(new MyDockTitleBar(nullptr));
	QTextEdit* edt1 =new QTextEdit(tr("Window 1")); 
	dockWidget1->setWidget(edt1);
	dockWidget1->setFixedWidth(150);
	addDockWidget(Qt::LeftDockWidgetArea,dockWidget1);

	//Í£¿¿´°¿Ú2£º 
	QDockWidget*dockWidget2 = new QDockWidget(tr("Dock Window 2"), this);
	//dockWidget2->setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetClosable);
	dockWidget2->setFeatures(QDockWidget::NoDockWidgetFeatures);
	/*MyDockTitleWidget *titlebar2 = new	MyDockTitleWidget();
	titlebar2->setFixedHeight(40);
	dockWidget2->setTitleBarWidget(titlebar2);*/	
	dockWidget2->setTitleBarWidget(new MyDockTitleBar(nullptr));
	QTextEdit* edt2 = new QTextEdit(tr("Window 2"));
	dockWidget2->setWidget(edt2);
	dockWidget2->setFixedWidth(250);
	addDockWidget(Qt::LeftDockWidgetArea, dockWidget2);

	

	//Í£¿¿´°¿Ú4£º 
	QDockWidget*dockWidget4 = new QDockWidget(tr("Dock Window 4"), this);
	//dockWidget4->setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetClosable);
	dockWidget4->setFeatures(QDockWidget::NoDockWidgetFeatures);
	QTextEdit* edt4 = new QTextEdit(tr("Window 4"));
	dockWidget4->setWidget(edt4);
	
	MyDockTitleBar *titlebar1 = new	MyDockTitleBar(dockWidget4);
	dockWidget4->setTitleBarWidget(titlebar1);
	//dockWidget4->setFixedWidth(190);
	addDockWidget(Qt::LeftDockWidgetArea, dockWidget4);
	

	//Í£¿¿´°¿Ú5£º 
	QDockWidget*dockWidget5 = new QDockWidget(tr("Dock Window 5"), this);
	//dockWidget5->setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetClosable);
	dockWidget5->setFeatures(QDockWidget::NoDockWidgetFeatures);
	QTextEdit* edt5 = new QTextEdit(tr("Window 5"));
	dockWidget5->setWidget(edt5);
	//dockWidget5->setStyle(new iconned_dock_style(QIcon(":/Image/company.png"), dockWidget5->style()));
	dockWidget5->setTitleBarWidget(new MyDockTitleBar(nullptr));
	//dockWidget5->setFixedWidth(190);
	addDockWidget(Qt::LeftDockWidgetArea, dockWidget5);

	splitDockWidget(dockWidget1, dockWidget2, Qt::Horizontal);
	splitDockWidget(dockWidget2, dockWidget4, Qt::Vertical);
	splitDockWidget(dockWidget4, dockWidget5, Qt::Vertical);

	//Í£¿¿´°¿Ú3£º 
	QDockWidget*dockWidget3 =new QDockWidget(tr("Dock Window 3"),this); 
	/*QWidget* title = dockWidget3->titleBarWidget();
	delete title;*/
	QWidget* lEmptyWidget = new QWidget();
	dockWidget3->setTitleBarWidget(lEmptyWidget);
	
	dockWidget3->setFeatures(QDockWidget::NoDockWidgetFeatures);
	//QTextEdit* edt3 =new QTextEdit(tr("Window 3"));
	QLabel* edt3 = new QLabel("×´Ì¬À¸ÐÅÏ¢");
	edt3->setStyleSheet("background-color: rgb(33, 150, 243);color: rgb(255, 255, 255);font: 10pt \"Î¢ÈíÑÅºÚ\";padding: 0px 0px 0px 20px;");
	dockWidget3->setWidget(edt3); 
	dockWidget3->setFixedHeight(40);
	addDockWidget(Qt::BottomDockWidgetArea,dockWidget3);

	//this->showMaximized();
	this->showFullScreen();
}
