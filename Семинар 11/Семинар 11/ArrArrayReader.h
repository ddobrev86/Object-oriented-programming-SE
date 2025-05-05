#pragma once
#include "ArrayReader.h"
#include <fstream>

class ArrArrayReader : public ArrayReader
{
private:
	size_t getSize(std::ifstream& ifs) const;
public:
	ArrArrayReader(const char* inputFile, const char* outputFile);

	void readFromFile() override;
	void saveToFile() const override;
};

