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
		Color m_fColor[100];

        Resources()
        {
            std::srand((uint)std::time(nullptr));
			for (int i = 0; i < 100; ++i)
			{
				m_fColor[i] = Color();
			}
        }

		/* = {
			Color(194, 144, 231), Color(117, 113, 38), Color(33, 19, 246), Color(45, 4, 86),
			Color(185, 52, 33), Color(37, 85, 232), Color(61, 42, 219), Color(180, 218, 115),
			Color(91, 123, 185), Color(7, 68, 174), Color(126, 114, 163), Color(246, 99, 88),
			Color(219, 220, 109), Color(73, 161, 6), Color(36, 26, 123), Color(1, 216, 48),
			Color(148, 202, 125), Color(85, 186, 118), Color(222, 43, 141), Color(178, 61, 191),
			Color(65, 253, 108), Color(77, 154, 241), Color(114, 94, 192), Color(104, 100, 184),
			Color(169, 199, 75), Color(252, 3, 119), Color(121, 110, 114), Color(112, 43, 169),
			Color(203, 210, 76), Color(4, 76, 208), Color(9, 32, 211), Color(236, 142, 14),
			Color(116, 95, 24), Color(72, 52, 73), Color(170, 223, 165), Color(14, 254, 103),
			Color(217, 77, 87), Color(52, 156, 78), Color(224, 112, 189), Color(38, 219, 161),
			Color(245, 120, 66), Color(245, 129, 131), Color(62, 79, 157), Color(84, 28, 180),
			Color(215, 39, 157), Color(130, 177, 131), Color(80, 63, 38), Color(205, 84, 20),
			Color(217, 209, 31), Color(39, 212, 48), Color(122, 147, 222), Color(65, 163, 24),
			Color(162, 55, 140), Color(199, 25, 95), Color(90, 56, 187), Color(150, 182, 206),
			Color(104, 150, 9), Color(162, 31, 214), Color(197, 19, 182), Color(40, 109, 23),
			Color(237, 193, 150), Color(115, 203, 134), Color(124, 92, 31), Color(244, 190, 59),
			Color(252, 245, 113), Color(25, 199, 66), Color(237, 49, 106), Color(155, 239, 112),
			Color(186, 194, 255), Color(145, 132, 78), Color(229, 17, 237), Color(235, 92, 113),
			Color(247, 18, 41), Color(180, 97, 88), Color(168, 172, 51), Color(22, 69, 239),
			Color(9, 200, 231), Color(53, 201, 138), Color(139, 133, 94), Color(86, 45, 8),
			Color(97, 140, 236), Color(142, 229, 77), Color(90, 63, 48), Color(223, 92, 174),
			Color(141, 240, 240), Color(234, 44, 20), Color(152, 150, 51), Color(161, 138, 232),
			Color(117, 91, 168), Color(36, 3, 14), Color(121, 123, 183), Color(101, 93, 31),
			Color(248, 99, 122), Color(56, 136, 223), Color(10, 233, 143), Color(205, 189, 49),
			Color(217, 43, 152), Color(213, 121, 30), Color(165, 80, 130), Color(10, 200, 10)
		};*/
	};
}