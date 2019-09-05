#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FaceModel.h"
#include <QProxyStyle>
#include <QPainter>
class iconned_dock_style : public QProxyStyle {
	Q_OBJECT
		QIcon icon_;
public:
	iconned_dock_style(const QIcon& icon, QStyle* style = 0)
		: QProxyStyle(style)
		, icon_(icon)
	{}

	virtual ~iconned_dock_style()
	{}

	virtual void drawControl(ControlElement element, const QStyleOption* option,
		QPainter* painter, const QWidget* widget = 0) const
	{
		if (element == QStyle::CE_DockWidgetTitle)
		{
			//width of the icon
			int width = pixelMetric(QStyle::PM_ToolBarIconSize);
			//margin of title from frame
			int margin = baseStyle()->pixelMetric(QStyle::PM_DockWidgetTitleMargin);

			QPoint icon_point(margin + option->rect.left(), margin + option->rect.center().y() - width / 2);

			painter->drawPixmap(icon_point, icon_.pixmap(width, width));

			const_cast<QStyleOption*>(option)->rect = option->rect.adjusted(width, 0, 0, 0);
		}
		baseStyle()->drawControl(element, option, painter, widget);
	}
};
class FaceModel : public QMainWindow
{
	Q_OBJECT

public:
	FaceModel(QWidget *parent = Q_NULLPTR);

private:
	Ui::FaceModelClass ui;
};
