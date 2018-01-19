#include "formater.h"

int main(uint argv, char* args[])
{
	for (uint i = 1; i < argv; ++i)
	{
		std::string fromFile = args[i];
		std::string toFile = fromFile.substr(0, fromFile.find_last_of('.')) + ".sdt";

		Formater formater(fromFile, toFile);
	}
	return 0;
}