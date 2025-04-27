#pragma once
#include <iostream>

enum class Color
{
	RED,
	BLUE,
	GREEN,
	YELLOW
};

class Card
{
	protected:
		Color color;

		void printColor(std::ostream& os) const;
	public:
		Card(Color color);
		Card(int color);

		Color getColor() const;

		friend std::ostream& operator<<(std::ostream& os, Card card);
};