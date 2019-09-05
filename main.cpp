#include "FaceModel.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FaceModel w;
	w.show();
	return a.exec();
}
