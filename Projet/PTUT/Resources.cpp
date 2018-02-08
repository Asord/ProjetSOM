#include "Resources.h"



namespace SOM
{
	Color::Color(uchar red, uchar gre, uchar blu)
	{
		vector.push_back(red);
		vector.push_back(gre);
		vector.push_back(blu);
	}

	Color::Color()
	{
		vector.push_back((uchar)rand() % 256);
		vector.push_back((uchar)rand() % 256);
		vector.push_back((uchar)rand() % 256);
	}

	uchar& Color::operator[](uint dim)
	{
		return vector[dim];
	}

}