#include "bitmap.h"

// d�finition de la fonction de lecture et remplissage des informations du header
void bitmap::readBitmapHeader(FILE* file)
{
	fread(&identifier, sizeof(ushort), 1, file);
	fread(&height, sizeof(uchar), 1, file);
	fread(&width, sizeof(uchar), 1, file);
	fread(&nbPix, sizeof(ushort), 1, file);
	fread(&pixSize, sizeof(uchar), 1, file);

	is_completed = true;
	is_valid = (identifier == 17491);

	/* Nb: futur -> ajouter un identifier pour d�terminer la version 2 du fichier
	Version 2 contient un header suppl�mentaire (ou concat ?) d�terminant le nb de sous images dans l'image 
	Ex: [ident] [height] [width] [size] [pixSize] [nbImage] | [pixSize + nbImage] {nbImage = number + 128} */
}