#include "SaveableDoubleArray.h"
#include <stdexcept>
#include <iostream>
#include <fstream>

SaveableDoubleArray::SaveableDoubleArray() : DoubleArray(){}
SaveableDoubleArray::SaveableDoubleArray(const double* numbers, const size_t size) : DoubleArray(numbers, size){}

void SaveableDoubleArray::write(const char* fileName)
{
	if (!fileName)
		throw std::invalid_argument("Invalid file name");

	std::ofstream ofs(fileName, std::ios::binary);
	if (!ofs.is_open())
		throw std::runtime_error("Could not open file");

	ofs.write((const char*)&capacity, sizeof(size_t));
	ofs.write((const char*)&size, sizeof(size_t));
	ofs.write((const char*)numbers, size * sizeof(double));

	ofs.close();
}

void SaveableDoubleArray::read(const char* fileName)
{
	if (!fileName)
		throw std::invalid_argument("Invalid file name");

	std::ifstream ifs(fileName, std::ios::binary);
	if (!ifs.is_open())
		throw std::runtime_error("Could not open file");

	ifs.read((char*)&capacity, sizeof(size_t));
	ifs.read((char*)&size, sizeof(size_t));

	delete[] numbers;
	numbers = new double[capacity];
	ifs.read((char*)numbers, size * sizeof(double));

	ifs.close();
}