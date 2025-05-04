#pragma once
#include "StudentDB.h"

class SortedStudentDB : public StudentDB
{
public:
	void sortBy(bool (*criteria)(const Student&, const Student&));
};

