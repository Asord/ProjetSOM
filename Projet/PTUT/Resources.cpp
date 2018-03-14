#include "Resources.h"
#include <algorithm>

namespace SOM // Resources
{
	//Resources::Resources(uint size)
	//{
	//	this->size = size;

	//	int sqrt_size = isqrt(size);
	//	if (sqrt_size * sqrt_size != size)
	//	{
	//		std::cerr << "La taille des ressources assignées à sa construction n'est pas un carré.";
	//		exit(EXIT_FAILURE);
	//	}

	//	srand((uint)time(NULL));

	//	for (uint i = 0; i < size; ++i)
	//		vector.push_back(SomElement(3));

	//}

	Resources::Resources(std::string filePath)
	{
		image = QImage(QString::fromStdString(filePath));
		
		// TODO: handle not found issue

		uchar* ptr = image.bits();

		QSize qsize = image.size();

		this->size = qsize.height() * qsize.width() * image.pixelFormat().bitsPerPixel();
		this->height = qsize.height();
		this->width = qsize.width();

	}
}