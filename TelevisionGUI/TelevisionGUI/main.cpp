#include "TelevisionGUI.h"
#include <vector>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TelevisionGUI w;
	
	w.show();
	return a.exec();
}
