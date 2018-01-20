#pragma once
#include <iostream>

#define SECURE_OPEN(file_ptr, file, method) \
file_ptr = fopen(file, method); \
if (file_ptr == NULL) return;

#define FILE_FORMAT_ID 17491 // SD
#define FILE_FORMAT_PIX_SIZE 3 // RGB
#define SQUARED_FILE_DATA true // Square image

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

namespace file_utile
{
	uint getFileLen(FILE* file_ptr)
	{
		uint size;
		fseek(file_ptr, 0, SEEK_END);
		size = ftell(file_ptr);
		rewind(file_ptr);
		return size;
	}

	uint getNbPix(FILE* file_ptr)
	{
		uint size = getFileLen(file_ptr);
		return (unsigned int)(size / 3);
	}

	uint squareDim(FILE* file_ptr)
	{
		uint size = getNbPix(file_ptr);
		return (unsigned int)sqrt(size);
	}


	void fileToData(FILE* file_ptr, uchar* data_ptr, uint size)
	{
		uchar buffer;
		for (uint i = 0; i < size; ++i)
		{
			fread(&buffer, sizeof(char), 1, file_ptr);
			data_ptr[i] = buffer;
		}
	}

	void dataToFile(FILE* file_ptr, uchar* data_ptr, uint size)
	{
		uchar buffer;
		for (uint i = 0; i < size; ++i)
		{
			buffer = data_ptr[i];
			fwrite(&buffer, sizeof(char), 1, file_ptr);
		}
	}

	void rngCompress(uchar* data_ptr, uchar* compressData_ptr, uint size)
	{
		if (size % 2 != 0)
			return;

		uchar buffer_1;
		uchar buffer_2;
		for (uint i = 0; i < size; i += 2)
		{
			buffer_1 = (data_ptr[i] / 16);
			buffer_2 = (data_ptr[i + 1] / 16) << 4;
			compressData_ptr[i / 2] = buffer_1 + buffer_2;
		}
	}
}