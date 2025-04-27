#pragma once
class DoubleArray
{
protected:
	static const size_t INITIAL_CAPACITY;

	double* numbers;
	size_t size;
	size_t capacity;

	void free();
	void copyFrom(const DoubleArray& other);
	void moveFrom(DoubleArray&& other);
	size_t calculateNewCapacity();
	void resize();

public:
	DoubleArray();
	DoubleArray(const double* numbers, const size_t size);
	DoubleArray(const DoubleArray& other);
	DoubleArray& operator=(const DoubleArray& other);
	DoubleArray(DoubleArray&& other) noexcept;
	DoubleArray& operator=(DoubleArray&& other) noexcept;
	~DoubleArray();

	friend bool operator==(const DoubleArray& lhs, const DoubleArray& rhs);
	friend bool operator!=(const DoubleArray& lhs, const DoubleArray& rhs);
	bool isEmpty();
};

