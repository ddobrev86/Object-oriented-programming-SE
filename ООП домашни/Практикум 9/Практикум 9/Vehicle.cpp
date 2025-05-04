#include "Vehicle.h"
#include <cstring>
#include <stdexcept>
#pragma warning(disable:4996)

void Vehicle::free()
{
	delete[] description;

	description = nullptr;
}

void Vehicle::copyFrom(const Vehicle& other)
{
	description = new char[strlen(other.description) + 1];
	strcpy(description, other.description);
}

void Vehicle::moveFrom(Vehicle&& other)
{
	description = other.description;

	other.description = nullptr;
}

Vehicle::Vehicle(const Registration& reg, const char* description) : registration(reg)
{
	if (!description)
		throw std::invalid_argument("Empty input");

	this->description = new char[strlen(description) + 1];

	strcpy(this->description, description);
}

Vehicle::Vehicle(const Vehicle& other) : registration(other.registration)
{
	copyFrom(other);
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Vehicle::Vehicle(Vehicle&& other) noexcept : registration(other.registration)
{
	moveFrom(std::move(other));
}

Vehicle& Vehicle::operator=(Vehicle&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Vehicle::~Vehicle()
{
	free();
}

const Registration& Vehicle::getRegistration() const
{
	return registration;
}