#include "DrawCard.h"

DrawCard::DrawCard(Color color, unsigned drawAmount) : Card(color)
{
	if (drawAmount != 4 && drawAmount != 6)
		throw std::invalid_argument("Draw amount should be 4 or 6");

	this->drawAmount = drawAmount;
}

DrawCard::DrawCard(int color, unsigned drawAmount) : DrawCard((Color)color, drawAmount)
{}

std::ostream& operator<<(std::ostream& os, const DrawCard& card)
{
	card.printColor(os);
	os << " +" << card.drawAmount;

	return os;
}
