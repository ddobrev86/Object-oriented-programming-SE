#pragma once
#include <iostream>

class Pixel
{
private:
	uint8_t r;
	uint8_t g;
	uint8_t b;
public:
	Pixel();
	Pixel(uint8_t r, uint8_t g, uint8_t b);

	void setRed(uint8_t r);
	void setGreen(uint8_t g);
	void setBlue(uint8_t b);

	uint8_t getRed() const;
	uint8_t getGreen() const;
	uint8_t getBlue() const;

	friend std::ostream& operator<<(std::ostream& os, const Pixel& pixel);
};

