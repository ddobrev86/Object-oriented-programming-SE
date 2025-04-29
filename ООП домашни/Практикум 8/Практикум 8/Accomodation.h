#pragma once
#include "Point.h"

enum class AccType
{
	Apartment,
	Villa,
	Hotel
};

class Accomodation
{
private:
	static size_t counter;

	size_t id;
	char* name;
	AccType type;
	Point coordinates;
	double price;
	bool isBooked;
	unsigned daysToStay;

	void free();
	void copyFrom(const Accomodation& other);
	
	void setId();

public:
	Accomodation();
	Accomodation(const char* name, AccType type,
		const Point& coordinates, double price);
	Accomodation(const Accomodation& other);
	Accomodation& operator=(const Accomodation& other);
	~Accomodation();

	void setName(const char* name);
	void setAccType(AccType type);
	void setCoordinates(const Point& coord);
	void setPrice(double price);
	void setIsBooked(bool isBooked);
	void setDaysToStay(unsigned daysToStay);

	const size_t& getId() const;
	const char* getName() const;
	AccType getAccType() const;
	const Point getCoordinates() const;
	double getPrice() const;
	bool getIsBooked() const;
	unsigned getDaysToStay() const;

	void makeReservation(unsigned daysToStay);
	void unreserve();

	double calculateTotalPrice() const;
};

