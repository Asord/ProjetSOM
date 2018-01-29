#include <iostream>
#include "Utility.h"

struct bitmap
{
	ushort identifier;
	uchar version;
	uchar height;
	uchar width;
	uchar nbImage;

	ushort nbPix;

	bool is_completed;
	bool is_valid;

	// Lecture du fichier d'entrée et remplissage des informations de header
	void readBitmapHeader(FILE* file);
};