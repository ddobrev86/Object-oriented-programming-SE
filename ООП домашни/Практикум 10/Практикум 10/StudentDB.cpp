#include "StudentDB.h"
#include <utility>

const size_t StudentDB::INITIAL_CAPACITY = 16;

unsigned StudentDB::roundToPowerOfTwo(unsigned v)
{
	v--;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v++;
	return v;
}

void StudentDB::free()
{
	for (size_t i = 0; i < size; i++)
		delete students[i];

	delete[] students;
	students = nullptr;
}

void StudentDB::copyFrom(const StudentDB& other)
{
	size = other.size;
	capacity = other.capacity;

	students = new Student * [capacity] {nullptr};
	for (size_t i = 0; i < size; i++)
		students[i] = new Student(*other.students[i]);
}

void StudentDB::moveFrom(StudentDB&& other)
{
	size = other.size;
	capacity = other.capacity;

	students = other.students;
	other.students = nullptr;
}

void StudentDB::resize(size_t newCap)
{
	capacity = newCap;
	Student** temp = new Student * [capacity] {nullptr};

	for (size_t i = 0; i < size; i++)
	{
		temp[i] = students[i];
		students[i] = nullptr;
	}

	delete[] students;
	students = temp;
	temp = nullptr;
}

StudentDB::StudentDB()
{
	capacity = INITIAL_CAPACITY;
	size = 0;
	students = new Student * [capacity] {nullptr};
}

StudentDB::StudentDB(Student** students, size_t size)
{
	this->capacity = roundToPowerOfTwo(size);
	this->size = size;
	
	students = new Student * [this->capacity]{ nullptr };
	for (size_t i = 0; i < size; i++)
	{
		this->students[i] = new Student(*students[i]);
	}
}

StudentDB::StudentDB(const StudentDB& other)
{
	copyFrom(other);
}

StudentDB& StudentDB::operator=(const StudentDB& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

StudentDB::StudentDB(StudentDB&& other)
{
	moveFrom(std::move(other));
}

StudentDB& StudentDB::operator=(StudentDB&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

StudentDB::~StudentDB()
{
	free();
}

void StudentDB::add(const Student& obj)
{
	if (size >= capacity)
		resize(capacity * 2);

	students[size++] = new Student(obj);
}

void StudentDB::remove(unsigned facultyNumber)
{
	for (size_t i = 0; i < size; i++)
	{
		if (students[i]->getFacultyNumber() == facultyNumber)
		{
			std::swap(students[i], students[size - 1]);
			delete students[size - 1];
			students[size - 1] = nullptr;
			size--;

			return;
		}
	}

	throw std::invalid_argument("There isn't a student with this faculty number");
}

Student& StudentDB::find(unsigned facultyNumber) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (students[i]->getFacultyNumber() == facultyNumber)
		{
			return *students[i];
		}
	}

	throw std::invalid_argument("There isn't a student with this faculty number");
}

void StudentDB::display() const
{
	for (size_t i = 0; i < size; i++)
	{
		students[i]->displayInfo();
		std::cout << '\n';
	}
}
