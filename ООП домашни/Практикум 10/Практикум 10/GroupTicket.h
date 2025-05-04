#pragma once
#include "Ticket.h"

class GroupTicket : public Ticket
{
public:
	GroupTicket(const char* name, double price);
	GroupTicket(const MyString& name, double price);
};

