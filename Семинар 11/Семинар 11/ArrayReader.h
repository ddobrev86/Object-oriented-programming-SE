#pragma once
class ArrayReader
{
protected:
	char* inputFile;
	char* outputFile;
	int* arr;
	size_t size;

	void free();
	void copyFrom(const ArrayReader& other);
	void moveFrom(ArrayReader&& other);
public:
	ArrayReader(const char* inputFile, const char* outputFile);
	ArrayReader(const ArrayReader& other);
	ArrayReader& operator=(const ArrayReader& other);
	ArrayReader(ArrayReader&& other) noexcept;
	ArrayReader& operator=(ArrayReader&& other) noexcept;
	virtual ~ArrayReader();

	virtual void readFromFile() = 0;
	virtual void saveToFile() const = 0;

	void sort();
};

