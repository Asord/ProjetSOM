#include "bitmapHeader.h"

// définition de la fonction de lecture et remplissage des informations du header
void bitmapHeader::readBitmapHeader(FILE* file)
{
	fread(&identifier, sizeof(ushort), 1, file);
	fread(&height, sizeof(uchar), 1, file);
	fread(&width, sizeof(uchar), 1, file);
	fread(&nbPix, sizeof(ushort), 1, file);
	fread(&pixSize, sizeof(uchar), 1, file);

	is_completed = true;
}