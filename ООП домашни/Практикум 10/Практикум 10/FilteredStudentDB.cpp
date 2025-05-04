#include "FilteredStudentDB.h"

void FilteredStudentDB::filter(bool(*criteria)(const Student&))
{
	if(!criteria)
		throw std::invalid_argument("No sort given");

	size_t end = size - 1;
	size_t current = 0;
	size_t removed = 0;

	while (students[current])
	{
		while ((current + removed < size) && !criteria(*students[current]))
		{
			std::swap(students[current], students[end]);
			removed++;

			delete students[end];
			students[end--] = nullptr;
		}
		current++;
	}
	
	size -= removed;
}

void FilteredStudentDB::limit(size_t n)
{
	if (n > size)
		throw std::invalid_argument("Limit is greater than the size of db");

	for (size_t current = n; current < size; current++)
	{
		delete students[current];
		students[current] = nullptr;
	}

	size = n;
}
