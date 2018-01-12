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
		int height;
		int width;
		Color histo[256];
		uchar couleur[4];

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
			//ouverture du fichier
			fopen_s(&fichier, filePath.std::string::c_str(), "rb");

			if (fichier == NULL) std::cout << "Impossible d'ouvrir le fichier en lecture !";

			for (int i = 0; i < 14; i++) // lecture BitMapFileHeader 
			{
				fread(&octLu, sizeof(uchar), 1, fichier);
			}

			for (int i = 0; i < 4; i++) // lecture BitMapInfoHeader 
			{
				fread(&octLu, sizeof(uchar), 1, fichier);
			}
			
			width = fread(&octLu, sizeof(uchar), 4, fichier);
			height = fread(&octLu, sizeof(uchar), 4, fichier);

			for (int i = 0; i < 28; i++) // lecture reste du BitMapInfoHeader 
			{
				fread(&octLu, sizeof(uchar), 1, fichier);
			}

			//definition des couleurs ndg
			for (int j = 0; j<256; j++) {

				for (int i = 0; i<4; i++) {
					fread(&octLu, sizeof(uchar), 1, fichier);
					couleur[i] = octLu;
				}
				unsigned char tempCouleur = (couleur[0] + couleur[1] + couleur[2]) / 3;
				/*rvb to ndg*/
				histo[j] = Color(tempCouleur, tempCouleur, tempCouleur);
			}

			const int size = height * width;
			m_fColor = new Color[size];

			//stoquage des couleurs
			for (int i = 0; i<nbPix; i++) 
			{
				fread(&octLu, sizeof(uchar), 1, fichier);
				m_fColor[i] = histo[octLu];
			}

			fclose(fichier);
		}

	};
}