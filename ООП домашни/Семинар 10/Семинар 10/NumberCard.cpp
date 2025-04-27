#include "NumberCard.h"
#include <stdexcept>

const unsigned NumberCard::MAX_CARD_VALUE = 9;

NumberCard::NumberCard(Color color, unsigned number) : Card(color)
{
	if (number > MAX_CARD_VALUE)
		throw std::invalid_argument("Card number should be between 0 and 9");

	this->number = number;
}

NumberCard::NumberCard(int color, unsigned number) : NumberCard((Color)color, number) {}

std::ostream& operator<<(std::ostream& os, const NumberCard& card)
{
	card.printColor(os);
	os << " " << card.number;

	return os;
}

bool operator==(const NumberCard& lhs, const NumberCard& rhs)
{
	return lhs.color == rhs.color || lhs.number == rhs.number;
}

bool operator==(const NumberCard& lhs, const Card& rhs)
{
	return lhs.color == rhs.getColor();
}
