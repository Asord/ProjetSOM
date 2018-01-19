#include <iostream>
#include "Utility.h"

struct bitmapHeader
{
	ushort identifier;
	uchar height;
	uchar width;
	ushort nbPix;
	uchar pixSize;

	bool is_completed;
	bool is_valid;

	// Lecture du fichier d'entrée et remplissage des informations de header
	void readBitmapHeader(FILE* file);
};