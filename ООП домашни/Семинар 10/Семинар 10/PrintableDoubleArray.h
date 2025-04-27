#pragma once
#include "DoubleArray.h"
#include <iostream>

class PrintableDoubleArray : public DoubleArray
{
public:
	PrintableDoubleArray();
	PrintableDoubleArray(const double* numbers, const size_t size);

	friend std::ostream& operator<<(std::ostream& os, const PrintableDoubleArray& obj);
	friend std::istream& operator>>(std::istream& is, PrintableDoubleArray& obj);
};

