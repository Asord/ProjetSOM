#include <iostream>
#include <string>

#define _CRT_SECURE_NO_WARNINGS

unsigned long getFileLen(FILE* file_ptr)
{
	unsigned long size;
	fseek(file_ptr, 0, SEEK_END);
	size = ftell(file_ptr) - 7;
	rewind(file_ptr);
	return size;
}

using namespace std;

int main(int argv, char* args[])
{
	unsigned char* fData;
	unsigned long fSize;

	FILE* pFile = fopen(args[1], "rb"); 
	if (pFile == NULL) return -1;

	fSize = getFileLen(pFile);

	fseek(pFile, 7, 0);

	fData = new unsigned char[fSize];

	unsigned char buffer;
	for (unsigned long i = 0; i < fSize; ++i)
	{
		fread(&buffer, sizeof(char), 1, pFile);
		fData[i] = buffer;
	}

	fclose(pFile);

	unsigned short identifier = 17491;
	unsigned char height  = stoi(args[3], nullptr, 10);
	unsigned char width   = stoi(args[4], nullptr, 10);
	unsigned short nbPix  = height * width;;
	unsigned char pixSize = 3;


	FILE* pOutputFile = fopen(args[2], "wb");

	fwrite(&identifier, sizeof(short), 1, pOutputFile);
	fwrite(&height, sizeof(char), 1, pOutputFile);
	fwrite(&width, sizeof(char), 1, pOutputFile);
	fwrite(&nbPix, sizeof(short), 1, pOutputFile);
	fwrite(&pixSize, sizeof(char), 1, pOutputFile);

	for (unsigned long i = 0; i < fSize; ++i)
	{
		buffer = fData[i];
		fwrite(&buffer, sizeof(char), 1, pOutputFile);
	}

	fclose(pOutputFile);

	delete[] fData;
}