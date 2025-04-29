#include "ComputerStore.h"
#include <cstring>
#include <stdexcept>
#include "ConsultantUtils.h"
#pragma warning (disable:4996)

const size_t ComputerStore::INITIAL_CAPACITY = 2;

void ComputerStore::free()
{
	delete[] name;
	delete[] computers;

	name = nullptr;
	computers = nullptr;
}

void ComputerStore::copyFrom(const ComputerStore& other)
{
	size = other.size;
	capacity = other.capacity;

	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	computers = new Computer[capacity];
	for (size_t i = 0; i < size; i++)
		computers[i] = other.computers[i];
}

void ComputerStore::resize()
{
	capacity = calculateNewCapacity();
	Computer* temp = new Computer[capacity];

	for (size_t i = 0; i < size; i++)
		temp[i] = computers[i];

	delete[] computers;
	computers = temp;
	//temp = nullptr;
}

size_t ComputerStore::calculateNewCapacity()
{
	size_t result = capacity;
	size_t mask = ComputerStore::INITIAL_CAPACITY;

	while (result & mask)
	{
		result ^= mask;
		mask <<= 1;
	}

	result ^= mask;

	return result;
}

ComputerStore::ComputerStore(const char* name)
{
	if (!name)
		throw std::invalid_argument("Empty string given");

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	capacity = ComputerStore::INITIAL_CAPACITY;
	size = 0;
	computers = new Computer[capacity];
}

ComputerStore::ComputerStore(const ComputerStore& other)
{
	copyFrom(other);
}

ComputerStore& ComputerStore::operator = (const ComputerStore & other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

ComputerStore::~ComputerStore()
{
	free();
}

void ComputerStore::addComputer(const Computer& computer)
{
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(computers[i].getBrandName(), computer.getBrandName()) == 0)
		{
			computers[i].addOne();
			return;
		}
	}
	
	if (size >= capacity)
		resize();

	computers[size++] = computer;
	computers[size - 1].addOne();
}

std::ostream& operator<<(std::ostream& os, const ComputerStore& obj)
{
	for (size_t i = 0; i < obj.size; i++)
		os << obj.computers[i] << '\n';

	return os;
}

void ComputerStore::buy(const char* brand, unsigned money)
{
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(computers[i].getBrandName(), brand) == 0)
		{
			if (computers[i].getQuantity() <= 0)
				throw std::logic_error("There aren't enough computers");

			if (computers[i].getPrice() > money)
				continue;

			computers[i].buyOne();
			return;
		}
	}

	throw std::invalid_argument("There isn't a computer from this brand");
}

void ComputerStore::printAvailable() const
{
	for (size_t i = 0; i < size; i++)
	{
		if (computers[i].getQuantity() > 0)
			std::cout << computers[i] << '\n';
	}
}

void ComputerStore::printAvailable(bool (*filter)(const Computer&)) const
{
	if (!filter)
		throw std::invalid_argument("Empty filter given");

	for (size_t i = 0; i < size; i++)
	{
		if (computers[i].getQuantity() > 0)
		{
			if(filter(computers[i]))
				std::cout << computers[i] << '\n';
		}
	}
}