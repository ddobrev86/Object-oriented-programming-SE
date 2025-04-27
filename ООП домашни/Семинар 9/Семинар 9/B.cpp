#include "B.h"
#include <utility>

const size_t B::INITIAL_CAPACITY = 4;

void B::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete data[i];
	}

	delete[] data;

	data = nullptr;
	capacity = size = 0;
}

void B::copyFrom(const B& other)
{
	capacity = other.capacity;
	size = other.size;

	data = new A * [capacity] {nullptr};

	for (size_t i = 0; i < size; i++)
	{
		data[i] = new A(*other.data[i]);
	}
}

void B::moveFrom(B&& other)
{
	data = other.data;
	other.data = nullptr;

	size = other.size;
	capacity = other.capacity;

	other.size = other.capacity = 0;
}

void B::resize(size_t newCap)
{
	A** newData = new A * [newCap] {nullptr};
	for (int i = 0; i < capacity; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
	capacity = newCap;
}

B::B()
{
	capacity = B::INITIAL_CAPACITY;
	size = 0;
	data = new A * [capacity] {nullptr};

	/*
	data = nullptr;
	capacity = size = 0;
	*/
}

B::B(const B& other)
{
	copyFrom(other);
}

B& B::operator=(const B& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

B::~B()
{
	free();
}

B::B(B&& other) noexcept
{
	moveFrom(std::move(other));
}

B& B::operator=(B&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

void B::add(const A& obj)
{
	if (size == capacity)
	{
		resize(capacity * 2);
	}

	data[size++] = new A(obj);
}