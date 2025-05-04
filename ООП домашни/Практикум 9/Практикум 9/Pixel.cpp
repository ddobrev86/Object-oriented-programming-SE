#include "Pixel.h"

Pixel::Pixel()
{
	r = 0;
	g = 0;
	b = 0;
}

Pixel::Pixel(uint8_t r, uint8_t g, uint8_t b)
{
	setRed(r);
	setGreen(g);
	setBlue(b);
}

void Pixel::setRed(uint8_t r)
{
	this->r = r;
}

void Pixel::setGreen(uint8_t g)
{
	this->g = g;
}

void Pixel::setBlue(uint8_t b)
{
	this->b = b;
}

uint8_t Pixel::getRed() const
{
	return r;
}

uint8_t Pixel::getGreen() const
{
	return g;
}

uint8_t Pixel::getBlue() const
{
	return b;
}

std::ostream& operator<<(std::ostream& os, const Pixel& pixel)
{
	os << "(" << (int)pixel.r << ", " << (int)pixel.g << ", " << (int)pixel.b << ")";
	return os;
}