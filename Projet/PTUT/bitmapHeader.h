#include <iostream>
#include "Utility.h"

struct bitmapHeader
{
	ushort identifier;
	uchar height;
	uchar width;
	ushort nbPix;
	uchar pixSize;

	bool is_completed = false;

	// Lecture du fichier d'entr�e et remplissage des informations de header
	void readBitmapHeader(FILE* file);
};