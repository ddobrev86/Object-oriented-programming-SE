#include "Accomodation.h"
#include <cstring>
//#include <iostream>
#include <stdexcept>
#pragma warning (disable:4996)

size_t Accomodation::counter = 0;

void Accomodation::free()
{
	delete[] name;

	name = nullptr;
}

void Accomodation::copyFrom(const Accomodation& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	id = other.id;
	type = other.type;
	coordinates = other.coordinates;
	price = other.price;
	isBooked = other.isBooked;
	daysToStay = other.daysToStay;
}

void Accomodation::setId()
{
	id = Accomodation::counter;
	Accomodation::counter++;
}

Accomodation::Accomodation()
{
	id = 0;
	name = nullptr;
	type = AccType::Apartment;
	coordinates = Point(0, 0);
	price = 0;
	isBooked = false;
	daysToStay = 0;
}

Accomodation::Accomodation(const char* name, AccType type, 
	const Point& coordinates, double price)
{
	try
	{
		setId();
		setName(name);
		setAccType(type);
		setCoordinates(coordinates);
		setPrice(price);
		setDaysToStay(0);
		setIsBooked(false);
	}
	catch (const std::exception& excp)
	{
		throw excp;
	}
}

Accomodation::Accomodation(const Accomodation& other)
{
	copyFrom(other);
}

Accomodation& Accomodation::operator=(const Accomodation& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Accomodation::~Accomodation()
{
	free();
}

void Accomodation::setName(const char* name)
{
	if (!name)
	{
		throw std::invalid_argument("Invalid name");
	}

	delete[] this->name;
	this->name = new char[strlen(name) + 1];

	strcpy(this->name, name);
}

void Accomodation::setAccType(AccType type)
{
	this->type = type;
}

void Accomodation::setCoordinates(const Point& coord)
{
	this->coordinates = coord;
}

void Accomodation::setPrice(double price)
{
	this->price = price;
}

void Accomodation::setIsBooked(bool isBooked)
{
	this->isBooked = isBooked;
}

void Accomodation::setDaysToStay(unsigned daysToStay)
{
	this->daysToStay = daysToStay;
}

const size_t& Accomodation::getId() const
{
	return id;
}

const char* Accomodation::getName() const
{
	return name;
}

AccType Accomodation::getAccType() const
{
	return type;
}

const Point Accomodation::getCoordinates() const
{
	return coordinates;
}

double Accomodation::getPrice() const
{
	return price;
}

bool Accomodation::getIsBooked() const
{
	return isBooked;
}

unsigned Accomodation::getDaysToStay() const
{
	return daysToStay;
}

void Accomodation::makeReservation(unsigned daysToStay)
{
	setDaysToStay(daysToStay);
	setIsBooked(true);
}

void Accomodation::unreserve()
{
	setDaysToStay(0);
	setIsBooked(false);
}

double Accomodation::calculateTotalPrice() const
{
	if (!isBooked)
	{
		return 0;
	}

	return daysToStay * price;
}