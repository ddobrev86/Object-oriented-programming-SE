#include "Student.h"
#include <stdexcept>

unsigned Student::counter = 1;

Student::Student(const char* name)
{
	if (!name)
		throw std::invalid_argument("Emtpy name");

	this->name = MyString(name);
	year = 1;
	facultyNumber = Student::counter++;
}

Student::Student(const MyString& name)
{
	this->name = name;
	year = 1;
	facultyNumber = Student::counter++;
}

MyString Student::getName() const
{
	return name;
}

unsigned Student::getFacultyNumber() const
{
	return facultyNumber;
}

unsigned Student::getYear() const
{
	return year;
}

void Student::setYear(unsigned year)
{
	this->year = year;
}

void Student::displayInfo() const
{
	std::cout << "Name: " << name <<
		"\nFaculty Number: " << facultyNumber <<
		"\nYear: " << year;
}
