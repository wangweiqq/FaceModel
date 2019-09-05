#pragma once

#include <QDialog>
#include "ui_CustomDialog.h"

class CustomDialog : public QDialog
{
	Q_OBJECT

public:
	CustomDialog(QWidget *parent = Q_NULLPTR);
	~CustomDialog();

private:
	Ui::CustomDialog ui;
};
