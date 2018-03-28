#include "Elements.h"

namespace SOM
{
	Elements::Elements(QDir directory)
	{
		imageHeight = 0;
		imageWidth = 0;

		QStringList ressources_list = directory.entryList(QStringList() << "*.jpg" << "*.JPG", QDir::Files);

		if (ressources_list.length() == 0)
			printf("Le dossier sp�cifier ne contiens pas d'images utilisables...");

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
				printf("Une image du dossier n'est pas de m�me dimention que les autres ! Arr�t");
				exit(-1);
			}
			else
			{
				images.push_back(image);
			}
		}
	}
}