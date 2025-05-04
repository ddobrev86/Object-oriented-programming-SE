#include "SortedStudentDB.h"

void SortedStudentDB::sortBy(bool(*criteria)(const Student&, const Student&))
{
	if (!criteria)
		throw std::invalid_argument("No sort given");

	for (size_t first = 0; first < size - 1; first++)
	{
		size_t minIndex = first;
		for (size_t second = first; second < size; second++)
		{
			if (criteria(*students[minIndex], *students[second]))
				minIndex = second;
		}

		if (first != minIndex)
			std::swap(students[first], students[minIndex]);
	}
}
