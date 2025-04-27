#pragma once
#include "DoubleArray.h"

class SaveableDoubleArray : public DoubleArray
{
public:
	SaveableDoubleArray();
	SaveableDoubleArray(const double* numbers, const size_t size);

	void read(const char* fileName);
	void write(const char* fileName);
};

