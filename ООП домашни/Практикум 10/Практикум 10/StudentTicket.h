#pragma once
#include "Ticket.h"

class StudentTicket : public Ticket
{
public:
	StudentTicket(const char* name, double price);
	StudentTicket(const MyString& name, double price);
};

