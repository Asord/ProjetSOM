#include "bitmap.h"

// définition de la fonction de lecture et remplissage des informations du header
void bitmap::readBitmapHeader(FILE* file)
{
	fread(&identifier, sizeof(ushort), 1, file);
	fread(&height, sizeof(uchar), 1, file);
	fread(&width, sizeof(uchar), 1, file);
	fread(&nbPix, sizeof(ushort), 1, file);
	fread(&pixSize, sizeof(uchar), 1, file);

	is_completed = true;
	is_valid = (identifier == 17491);

	/* Nb: futur -> ajouter un identifier pour déterminer la version 2 du fichier
	Version 2 contient un header supplémentaire (ou concat ?) déterminant le nb de sous images dans l'image 
	Ex: [ident] [height] [width] [size] [pixSize] [nbImage] | [pixSize + nbImage] {nbImage = number + 128} */
}