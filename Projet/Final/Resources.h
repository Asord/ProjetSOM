#pragma once
#include "..\SOM\Utility.h"

namespace SOM
{
	struct Color
	{
		char r;
		char g;
		char b;
		uint m_nColor;

		Color(char red, char gre, char blu)
		{
			r = red;
			g = gre;
			b = blu;
			m_nColor = r << 16 | g << 8 | b;
		}

		Color(uint color)
		{
			m_nColor = color;
			r = 0xFF0000 & color >> 16;
			g = 0xFF00 & color >> 8;
			b = 0xFF & color;
		}
	};

	static struct Resources 
	{
		Color m_fColor[10][4][4] =
		{
			{
				{ Color(194, 144, 231), Color(117, 113, 38), Color(33, 19, 246), Color(45, 4, 86) },
				{ Color(185, 52, 33), Color(37, 85, 232), Color(61, 42, 219), Color(180, 218, 115) },
				{ Color(91, 123, 185), Color(7, 68, 174), Color(126, 114, 163), Color(246, 99, 88) },
				{ Color(219, 220, 109), Color(73, 161, 6), Color(36, 26, 123), Color(1, 216, 48) }
			},
			{
				{ Color(148, 202, 125), Color(85, 186, 118), Color(222, 43, 141), Color(178, 61, 191) },
				{ Color(65, 253, 108), Color(77, 154, 241), Color(114, 94, 192), Color(104, 100, 184) },
				{ Color(169, 199, 75), Color(252, 3, 119), Color(121, 110, 114), Color(112, 43, 169) },
				{ Color(203, 210, 76), Color(4, 76, 208), Color(9, 32, 211), Color(236, 142, 14) }
			},
			{
				{ Color(116, 95, 24), Color(72, 52, 73), Color(170, 223, 165), Color(14, 254, 103) },
				{ Color(217, 77, 87), Color(52, 156, 78), Color(224, 112, 189), Color(38, 219, 161) },
				{ Color(245, 120, 66), Color(245, 129, 131), Color(62, 79, 157), Color(84, 28, 180) },
				{ Color(215, 39, 157), Color(130, 177, 131), Color(80, 63, 38), Color(205, 84, 20) }
			},
			{
				{ Color(217, 209, 31), Color(39, 212, 48), Color(122, 147, 222), Color(65, 163, 24) },
				{ Color(162, 55, 140), Color(199, 25, 95), Color(90, 56, 187), Color(150, 182, 206) },
				{ Color(104, 150, 9), Color(162, 31, 214), Color(197, 19, 182), Color(40, 109, 23) },
				{ Color(237, 193, 150), Color(115, 203, 134), Color(124, 92, 31), Color(244, 190, 59) }
			},
			{
				{ Color(252, 245, 113), Color(25, 199, 66), Color(237, 49, 106), Color(155, 239, 112) },
				{ Color(186, 194, 255), Color(145, 132, 78), Color(229, 17, 237), Color(235, 92, 113) },
				{ Color(247, 18, 41), Color(180, 97, 88), Color(168, 172, 51), Color(22, 69, 239) },
				{ Color(9, 200, 231), Color(53, 201, 138), Color(139, 133, 94), Color(86, 45, 8) }
			},
			{
				{ Color(97, 140, 236), Color(142, 229, 77), Color(90, 63, 48), Color(223, 92, 174) },
				{ Color(141, 240, 240), Color(234, 44, 20), Color(152, 150, 51), Color(161, 138, 232) },
				{ Color(117, 91, 168), Color(36, 3, 14), Color(121, 123, 183), Color(101, 93, 31) },
				{ Color(248, 99, 122), Color(56, 136, 223), Color(10, 233, 143), Color(205, 189, 49) }
			},
			{
				{ Color(217, 43, 152), Color(213, 121, 30), Color(165, 80, 130), Color(10, 73, 200) },
				{ Color(96, 72, 140), Color(174, 83, 121), Color(176, 186, 210), Color(73, 221, 98) },
				{ Color(237, 124, 190), Color(148, 84, 96), Color(78, 157, 106), Color(72, 210, 47) },
				{ Color(255, 106, 200), Color(169, 134, 25), Color(72, 191, 18), Color(85, 173, 157) }
			},
			{
				{ Color(25, 223, 213), Color(19, 118, 68), Color(157, 64, 127), Color(198, 138, 67) },
				{ Color(2, 164, 186), Color(171, 148, 39), Color(64, 184, 19), Color(32, 40, 216) },
				{ Color(165, 121, 125), Color(97, 255, 136), Color(26, 125, 119), Color(177, 54, 150) },
				{ Color(2, 114, 29), Color(191, 75, 144), Color(89, 129, 152), Color(47, 249, 243) }
			},
			{
				{ Color(12, 93, 251), Color(36, 165, 93), Color(192, 127, 199), Color(18, 166, 90) },
				{ Color(110, 6, 223), Color(8, 135, 50), Color(113, 178, 240), Color(46, 156, 166) },
				{ Color(236, 102, 5), Color(44, 18, 210), Color(230, 189, 79), Color(247, 75, 59) },
				{ Color(135, 53, 68), Color(27, 103, 71), Color(112, 15, 52), Color(24, 48, 233) }
			},
			{
				{ Color(216, 46, 181), Color(21, 219, 194), Color(23, 225, 4), Color(174, 247, 225) },
				{ Color(24, 128, 239), Color(207, 44, 166), Color(236, 191, 192), Color(236, 128, 197) },
				{ Color(155, 21, 150), Color(226, 127, 144), Color(37, 212, 255), Color(197, 21, 138) },
				{ Color(108, 252, 179), Color(111, 75, 214), Color(104, 197, 233), Color(128, 215, 163) }
			}
		};
	};
}