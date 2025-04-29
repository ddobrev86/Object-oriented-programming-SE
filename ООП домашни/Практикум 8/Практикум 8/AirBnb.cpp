#include "AirBnb.h"
//#include <exception> //std::exception
#include <stdexcept>
#include <iostream>

double AirBnb::allReservationsTotal = 0;

void AirBnb::free()
{
	delete[] places;

	places = nullptr;
	size = 0;
	capacity = 0;
}

void AirBnb::copyFrom(const AirBnb& other)
{
	places = new Accomodation[other.capacity];

	size = other.size;
	capacity = other.capacity;
}

void AirBnb::resize()
{
	capacity = calculateNewCapacity();

	Accomodation* temp = new Accomodation[capacity];

	for (size_t i = 0; i < size; i++)
	{
		temp[i] = places[i];
	}

	delete[] places;
	places = temp;
}

size_t AirBnb::calculateNewCapacity()
{
	size_t result = capacity;

	size_t mask = AirBnb::INITIAL_CAPACITY;

	while (result & mask)
	{
		result ^= mask;
		mask <<= 1;
	}

	result ^= mask;

	return result;
}

AirBnb::AirBnb()
{
	capacity = AirBnb::INITIAL_CAPACITY;
	size = 0;
	places = new Accomodation[capacity];
}

AirBnb::AirBnb(const AirBnb& other)
{
	copyFrom(other);
}

AirBnb& AirBnb::operator=(const AirBnb& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

AirBnb::~AirBnb()
{
	free();
}

void AirBnb::addAccomodation(const Accomodation& obj)
{
	if (size >= capacity)
	{
		resize();
	}

	places[size++] = obj;
}

void AirBnb::makeReservation(size_t id, unsigned daysToStay)
{
	for (size_t current = 0; current < size; current++)
	{
		if (id == places[current].getId())
		{
			places[current].makeReservation(daysToStay);
			allReservationsTotal += places[current].calculateTotalPrice();

			return;
		}
	}

	throw std::invalid_argument("Accomodation doesn't exist");
}

void AirBnb::unreserve(size_t id)
{
	for (size_t current = 0; current < size; current++)
	{
		if (id == places[current].getId())
		{
			if (places[current].getIsBooked())
			{
				places[current].unreserve();
				return;
			}

			throw std::invalid_argument("There isn't a reservation for this accomodation");
		}
	}

	throw std::invalid_argument("Accomodation doesn't exist");
}

double AirBnb::calculateCurrentIncome() const
{
	double total = 0;

	for (size_t current = 0; current < size; current++)
	{
		if (places[current].getIsBooked())
		{
			total += places[current].calculateTotalPrice();
		}
	}

	return total;
}

double AirBnb::getTotalIncome() const
{
	return allReservationsTotal;
}

Accomodation& AirBnb::getClosest(const Point& other) const
{
	if (size == 0)
		throw std::logic_error("There aren't accomodations to find");

	size_t idx = 0;
	double shortestDistance = places[0].getCoordinates().calculateDistance(other);

	for (size_t current = 1; current < size; current++)
	{
		double currentDistance = places[current].getCoordinates().calculateDistance(other);

		if (currentDistance < shortestDistance)
		{
			shortestDistance = currentDistance;
			idx = current;
		}
	}

	return places[idx];
}

void AirBnb::removeAccomodation(size_t id)
{
	for (size_t current = 0; current < size; current++)
	{
		if (places[current].getId() == id)
		{
			if (places[current].getIsBooked())
			{
				throw std::invalid_argument("Accomodation is booked");
			}

			if (current < size - 1)
			{
				std::swap(places[current], places[size - 1]);
			}

			size--;
			return;
		}
	}

	throw std::invalid_argument("There isn't an accomodation with this ID");
}