#pragma once
#include "Student.h"

class StudentDB
{
private:
	static unsigned roundToPowerOfTwo(unsigned v);

protected:
	static const size_t INITIAL_CAPACITY;

	Student** students;
	size_t size;
	size_t capacity;

	void free();
	void copyFrom(const StudentDB& other);
	void moveFrom(StudentDB&& other);

	void resize(size_t newCap);
	size_t calculateNewCapacity();
public: 
	StudentDB();
	StudentDB(Student** students, size_t size);
	StudentDB(const StudentDB& other);
	StudentDB& operator=(const StudentDB& other);
	StudentDB(StudentDB&& other);
	StudentDB& operator=(StudentDB&& other);
	~StudentDB();

	void add(const Student& obj);
	void remove(unsigned facultyNumber);
	Student& find(unsigned facultyNumber) const;
	void display() const;
};

