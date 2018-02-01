#pragma once
#include "Utility.h"
#include <cmath>
#include <time.h>
#include <iostream>
#include "bitmap.h"

#define VECTOR_DIM 3

namespace SOM
{
	/* DECAPED: DO NOT USE COLOR STRUCTURE FROM NOW */
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

	struct SOMData
	{	
		uchar* m_pData = nullptr;
		uchar  m_nWidth;
		uchar  m_nHeight;
		ushort m_nNbPix;

		SOMData()
		{
			m_pData = new uchar[100]{
				0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
				0,  0,  0, 16, 16, 16, 16, 16,  0,  0,
				0,  0,  0,  0,  0,  0,  0, 16,  0,  0,
				0,  0,  0,  0,  0,  0,  0, 16,  0,  0,
				0,  0,  0,  0,  0,  0,  0, 16,  0,  0,
				0,  0,  0, 16, 16, 16, 16, 16,  0,  0,
				0,  0,  0,  0,  0,  0,  0, 16,  0,  0,
				0,  0,  0,  0,  0,  0,  0, 16,  0,  0,
				0,  0,  0, 16, 16, 16, 16, 16,  0,  0,
				0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			};

			m_nHeight = 10;
			m_nWidth  = 10;
			m_nNbPix  = 100;
		}

		SOMData(uchar* data, uchar width, uchar height)
		{
			m_nWidth = width;
			m_nHeight = height;
			m_nNbPix = (ushort)(width * height);

			m_pData = new uchar[m_nNbPix];
			memcpy(m_pData, data, sizeof(uchar)*m_nNbPix);
		}

		~SOMData()
		{
			delete[] m_pData;
		}

		ushort operator[](uint idWeight) 
		{
			if (idWeight < m_nNbPix)
				return m_pData[idWeight];
			else
			{
				std::cout << "Poids inexistants (hors limite)";
				exit(EXIT_FAILURE);
			}
		}
	};

	const double fColorMinAct = sqrt(VECTOR_DIM * pow(2, 16 * sizeof(uchar)));

	struct Resources
	{
		SOMData* m_pData = nullptr;

		uint m_nNbImages;
		uint m_nImageSize;

		uint m_nHeight;
		uint m_nWidth;

		uchar m_cVersion;

		FILE* m_fichier;

		Resources()
		{
			m_pData = new SOMData();
		}

		Resources(std::string filePath)
		{
			//ouverture du fichier
			m_fichier = fopen(filePath.std::string::c_str(), "rb");

			if (!m_fichier)
			{
				std::cout << "Impossible d'ouvrir le fichier en lecture !";
				exit(1);
			}

			bitmap header;

			header.readBitmapHeader(m_fichier);

			m_nWidth  = header.width;
			m_nHeight = header.height;
			m_nImageSize  = header.nbPix;
			m_nNbImages = header.nbImage;
			m_cVersion = header.version;

			if (m_nImageSize > 625) // 25*25
			{
				std::cout << "Le fichier ouvert contiens au moins une image d'une dimention suppérieure à 25*25 pixels.";
				exit(2);
			}

			if (m_nNbImages > 20)
			{
				std::cout << "Le nombres d'images contenues dans le fichier est suppérieure à 20.";
				exit(4);
			}

			// 1: Random Color | 2: Random Gray | 3: Char Data
			if (m_cVersion == 3) {
				m_pData = new SOMData[m_nNbImages];

				uchar* data_buffer = new uchar[m_nImageSize];
				uchar  buffer;

				for (uint image = 0; image < m_nNbImages; ++image)
				{
					for (uint i = 0; i < m_nImageSize/2; i += 2)
					{
						fread(&buffer, sizeof(uchar), 1, m_fichier);

						uchar c0 = buffer & 0x0F;
						uchar c1 = (buffer & 0xF0) >> 4;

						data_buffer[i]     = c0;
						data_buffer[i + 1] = c1;
					}

					m_pData[image] = SOMData(data_buffer, m_nHeight, m_nWidth);
				}

				delete[] data_buffer;
			}
			else
			{
					std::cout << "Le format de fichier que vous avez séléctionné ne actuellement pas être utiliser.";
					exit(3);
			};

			fclose(m_fichier);
		}

		~Resources()
		{
			delete[] m_pData;
		}

	};

}