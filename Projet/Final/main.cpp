#include "Interface.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SOM::Interface w;
	w.show();
	return a.exec();
}
