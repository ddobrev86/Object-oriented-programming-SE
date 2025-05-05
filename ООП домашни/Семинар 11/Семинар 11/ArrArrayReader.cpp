#include "ArrArrayReader.h"

ArrArrayReader::ArrArrayReader(const char* inputFile, const char* outputFile) : ArrayReader(inputFile, outputFile)
{
}

size_t ArrArrayReader::getSize(std::ifstream& ifs) const
{
	if (!ifs.is_open())
		return 0;

	size_t currPos = ifs.tellg();
	ifs.seekg(0, std::ios::beg);

	size_t count = 0;
	while (true)
	{
		if (ifs.eof())
			break;

		if (ifs.get() == ' ' && ifs.peek() != ' ')
			count++;
	}

	ifs.clear();
	ifs.seekg(currPos);

	return count;
}

void ArrArrayReader::readFromFile()
{
	std::ifstream ifs(inputFile);
	if (!ifs.is_open())
		throw std::runtime_error("Error when opening file");

	size = getSize(ifs) + 1;
	delete[] arr;
	arr = new int[size];

	char current = ifs.peek();

	ifs.ignore();
	
	for (size_t i = 0; i < size; i++)
	{
		char current = ifs.peek();
		ifs >> arr[i];
	}

	ifs.close();
}

void ArrArrayReader::saveToFile() const
{
	std::ofstream ofs(outputFile);
	if (!ofs.is_open())
		throw std::runtime_error("Error when opening file");

	ofs << '[';

	for (size_t i = 0; i < size; i++)
	{
		ofs << arr[i];
		if (i != size - 1)
			ofs << ' ';
	}

	ofs << ']';


	ofs.close();
}
