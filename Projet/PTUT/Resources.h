#pragma once
#include "Utility.h"
#include <cmath>
#include <time.h>
#include <iostream>
#include "bitmapHeader.h"

#define VECTOR_DIM 3

namespace SOM
{
	struct Color
	{
		uchar* col;

		Color(uchar red, uchar gre, uchar blu)
		{
			col = new uchar[VECTOR_DIM];
			col[0] = red;
			col[1] = gre;
			col[2] = blu;
		}

		Color()
		{
			col = new uchar[VECTOR_DIM];
			col[0] = (uchar)rand() % 256;
			col[1] = (uchar)rand() % 256;
			col[2] = (uchar)rand() % 256;
		}

		uchar& operator[](uint dim)
		{ 
			return col[dim];
		}
	};

	static const double fColorMinAct = sqrt(VECTOR_DIM * pow(2, 16 * sizeof(uchar)));

	struct Resources
	{
		Color* m_fColor = nullptr;

		uint m_nNbPix;

		uint m_nHeight;
		uint m_nWidth;

		FILE* m_fichier;

		Resources()
		{
			Resources(10, 10);
		}

		Resources(uint width, uint height)
		{
			m_nWidth = width;
			m_nHeight = height;

			m_nNbPix = m_nHeight * m_nWidth;

			m_fColor = new Color[m_nNbPix];

			srand((uint)time(NULL));


			for (uint i = 0; i < m_nNbPix; ++i)
			{
				m_fColor[i] = Color();
			}

		}

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

			m_nNbPix  = header.nbPix;
			m_nWidth  = header.width;
			m_nHeight = header.height;

			m_fColor  = new Color[m_nNbPix];

			uchar byte;
			uchar* color = new uchar[3];

			for (uint i = 0; i < m_nNbPix; ++i)
			{
				for (uint col = 0; col < 3; ++col)
				{
					fread(&byte, sizeof(uchar), 1, m_fichier);
					color[col] = byte;
				}
				m_fColor[i] = Color(color[0], color[1], color[2]);
			}

			delete[] color;

			fclose(m_fichier);
		}

		~Resources()
		{
			delete[] m_fColor;
		}

	};
}