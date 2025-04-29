#pragma once
#include "Accomodation.h"

class AirBnb
{
	private:
		static constexpr size_t INITIAL_CAPACITY = 2;

		Accomodation* places = nullptr;
		size_t size = 0;
		size_t capacity = 0;

		static double allReservationsTotal;

		void free();
		void copyFrom(const AirBnb& other);
		void resize();
		size_t calculateNewCapacity();

	public:
		AirBnb();
		AirBnb(const AirBnb&);
		AirBnb& operator=(const AirBnb& other);
		~AirBnb();

		void addAccomodation(const Accomodation& obj);
		
		void makeReservation(size_t id, unsigned daysToStay);
		void unreserve(size_t id);

		double calculateCurrentIncome() const;
		double getTotalIncome() const;

		Accomodation& getClosest(const Point& other) const;

		void removeAccomodation(size_t id);
};

