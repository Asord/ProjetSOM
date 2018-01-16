#include "PTUT.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SOM::PTUT w;
	w.show();
	auto res = a.exec();
	_CrtDumpMemoryLeaks();
	return res;
}
