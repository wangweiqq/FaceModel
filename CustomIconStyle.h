#pragma once

#include <QCommonStyle>
#include <QProxyStyle>
//class CustomIconStyle : public QCommonStyle
//{
//	Q_OBJECT
//
//public:
//	CustomIconStyle();
//	~CustomIconStyle();
//	void SetCustomSize(int);
//
//	//protected:
//	virtual int pixelMetric(PixelMetric metric, const QStyleOption * option, const QWidget * widget) const;
//
//private:
//	int mSize;
//};
class CustomIconStyle : public QProxyStyle
{
	Q_OBJECT

public:
	CustomIconStyle();
	~CustomIconStyle();
	void SetCustomSize(int);

	//protected:
	virtual int pixelMetric(PixelMetric metric, const QStyleOption * option, const QWidget * widget) const;

private:
	int mSize;
};