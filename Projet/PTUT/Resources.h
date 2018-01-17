#pragma once
#include "Utility.h"
#include <cmath>
#include <time.h>
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
			col[0] = (uchar)rand() % 256;
			col[1] = (uchar)rand() % 256;
			col[2] = (uchar)rand() % 256;
		}

		uchar& operator[](uint dim)
		{ 
			return col[dim];
		}
	};

	static const double fColorMinAct= sqrt(VECTOR_DIM * pow(2, 16 * sizeof(uchar)));

	struct Resources
	{
		Color* m_fColor;
		uchar m_cOctLu;
		uint m_nNbPix;
		uint m_nHeight;
		uint m_nWidth;
		Color m_histo[256];
		uchar m_cCouleur[4];

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
			fopen_s(&m_fichier, filePath.std::string::c_str(), "rb");

			if (m_fichier == NULL) std::cout << "Impossible d'ouvrir le fichier en lecture !";

			for (int i = 0; i < 14; i++) // lecture BitMapFileHeader 
			{
				fread(&m_cOctLu, sizeof(uchar), 1, m_fichier);
			}

			for (int i = 0; i < 4; i++) // lecture BitMapInfoHeader 
			{
				fread(&m_cOctLu, sizeof(uchar), 1, m_fichier);
			}
			
			m_nWidth = fread(&m_cOctLu, sizeof(uchar), 4, m_fichier);
			m_nHeight = fread(&m_cOctLu, sizeof(uchar), 4, m_fichier);

			for (int i = 0; i < 28; i++) // lecture reste du BitMapInfoHeader 
			{
				fread(&m_cOctLu, sizeof(uchar), 1, m_fichier);
			}

			//definition des couleurs ndg
			for (int j = 0; j<256; j++) {

				for (int i = 0; i<4; i++) {
					fread(&m_cOctLu, sizeof(uchar), 1, m_fichier);
					m_cCouleur[i] = m_cOctLu;
				}
				unsigned char tempCouleur = (m_cCouleur[0] + m_cCouleur[1] + m_cCouleur[2]) / 3;
				/*rvb to ndg*/
				m_histo[j] = Color(tempCouleur, tempCouleur, tempCouleur);
			}

			const int size = m_nHeight * m_nWidth;
			m_fColor = new Color[size];

			//stoquage des couleurs
			for (int i = 0; i<m_nNbPix; i++) 
			{
				fread(&m_cOctLu, sizeof(uchar), 1, m_fichier);
				m_fColor[i] = m_histo[m_cOctLu];
			}

			fclose(m_fichier);
		}

	};
}