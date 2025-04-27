#pragma once
#include "DoubleArray.h"

class ModifiableDoubleArray : public DoubleArray
{
	public:
		ModifiableDoubleArray();
		ModifiableDoubleArray(const double* numbers, const size_t size);

		void push_back(double numberToAdd);
		void pop_back();
		double& last();
};

