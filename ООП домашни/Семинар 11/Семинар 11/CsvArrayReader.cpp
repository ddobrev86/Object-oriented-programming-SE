#include "CsvArrayReader.h"

CsvArrayReader::CsvArrayReader(const char* inputFile, const char* outputFile) : ArrayReader(inputFile, outputFile)
{
}

size_t CsvArrayReader::getCommaCount(std::ifstream& ifs) const
{
	if (!ifs.is_open())
		return 0;

	size_t currentPos = ifs.tellg();
	ifs.seekg(0, std::ios::beg);

	size_t count = 0;
	while (true)
	{
		if (ifs.eof())
			break;

		if (ifs.get() == ',')
			count++;
	}

	ifs.clear();
	ifs.seekg(currentPos);

	return count;
}

void CsvArrayReader::readFromFile()
{
	std::ifstream ifs(inputFile);
	if (!ifs.is_open())
		throw std::runtime_error("Error when opening file");

	size = getCommaCount(ifs) + 1;
	delete[] arr;
	arr = new int[size];

	size_t current = 0;

	while (current < size)
	{
		if (ifs.peek() == ',')
			ifs.ignore();

		ifs >> arr[current++];

		if (ifs.eof())
			break;
	}

	ifs.close();
}

void CsvArrayReader::saveToFile() const
{
	std::ofstream ofs(outputFile);
	if (!ofs.is_open())
		throw std::runtime_error("Error when opening file");

	for (size_t i = 0; i < size; i++)
	{
		ofs << arr[i];
		if (i != size - 1)
			ofs << ',';
	}

	ofs.close();
}
