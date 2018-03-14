#pragma once
#include "Utility.h"
#include "bitmapHeader.h"

#include <time.h>
#include <iostream>
#include <vector>
#include <qimage.h>

namespace SOM
{
	class Resources
	{
	public:
		//std::vector<QImage> vector;
		uint size;
		uint height;
		uint width;
		QImage image;

		Resources(uint size);
		Resources(uint height, uint width);
		Resources(std::string filePath);

	};
}