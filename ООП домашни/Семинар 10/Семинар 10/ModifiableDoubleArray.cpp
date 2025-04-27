#include "ModifiableDoubleArray.h"
#include <stdexcept>

ModifiableDoubleArray::ModifiableDoubleArray() : DoubleArray(){}
ModifiableDoubleArray::ModifiableDoubleArray(const double* numbers, const size_t size) : DoubleArray(numbers, size){}

void ModifiableDoubleArray::push_back(double numberToAdd)
{
	if (size >= capacity)
		resize();

	numbers[size++] = numberToAdd;
}

void ModifiableDoubleArray::pop_back()
{
	if (size == 0)
		throw std::logic_error("Array is empty");

	size--;
}

double& ModifiableDoubleArray::last()
{
	return numbers[size - 1];
}