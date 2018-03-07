#pragma once
#include "Utility.h"
#include "bitmapHeader.h"

#include <time.h>
#include <iostream>
#include <vector>

namespace SOM
{
	static const double fColorMinAct = sqrt(3 * pow(2, 16 * sizeof(uchar)));

	class SomElement
	{
	protected:
		uchar dimension;
		std::vector<float> vector;

	public:
		SomElement(uint dimension);
		SomElement(uint dimension, int min, int max);
		SomElement(std::vector<float>& data, uint dimension);

		float& operator[](uint dim);
	};

	class Resources
	{
	private:

		FILE* m_fichier;


	public:
		std::vector<SomElement> vector;
		uint size;
		uint height;
		uint width;

		Resources(uint size);
		Resources(uint height, uint width);
		Resources(std::string filePath);

	};
}