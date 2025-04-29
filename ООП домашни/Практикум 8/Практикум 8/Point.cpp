#include "Point.h"
#include <iostream>

Point::Point()
{
	this->x = 0;
	this->y = 0;
}

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

double Point::calculateDistance(const Point& other) const
{
	int xDiff = other.x - x;
	int yDiff = other.y - y;

	return sqrt(xDiff * xDiff + yDiff * yDiff);
}