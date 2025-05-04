#include "GroupTicket.h"


GroupTicket::GroupTicket(const char* name, double price) : Ticket(name, price * 0.8) {}

GroupTicket::GroupTicket(const MyString& name, double price) : Ticket(name, price * 0.8) {}