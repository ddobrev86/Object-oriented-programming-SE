#pragma once
struct A
{
	int x;
	int y;
};

class B
{
private:
	static const size_t INITIAL_CAPACITY;

	A** data;
	size_t capacity;
	size_t size;

	void free();
	void copyFrom(const B& other);
	void moveFrom(B&& other);

	void resize(size_t newCap);

public:
	B();
	B(const B& other);
	B& operator=(const B& other);
	~B();

	B(B&& other) noexcept;
	B& operator=(B&& other) noexcept;

	void add(const A& obj);

};