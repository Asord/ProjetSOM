#include "Resources.h"
#include <algorithm>

#define randRange(min, max) rand() % (max - min) + min + 1

namespace SOM // SomElement
{
	SomElement::SomElement(uint dimention)
	{
		this->dimention = dimention;
		
		for (uint i = 0; i < dimention; ++i)
			this->vector.push_back((float)rand());
	}

	SomElement::SomElement(uint dimention, int min, int max)
	{
		this->dimention = dimention;

		for (uint i = 0; i < dimention; ++i)
			this->vector.push_back((float)(randRange(min, max)));
	}

	SomElement::SomElement(std::vector<float>& data, uint dimention)
	{
		this->dimention = dimention;

		for (uint i = 0; i < dimention; ++i)
			this->vector.push_back(data[i]);
	}

	float& SomElement::operator[](uint dim)
	{
		return this->vector[dim];
	}

}

namespace SOM // Resources
{
	Resources::Resources(uint height, uint width)
	{
		this->height = height;
		this->width  = width;
		this->size   = height * width;

		srand((uint)time(NULL));

		for (uint i = 0; i < size; ++i)
			vector.push_back(SomElement(3));

	}

	Resources::Resources(uint size)
	{
		this->size = size;

		int sqrt_size = isqrt(size);
		if (sqrt_size * sqrt_size != size)
		{
			std::cerr << "La taille des ressources assignées à sa construction n'est pas un carré.";
			exit(EXIT_FAILURE);
		}

		srand((uint)time(NULL));

		for (uint i = 0; i < size; ++i)
			vector.push_back(SomElement(3));

	}

	Resources::Resources(std::string filePath)
	{
		m_fichier = fopen(filePath.std::string::c_str(), "rb");

		if (m_fichier == NULL) 
		{
			std::cerr << "Impossible d'ouvrir le fichier en lecture !";
			exit(EXIT_FAILURE);
		}

		bitmapHeader header;
		header.readBitmapHeader(m_fichier);

		this->size = header.nbPix;
		this->height = header.height;
		this->width = header.width;

		uchar byte_buffer;
		SomElement color_buffer(3);

		for (uint i = 0; i < size; ++i)
		{
			for (uint col = 0; col < 3; ++col)
			{
				fread(&byte_buffer, sizeof(uchar), 1, m_fichier);
				color_buffer[col] = byte_buffer;
			}
			vector.push_back(color_buffer);
		}

		fclose(m_fichier);
	}
}