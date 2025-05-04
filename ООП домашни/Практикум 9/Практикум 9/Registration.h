#pragma once
#include "Constants.h"

class Registration
{
private:
	char number[Constants::MAX_REGISTRATION_SIZE + 1]{0};

	bool isValidNumber(const char* number);
public:
	Registration(const char* number);

	friend bool operator==(const Registration& first, const Registration& second);
	friend bool operator!=(const Registration& first, const Registration& second);

	const char* getRegistrationNumber() const;
};

