#pragma once

#include <QWidget>
#include <QSize>

#include <QDockWidget>

#include <QMouseEvent>

#include <QWidget>

#include <QPainter>

#include <QPaintEvent>

#include "qdebug.h"

#include <QStyle>
class MyDockTitleBar : public QWidget
{
	Q_OBJECT

public:
	MyDockTitleBar(QWidget *parent);
	~MyDockTitleBar();
	QSize sizeHint() const
	{
		return minimumSizeHint();
	}
	QSize minimumSizeHint() const;
	void SetIcon(QPixmap icon);
	void SetTitle(QString title);
protected:
	void paintEvent(QPaintEvent *event);

	void mousePressEvent(QMouseEvent *event);
public slots:
	void updateMask();
private:
	QPixmap minPix, closePix, floatPix,iconPix;
	QString mTitle;
};
