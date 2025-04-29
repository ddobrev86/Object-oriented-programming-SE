#pragma once
#include "Computer.h"
#include <iostream>

class ComputerStore
{
private:
	static const size_t INITIAL_CAPACITY;

	char* name;
	Computer* computers;
	size_t size;
	size_t capacity;

	void free();
	void copyFrom(const ComputerStore& other);
	void resize();
	size_t calculateNewCapacity();

public:
	ComputerStore(const char* name);
	ComputerStore(const ComputerStore& other);
	ComputerStore& operator=(const ComputerStore& other);
	~ComputerStore();

	void addComputer(const Computer& computer);
	friend std::ostream& operator<<(std::ostream& os, const ComputerStore& obj);
	void buy(const char* brand, unsigned money);
	void printAvailable() const;
	void printAvailable(bool (*filter)(const Computer&)) const;
};

