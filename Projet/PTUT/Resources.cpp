#include "Resources.h"

namespace SOM
{
	Resources::Resources(QDir directory)
	{
		imageHeight = 0;
		imageWidth = 0;

		QStringList ressources_list = directory.entryList(QStringList() << "*.jpg" << "*.JPG", QDir::Files);

		foreach(QString files, ressources_list)
		{
			QString imagePath = directory.absolutePath() + "/" + files;
			QImage image = QImage(imagePath);

			QSize imageSize = image.size();

			if (imageHeight == 0 && imageWidth == 0)
			{
				imageWidth = imageSize.width();
				imageHeight = imageSize.height();

				byteSize = imageSize.height() * imageSize.width() * image.pixelFormat().bitsPerPixel();

			}

			if (imageHeight != imageSize.height() || imageWidth != imageSize.width())
			{
				// TODO: handle error
				exit(-1);
			}
			else
			{
				images.push_back(image);
			}
		}
	}
}