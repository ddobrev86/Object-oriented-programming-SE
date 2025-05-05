#include "DatArrayReader.h"
#include <fstream>

DatArrayReader::DatArrayReader(const char* inputFile, const char* outputFile) : ArrayReader(inputFile, outputFile)
{
}

void DatArrayReader::readFromFile()
{
	std::ifstream ifs(inputFile, std::ios::binary);
	if (!ifs.is_open())
		throw std::runtime_error("Error when opening file");

	ifs.read((char*)&size, sizeof(size_t));
	delete[] arr;
	arr = new int[size];

	ifs.read((char*)arr, size * sizeof(int));

	ifs.close();
}

void DatArrayReader::saveToFile() const
{
	std::ofstream ofs(outputFile, std::ios::binary);
	if (!ofs.is_open())
		throw std::runtime_error("Error when opening file");

	ofs.write((const char*)&size, sizeof(size_t));
	ofs.write((const char*)arr, this->size * sizeof(int));

	ofs.close();
}
