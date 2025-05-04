#include "VehicleList.h"
#include <stdexcept>

const size_t VehicleList::INITIAL_CAPACITY = 16;

void VehicleList::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete vehicles[i];
	}

	delete[] vehicles;

}

void VehicleList::copyFrom(const VehicleList& other)
{
	size = other.size;
	capacity = other.capacity;

	vehicles = new Vehicle * [capacity];
	for (size_t i = 0; i < size; i++)
		vehicles[i] = new Vehicle(*(other.vehicles[i]));
}

void VehicleList::moveFrom(VehicleList&& other)
{
	size = other.size;
	capacity = other.capacity;

	vehicles = other.vehicles;
	other.vehicles = nullptr;
}

void VehicleList::resize()
{
	capacity += VehicleList::INITIAL_CAPACITY;

	Vehicle** temp = new Vehicle * [capacity];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = new Vehicle(*(vehicles[i]));
		delete vehicles[i];
	}

	delete[] vehicles;
	vehicles = temp;
}

VehicleList::VehicleList()
{
	size = 0;
	capacity = VehicleList::INITIAL_CAPACITY;
	vehicles = new Vehicle * [capacity] {nullptr};
}

VehicleList::VehicleList(size_t capacity)
{
	size = 0;
	this->capacity = capacity;
	vehicles = new Vehicle * [capacity] {nullptr};
}

VehicleList::VehicleList(const VehicleList& other)
{
	copyFrom(other);
}

VehicleList& VehicleList::operator=(const VehicleList& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

VehicleList::VehicleList(Vehicle&& other) noexcept
{
	moveFrom(std::move(other));
}

VehicleList& VehicleList::operator=(VehicleList&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

VehicleList::~VehicleList()
{
	free();
}

void VehicleList::addVehicle(const Vehicle& obj)
{
	for (size_t i = 0; i < size; i++)
	{
		if (vehicles[i]->getRegistration() == obj.getRegistration())
			throw std::invalid_argument("There cannot be two vehicles with the same registration");
	}

	if (size >= capacity)
		resize();

	vehicles[size++] = new Vehicle(obj);
}

Vehicle& VehicleList::operator[](size_t index)
{
	if (index < 0 || index >= size)
		throw std::invalid_argument("Invalid index");

	return *(vehicles[index]);
}

const Vehicle& VehicleList::operator[](size_t index) const
{
	if (index < 0 || index >= size)
		throw std::invalid_argument("Invalid index");

	return *(vehicles[index]);
}

bool VehicleList::isEmpty() const
{
	return !vehicles || size == 0;
}

size_t VehicleList::getCapacity() const
{
	return capacity;
}

size_t VehicleList::getVeicleCount() const
{
	return size;
}

Vehicle& VehicleList::findVehicle(Registration registration)
{
	for (size_t i = 0; i < size; i++)
	{
		if (vehicles[i]->getRegistration() == registration)
			return *vehicles[i];
	}

	throw std::invalid_argument("There isn't a vehicle with this registration number");
}
