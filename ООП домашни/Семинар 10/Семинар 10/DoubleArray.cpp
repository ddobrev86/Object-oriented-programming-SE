#include "DoubleArray.h"
#include <iostream>

const size_t DoubleArray::INITIAL_CAPACITY = 16;

void DoubleArray::free()
{
	delete[] numbers;
	numbers = nullptr;

	size = 0;
	capacity = 0;
}

void DoubleArray::copyFrom(const DoubleArray& other)
{
	capacity = other.capacity;
	size = other.size;

	numbers = new double[other.capacity];
	for (size_t i = 0; i < size; i++)
		numbers[i] = other.numbers[i];
}

void DoubleArray::moveFrom(DoubleArray&& other)
{
	capacity = other.capacity;
	size = other.size;

	numbers = other.numbers;
	other.numbers = nullptr;
}

size_t DoubleArray::calculateNewCapacity()
{
	size_t result = capacity;
	size_t mask = DoubleArray::INITIAL_CAPACITY;

	while (result & mask)
	{
		result ^= mask;
		mask <<= 1;
	}

	result ^= mask;
	return result;
}

void DoubleArray::resize()
{
	capacity = calculateNewCapacity();

	double* temp = new double[capacity];

	for (size_t i = 0; i < size; i++)
		temp[i] = numbers[i];

	delete[] numbers;
	numbers = temp;
	temp = nullptr;
}

DoubleArray::DoubleArray()
{
	size = 0;
	capacity = DoubleArray::INITIAL_CAPACITY;
	numbers = new double[capacity];
}

DoubleArray::DoubleArray(const double* numbers, const size_t size)
{
	capacity = DoubleArray::INITIAL_CAPACITY;
	this->size = size;

	while (this->size >= capacity)
		capacity = calculateNewCapacity();

	this->numbers = new double[capacity];
	for (size_t i = 0; i < size; i++)
		this->numbers[i] = numbers[i];
}

DoubleArray::DoubleArray(const DoubleArray& other)
{
	copyFrom(other);
}

DoubleArray& DoubleArray::operator=(const DoubleArray& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

DoubleArray::DoubleArray(DoubleArray&& other) noexcept
{
	moveFrom(std::move(other));
}

DoubleArray& DoubleArray::operator = (DoubleArray&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

DoubleArray::~DoubleArray()
{
	free();
}

bool operator==(const DoubleArray& lhs, const DoubleArray& rhs)
{
	if (lhs.size != rhs.size)
		return false;

	for (size_t i = 0; i < lhs.size; i++)
	{
		if (lhs.numbers[i] != rhs.numbers[i])
			return false;
	}

	return true;
}

bool operator!=(const DoubleArray& lhs, const DoubleArray& rhs)
{
	return !(lhs == rhs);
}

bool DoubleArray::isEmpty()
{
	return numbers == nullptr;
}