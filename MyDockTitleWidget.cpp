#pragma execution_character_set("utf-8")
#include "MyDockTitleWidget.h"
#include <QResizeEvent>
#include <QMenu>
#include <QDebug>
#include "CustomIconStyle.h"
#define STRCONTENT(x) #x
#define STRQUIT "¹Ø±Õ"
#define STRSETTING "ÉèÖÃ"
MyDockTitleWidget::MyDockTitleWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//this->setStyleSheet("background-color: rgb(33, 150, 243);color: rgb(255, 255, 255);font: 20pt \"Î¢ÈíÑÅºÚ\";margin 0px;padding:0px;border: 0px solid red;");
	this->setStyleSheet("background-color: rgb(33, 150, 243);color: rgb(255, 255, 255);font: 20pt \"Î¢ÈíÑÅºÚ\";");

	menu1 = new Menu("hello");
	QAction* actSetting = menu1->addAction(QIcon(":/Image/shezhi.png"), STRSETTING);
	menu1->addSeparator();
	QAction* actClose = menu1->addAction(QIcon(":/Image/close.png"), STRQUIT);
	menu1->setStyle(new CustomIconStyle);
	menu1->setStyleSheet(STRCONTENT(
		QMenu{
			background: white;
			padding:5px;
			border:1px solid gray;
			border-radius:6px;
		}
		QMenu::item{
			padding:15px 50px 15px 60px;
			margin:15px 15px;
			height:35px;
			font: 15pt "Î¢ÈíÑÅºÚ";
		}
		QMenu::item:selected:enabled{
				background:lightgray;
				color:white;
		}
		QMenu::item : selected : !enabled{
				background:transparent;
		}
		QMenu::separator{
				height:1px;
				background:lightgray;
				margin:5px 0px 5px 0px;
		}
	));
	menu1->show();
	menu1->hide();
}

MyDockTitleWidget::~MyDockTitleWidget()
{
}
void MyDockTitleWidget::resizeEvent(QResizeEvent *event)
{
	QWidget::resizeEvent(event);
	ui.Title->setGeometry(this->geometry());
	ui.pushButton->setFixedHeight(this->height()-1);
	ui.pushButton_2->setFixedHeight(this->height()-1);
	ui.pushButton->move(20, 0);
	ui.pushButton_2->move(this->width() - ui.pushButton_2->width() - 20, 0);
	/*int height = ui.Icon->height();
	ui.Icon->setFixedWidth(height);*/
}
//void MyDockTitleWidget::SetIcon(QString icon) {
//	/*ui.Icon->setScaledContents(true);
//	ui.Icon->setPixmap(QPixmap(icon));*/
//}
//void MyDockTitleWidget::SetTitle(QString title) {
//
//}
void MyDockTitleWidget::on_pushButton_clicked() {

}
void MyDockTitleWidget::on_pushButton_2_clicked() {
	if (QAction *act = menu1->exec(QPoint(QCursor::pos().x() - menu1->width(),QCursor::pos().y())))
	{
		QString str = act->text();
		qDebug() << str << "triggered";
		if (str == STRSETTING) {
		
		}
		else if (str == STRQUIT) {
			qApp->quit();
		}
	}
	else {
		qDebug() << "Î´Ñ¡Ôñ²Ëµ¥ triggered";
	}
}