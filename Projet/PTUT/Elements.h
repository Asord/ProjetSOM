#pragma once
#include "Utility.h"

#include <time.h>
#include <iostream>
#include <vector>
#include <qimage.h>
#include <qdir.h>
#include <qdebug.h>

namespace SOM
{
	const unsigned long fColorMinAct = 0xffffffff;

	struct Elements
	{
		std::vector<QImage> images;
		uint byteSize;
		uint imageHeight;
		uint imageWidth;

		Elements(QDir directory);
	};
}
