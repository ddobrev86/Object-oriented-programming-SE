#pragma once
#include <iostream>

class Timestamp
{
protected:
	unsigned time;

public:
	Timestamp();
	Timestamp(unsigned time);

	void setTime(unsigned time);
	unsigned getTime() const;

	friend std::istream& operator>>(std::istream& is, Timestamp& timestamp);
	friend std::ostream& operator<<(std::ostream& os, const Timestamp& timestamp);
	Timestamp& operator+=(unsigned timeToAdd);
};

