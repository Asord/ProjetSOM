#pragma once
#include "Utility.h"
#include <cmath>
#include <ctime>
#include <iostream>

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
            col[0] = (uchar)(std::rand() % 256);
            col[1] = (uchar)(std::rand() % 256);
            col[2] = (uchar)(std::rand() % 256);
		}


		uchar& operator[](uint dim)
		{
			return col[dim];
		}

	};

	static const double fColorMinAct = sqrt(VECTOR_DIM * pow(2, 16 * sizeof(uchar)));

	struct Resources
	{
		Color* m_fColor;
		uint m_nWidth = 20;
		uint m_nHeight = 20;

        Resources()
        {
            std::srand((uint)std::time(nullptr));

			m_fColor = new Color[m_nHeight * m_nWidth];

			for (int i = 0; i < m_nHeight * m_nWidth; ++i)
			{
				m_fColor[i] = Color();
			}
        }
	};
}