#include "CustomDialog.h"

CustomDialog::CustomDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(this->windowFlags() & Qt::CustomizeWindowHint ^ Qt::WindowTitleHint);
	//this->setStyleSheet("color: rgb(255, 255, 255);font: 20pt \"Î¢ÈíÑÅºÚ\";margin 20 0 0 0;border: 0px solid red;");
}

CustomDialog::~CustomDialog()
{
}
