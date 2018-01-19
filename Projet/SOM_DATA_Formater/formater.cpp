/*#include "formater.h"

Formater::Formater(std::string fromFile, std::string toFile)
{
	printf("Formatage du fichier %s (raw) en fichier %s (en sdt)", fromFile.c_str(), toFile.c_str());

	SECURE_OPEN(m_pFile, fromFile.c_str(), "rb");
	ReadFileData();
	fclose(m_pFile);

	SECURE_OPEN(m_pFile, toFile.c_str(), "wb");
	WriteFileData();
	fclose(m_pFile);
}

Formater::~Formater()
{
	delete[] m_pData;
	delete m_pFile;
}

void Formater::ReadFileData()
{
	m_nSize = file_utile::getFileLen(m_pFile);

	m_pData = new uchar[m_nSize];

	file_utile::fileToData(m_pFile, m_pData, m_nSize);

	m_nNbPix = (ushort)(m_nSize / FILE_FORMAT_PIX_SIZE);

	if (SQUARED_FILE_DATA) m_nHeight = m_nWidth = (uchar)sqrt(m_nNbPix);
}

void Formater::WriteFileData()
{
	fwrite(&m_nIdentifier, sizeof(short), 1, m_pFile);
	fwrite(&m_nHeight, sizeof(char), 1, m_pFile);
	fwrite(&m_nWidth, sizeof(char), 1, m_pFile);
	fwrite(&m_nNbPix, sizeof(short), 1, m_pFile);
	fwrite(&m_nPixelSize, sizeof(char), 1, m_pFile);

	file_utile::dataToFile(m_pFile, m_pData, m_nSize);
}*/