#pragma once
#include "Utility.h"
#include <cmath>
#include <time.h>
#include <iostream>
#include "bitmapHeader.h"

#include <vector>

namespace SOM
{
	static const double fColorMinAct = sqrt(3 * pow(2, 16 * sizeof(uchar)));

	struct Color
	{
		uchar dim = 3;
		std::vector<uchar> vector;

		Color();
		Color(uchar red, uchar gre, uchar blu);

		uchar& operator[](uint dim);
	};


	template<typename T>
	struct Resources
	{
		std::vector<T> vector;

		uint m_nNbPix;

		uint m_nHeight;
		uint m_nWidth;

		FILE* m_fichier;

		Resources();
		Resources(uint width, uint height);
		Resources(std::string filePath);

	};

	template<typename T>
	Resources<T>::Resources()
	{
		Resources(10, 10);
	}

	template<typename T>
	Resources<T>::Resources(uint width, uint height)
	{
		m_nWidth = width;
		m_nHeight = height;

		m_nNbPix = m_nHeight * m_nWidth;

		srand((uint)time(NULL));

		for (uint i = 0; i < m_nNbPix; ++i)
			vector.push_back(Color());

	}

	template<typename T>
	Resources(std::string filePath)
	{
		//ouverture du fichier
		m_fichier = fopen(filePath.std::string::c_str(), "rb");

		if (m_fichier == NULL) // TODO: handle file reading error
		{
			std::cout << "Impossible d'ouvrir le fichier en lecture !";
			return;
		}

		bitmapHeader header;
		header.readBitmapHeader(m_fichier);

		m_nNbPix = header.nbPix;
		m_nWidth = header.width;
		m_nHeight = header.height;

		uchar byte;

		Color color;

		for (uint i = 0; i < m_nNbPix; ++i)
		{
			for (uint col = 0; col < 3; ++col)
			{
				fread(&byte, sizeof(uchar), 1, m_fichier);
				color[col] = byte;
			}
			vector.push_back(Color(color[0], color[1], color[2]));
		}

		fclose(m_fichier);
	}
}