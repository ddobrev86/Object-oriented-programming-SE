#pragma once
#include "MyString.h"

class Student
{
private:
	static unsigned counter;

	MyString name;
	unsigned facultyNumber;
	unsigned year;
public:
	Student(const char* name);
	Student(const MyString& name);

	MyString getName() const;
	unsigned getFacultyNumber() const;
	unsigned getYear() const;

	void setYear(unsigned year);

	void displayInfo() const;
};

