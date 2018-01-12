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
		unsigned char octLu;
		int nbPix;
		unsigned char couleur[4];

		FILE* fichier;


		Resources()
		{
			m_fColor = new Color[100];

			srand((uint)time(NULL));


			for (int i = 0; i < 100; ++i)
			{
				m_fColor[i] = Color();
			}
		}

		Resources(std::string filePath)
		{
			fopen_s(&fichier, filePath.std::string::c_str(), "rb");

			//TODO: recupéré le nombre de pixel
			//nbPix = ?????
			
			const int size = nbPix;
			m_fColor = new Color[size];

			if (fichier == NULL) std::cout << "Impossible d'ouvrir le fichier en lecture !";

			for (int i = 0; i < 14; i++) // lecture BitMapFileHeader 
			{
				fread(&octLu, sizeof(unsigned char), 1, fichier);
			}

			for (int i = 0; i < 40; i++) // lecture BitMapInfoHeader 
			{
				fread(&octLu, sizeof(unsigned char), 1, fichier);
			}

			for (int j = 0; j<256; j++) {

				for (int i = 0; i<4; i++) {
					fread(&octLu, sizeof(unsigned char), 1, fichier);
					couleur[i] = octLu;
				}
				unsigned char tempCouleur = (couleur[0] + couleur[1] + couleur[2]) / 3;
				/*rvb to ndg*/
				couleur[0] = tempCouleur;
				couleur[1] = tempCouleur;
				couleur[2] = tempCouleur;
			}

			//TODO: stoquer la couleur dans m_fColor
			for (int i = 0; i<nbPix; i++) // lecture Ndg 
			{
				fread(&octLu, sizeof(unsigned char), 1, fichier);
				histo[octLu] = histo[octLu] + 1;
				m_fColor[i] = octLu;
			}
			fclose(fichier);
		}

	};
}