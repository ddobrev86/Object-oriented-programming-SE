#include "MyString.h"
#include <algorithm>
#include <stdexcept>
#pragma warning (disable : 4996)

const size_t MyString::INITIAL_CAPACTIY = 16;

void MyString::free()
{
	delete[] data;
	data = nullptr;

	size = 0;
	capacity = 0;
}

void MyString::copyFrom(const MyString& other)
{
	capacity = other.capacity;
	data = new char[capacity];
	strcpy(data, other.data);
	size = other.size;
}

void MyString::moveFrom(MyString&& other)
{
	capacity = other.capacity;
	size = other.size;

	data = other.data;
	other.data = nullptr;
}

size_t MyString::calcualteNewCapacity()
{
	size_t result = capacity;
	size_t mask = MyString::INITIAL_CAPACTIY;

	while (result & mask)
	{
		result ^= mask;
		mask <<= 1;
	}

	result ^= mask;
	return result;
}

void MyString::resize()
{
	capacity = calcualteNewCapacity();

	char* newData = new char[capacity + 1];
	strcpy(newData, data);
	delete[] data;
	data = newData;
}

void MyString::resize(size_t newCapacity)
{
	capacity = newCapacity;

	char* newData = new char[capacity + 1];
	strcpy(newData, data);
	delete[] data;
	data = newData;
}

MyString::MyString() : MyString("") {}

MyString::MyString(const char* str)
{
	if (!str)
		throw std::invalid_argument("Empty string given");

	size = strlen(str);
	capacity = MyString::INITIAL_CAPACTIY;
	while (size >= capacity)
		capacity = calcualteNewCapacity();

	data = new char[capacity];
	strcpy(data, str);
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

MyString::MyString(MyString&& other) noexcept
{
	moveFrom(std::move(other));
}

MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

MyString::~MyString()
{
	free();
}

size_t MyString::getSize() const
{
	return size;
}

size_t MyString::getCapacity() const
{
	return capacity - 1;
}

const char* MyString::c_str() const
{
	return data;
}

char& MyString::operator[](unsigned index)
{
	if (index >= size)
		throw std::invalid_argument("Index exceeds string size");

	return data[index];
}

const char& MyString::operator[](unsigned index) const
{
	if (index >= size)
		throw std::invalid_argument("Index exceeds string size");

	return data[index];
}

MyString& MyString::operator+=(const MyString& other)
{
	size_t newCapacity = capacity;
	while (size + other.size + 1 > capacity)
		newCapacity = calcualteNewCapacity();

	resize(newCapacity);
	strncat(data, other.data, other.size);

	size += other.size;

	return *this;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString res(lhs);
	res += rhs;

	return res;
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	return os << str.data;
}

std::istream& operator>>(std::istream& is, MyString& str)
{
	char buff[1024];
	is >> buff;

	size_t buffStringSize = strlen(buff);
	while (buffStringSize >= str.capacity)
		str.capacity = str.calcualteNewCapacity();

	strcpy(str.data, buff);
	str.size = buffStringSize;

	return is;
}

MyString MyString::substr(unsigned begin, unsigned howMany)
{
	if (begin + howMany > size)
		return MyString("");

	MyString res;
	res.capacity = (MyString::INITIAL_CAPACTIY % howMany + 1) * MyString::INITIAL_CAPACTIY;
	res.data = new char[res.capacity];
	strncat(res.data, data + begin, howMany);
	res.size = howMany;

	return res;
}


bool operator==(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return !(lhs == rhs);
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}