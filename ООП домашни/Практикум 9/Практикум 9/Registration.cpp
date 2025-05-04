#include "Registration.h"
#include <stdexcept>
#include <cstring>
#pragma warning(disable:4996)

bool isUpperLatinLetter(char symbol)
{
	return symbol >= 'A' && symbol <= 'Z';
}

bool isDigit(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}

bool Registration::isValidNumber(const char* number)
{
	if (!number)
		throw std::invalid_argument("Empty string");

	size_t strSize = strlen(number);

	if (strSize > Constants::MAX_REGISTRATION_SIZE && 
		strSize < Constants::MIN_REGISTRATION_SIZE)
		throw std::invalid_argument("Invalid size");

	for (int i = strSize - 1; i >= 0; i--)
	{
		int checkedSymbols = strSize - 1 - i;

		if (checkedSymbols >= 2 && checkedSymbols < 6)
		{
			if (!isDigit(number[i]))
				throw std::invalid_argument("Invalid input");
		}
		else
		{
			if (!isUpperLatinLetter(number[i]))
				throw std::invalid_argument("Invalid input");
		}

	}
}

Registration::Registration(const char* number)
{
	if (!number)
		throw std::invalid_argument("Empty input");

	try
	{
		if(isValidNumber(number))
			strcpy(this->number, number);
	}
	catch(std::invalid_argument excp)
	{
		throw std::invalid_argument(excp.what());
	}
}

bool operator==(const Registration& first, const Registration& second)
{
	return strcmp(first.number, second.number) == 0;
}

bool operator!=(const Registration& first, const Registration& second)
{
	return !(first == second);
}

const char* Registration::getRegistrationNumber() const
{
	return number;
}