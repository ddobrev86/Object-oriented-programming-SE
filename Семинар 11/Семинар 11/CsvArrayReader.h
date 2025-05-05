#pragma once
#include "ArrayReader.h"
#include <fstream>

class CsvArrayReader : public ArrayReader
{
private:
	size_t getCommaCount(std::ifstream& ifs) const;

public:
	CsvArrayReader(const char* inputFile, const char* outputFile);
	
	void readFromFile() override;
	void saveToFile() const override;
};

