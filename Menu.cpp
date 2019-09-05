#include "Menu.h"
#include <QEvent>
#include <Windows.h>
Menu::Menu(QWidget *parent)
	: QMenu(parent)
{
	init();
}
Menu::Menu(const QString & title) : QMenu(title)
{
	init();
}

Menu::~Menu()
{
}
void Menu::init()
{
	//Qss::setMenu(this, QColor("#46e6b7"));

	// 必须设置popup, 因为QMenuPrivate::activateAction中使用QApplication::activePopupWidget()函数
	this->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);
	// 以objectname 区分Qt内置菜单和CCustomMenu
	this->setObjectName("CustomMenu");
}

bool Menu::event(QEvent *event)
{
	static bool class_amended = false;
	if (event->type() == QEvent::WinIdChange)
	{
		HWND hwnd = reinterpret_cast<HWND>(winId());
		if (class_amended == false)
		{
			class_amended = true;
			DWORD class_style = ::GetClassLong(hwnd, GCL_STYLE);
			class_style &= ~CS_DROPSHADOW;
			::SetClassLong(hwnd, GCL_STYLE, class_style);
		}

	}
	return QWidget::event(event);
}