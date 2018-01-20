#pragma once
#include "Utility.h"
#include <cmath>
#include <time.h>
#include <iostream>
#include "bitmap.h"

#define VECTOR_DIM 3

namespace SOM
{
	struct Color
	{
		uchar col[3];

		Color(uchar ndg)
		{
			//col = new uchar[VECTOR_DIM];
			col[0] = col[1] = col[2] = ndg * 16;
		}

		Color(uchar red, uchar gre, uchar blu)
		{
			//col = new uchar[VECTOR_DIM];
			col[0] = red / 16;
			col[1] = gre / 16;
			col[2] = blu / 16;

			col[0] *= 16;
			col[1] *= 16;
			col[2] *= 16;

		}

		Color()
		{
			//col = new uchar[VECTOR_DIM];
			uchar r0 = rand() % 16;
			uchar r1 = rand() % 16;
			uchar r2 = rand() % 16;

			col[0] = r0 * 16;
			col[1] = r1 * 16;
			col[2] = r2 * 16;
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
				m_fColor[i] = Color(i % 256);
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

			bitmap header;

			header.readBitmapHeader(m_fichier);

			m_nWidth  = header.width;
			m_nHeight = header.height;
			m_nNbPix = m_nHeight * m_nWidth;

			m_fColor  = new Color[m_nNbPix];

			uchar byte;

			for (uint i = 0; i < m_nNbPix; i += 2)
			{
				fread(&byte, sizeof(uchar), 1, m_fichier);

				uchar c0 = byte & 0x0F;
				uchar c1 = (byte & 0xF0) >> 4;

				m_fColor[i]     = Color(c0);
				m_fColor[i + 1] = Color(c1);
			}

			fclose(m_fichier);
		}

		~Resources()
		{
			delete[] m_fColor;
		}

	};
}