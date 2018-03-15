#include "PTUT.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SOM::PTUT w(&a);
	w.show();
	return a.exec();
}
