#pragma once
class Point
{
	private:
		double x;
		double y;
	public:
		Point();
		Point(int x, int y);

		double calculateDistance(const Point& other) const;
};