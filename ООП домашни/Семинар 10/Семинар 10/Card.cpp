#include "Card.h"

void Card::printColor(std::ostream& os) const
{
	switch (color)
	{
	case Color::RED:
		os << "Red";
		break;
	case Color::BLUE:
		os << "Blue";
		break;
	case Color::GREEN:
		os << "Green";
		break;
	case Color::YELLOW:
		os << "Yellow";
		break;
	}
}

Card::Card(Color color)
{
	this->color = color;
}

Card::Card(int color)
{
	this->color = (Color)color;
}

std::ostream& operator<<(std::ostream& os, Card card)
{
	switch (card.color)
	{
		case Color::RED:
			os << "Red";
			break;
		case Color::BLUE:
			os << "Blue";
			break;
		case Color::GREEN:
			os << "Green";
			break;
		case Color::YELLOW:
			os << "Yellow";
			break;
	}

	return os;
}

Color Card::getColor() const
{
	return color;
}
