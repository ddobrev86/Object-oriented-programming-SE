#pragma once
#include "Vehicle.h"

class VehicleList
{
	private:
		static const size_t INITIAL_CAPACITY;

		Vehicle** vehicles;
		size_t size;
		size_t capacity;

		void free();
		void copyFrom(const VehicleList& other);
		void moveFrom(VehicleList&& other);
		void resize();
	public:
		VehicleList();
		VehicleList(size_t capacity);
		VehicleList(const VehicleList& other);
		VehicleList& operator=(const VehicleList& other);
		VehicleList(Vehicle&& other) noexcept;
		VehicleList& operator=(VehicleList&& other) noexcept;
		~VehicleList();

		void addVehicle(const Vehicle& obj);
		const Vehicle& operator[](size_t index) const;
		Vehicle& operator[](size_t index);
		bool isEmpty() const;

		size_t getCapacity() const;
		size_t getVeicleCount() const;

		Vehicle& findVehicle(Registration registration);
};

