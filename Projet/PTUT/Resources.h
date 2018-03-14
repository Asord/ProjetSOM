#pragma once
#include "Utility.h"
#include "bitmapHeader.h"

#include <time.h>
#include <iostream>
#include <vector>
#include <qimage.h>
#include <qdir.h>

namespace SOM
{
	class Resources
	{
	public:
		std::vector<QImage> images;
		uint byteSize;
		uint imageHeight;
		uint imageWidth;

		Resources(QDir directory);
	};
}