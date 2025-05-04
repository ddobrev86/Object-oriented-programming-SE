#include "StudentTicket.h"

StudentTicket::StudentTicket(const char* name, double price) : Ticket(name, price / 2) {}

StudentTicket::StudentTicket(const MyString& name, double price) : Ticket(name, price / 2) {}