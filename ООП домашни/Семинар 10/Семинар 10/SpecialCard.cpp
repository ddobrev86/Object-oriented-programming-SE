#include "SpecialCard.h"

void SpecialCard::printAction(std::ostream& os) const
{
	switch (action)
	{
		case Action::REVERSE:
			os << " Reverse";
			break;
		case Action::SKIP:
			os << " Skip";
			break;
	}
}

SpecialCard::SpecialCard(Color color, Action action) : Card(color)
{
	this->action = action;
}

SpecialCard::SpecialCard(int color, Action action) : SpecialCard((Color)color, action)
{}

SpecialCard::SpecialCard(Color color, int action) : SpecialCard(color, (Action)action)
{}

SpecialCard::SpecialCard(int color, int action) : SpecialCard((Color)color, (Action)action) 
{}

std::ostream& operator<<(std::ostream& os, const SpecialCard& card)
{
	card.printColor(os);
	card.printAction(os);

	return os;
}
