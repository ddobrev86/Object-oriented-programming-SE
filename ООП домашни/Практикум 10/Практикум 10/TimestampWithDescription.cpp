#include "TimestampWithDescription.h"
#include <cstring>
#include <stdexcept>
#pragma warning (disable:4996)

void TimestampWithDescription::free()
{
	delete[] description;
	description = nullptr;
}

void TimestampWithDescription::copyFrom(const TimestampWithDescription& other)
{
	description = new char[strlen(other.description) + 1];
	strcpy(description, other.description);
}

void TimestampWithDescription::moveFrom(TimestampWithDescription&& other)
{
	description = other.description;
	other.description = nullptr;
}

TimestampWithDescription::TimestampWithDescription() : Timestamp()
{
	description = nullptr;
}

TimestampWithDescription::TimestampWithDescription(unsigned timestamp, const char* desc) : Timestamp(timestamp)
{
	try
	{
		setDescription(desc);
	}
	catch (const std::exception& excp)
	{
		throw excp;
	}
}

TimestampWithDescription::TimestampWithDescription(const TimestampWithDescription& other)
{
	copyFrom(other);
}

TimestampWithDescription& TimestampWithDescription::operator=(const TimestampWithDescription& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

TimestampWithDescription::TimestampWithDescription(TimestampWithDescription&& other) noexcept
{
	moveFrom(std::move(other));
}

TimestampWithDescription& TimestampWithDescription::operator=(TimestampWithDescription&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

TimestampWithDescription::~TimestampWithDescription()
{
	free();
}

void TimestampWithDescription::setDescription(const char* description)
{
	if (!description)
		throw std::invalid_argument("Empty description");

	delete[] this->description;
	this->description = new char[strlen(description) + 1];
	strcpy(this->description, description);
}

const char* TimestampWithDescription::getDescription() const
{
	return description;
}

std::istream& operator>>(std::istream& is, TimestampWithDescription& timestamp)
{
	is >> timestamp.time;

	char buffer[1024];
	is >> buffer;

	delete[] timestamp.description;
	timestamp.description = new char[strlen(buffer) + 1];
	strcpy(timestamp.description, buffer);

	return is;
}

std::ostream& operator<<(std::ostream& os, const TimestampWithDescription& timestamp)
{
	Timestamp* obj = new Timestamp(timestamp);
	os << *obj << '\n' << timestamp.getDescription();

	delete obj;
	return os;
}