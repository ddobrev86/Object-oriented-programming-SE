#pragma once
#include "MyString.h"
#include <iostream>

class Ticket
{
protected:
	MyString playName;
	double price;

public:
	Ticket(const char* name, double price);
	Ticket(const MyString& name, double price);

	friend std::ostream& operator<<(std::ostream& os, const Ticket& ticket);
};

