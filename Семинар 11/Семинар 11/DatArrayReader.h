#pragma once
#include "ArrayReader.h"

class DatArrayReader : public ArrayReader
{
public:
	DatArrayReader(const char* inputFile, const char* outputFile);

	void readFromFile() override;
	void saveToFile() const override;
};

