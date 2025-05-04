#include "Ticket.h"

Ticket::Ticket(const char* name, double price) : playName(name)
{
	this->price = price;
}

Ticket::Ticket(const MyString& name, double price) : playName(name)
{
	this->price = price;
}

std::ostream& operator<<(std::ostream& os, const Ticket& ticket)
{
	os << "Play name: " << ticket.playName << "\nPrice: " << ticket.price;

	return os;
}
