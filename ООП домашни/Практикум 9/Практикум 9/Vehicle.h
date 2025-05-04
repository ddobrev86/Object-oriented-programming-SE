#pragma once
#include "Registration.h"
#include <utility>

class Vehicle
{
	private:
		Registration registration;
		char* description;

		void free();
		void copyFrom(const Vehicle& other);
		void moveFrom(Vehicle&& other);

	public:
		Vehicle(const Registration& reg, const char* description);
		Vehicle(const Vehicle& other);
		Vehicle& operator=(const Vehicle& other);
		Vehicle(Vehicle&& other) noexcept;
		Vehicle& operator=(Vehicle&& other) noexcept;
		~Vehicle();

		const Registration& getRegistration() const;
};

