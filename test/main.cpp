#include "CcMainWin.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CcMainWin w;
	//w.showMaximized();
	w.showFullScreen();
	return a.exec();
}
