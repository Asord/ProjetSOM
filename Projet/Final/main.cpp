#include "Interface.h"
#include "Network.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SOM::Interface w;
	w.show();
	return a.exec();
}
