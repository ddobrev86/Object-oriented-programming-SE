#include "Timestamp.h"

Timestamp::Timestamp()
{
	time = 0;
}

Timestamp::Timestamp(unsigned time)
{
	setTime(time);
}

void Timestamp::setTime(unsigned time)
{
	this->time = time;
}

unsigned Timestamp::getTime() const
{
	return time;
}

std::istream& operator>>(std::istream& is, Timestamp& timestamp)
{
	is >> timestamp.time;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Timestamp& timestamp)
{
	os << timestamp.time << " seconds since Jan 01 1970. (UTC)";
	return os;
}

Timestamp& Timestamp::operator+=(unsigned timeToAdd)
{
	time += timeToAdd;
	return *this;
}