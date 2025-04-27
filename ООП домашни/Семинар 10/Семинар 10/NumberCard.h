#pragma once
#include "Card.h"
#include <iostream>

class NumberCard : public Card
{
	protected:
		static const unsigned MAX_CARD_VALUE;

		unsigned number;
	public:
		NumberCard(Color color, unsigned number);
		NumberCard(int color, unsigned number);

		friend std::ostream& operator<<(std::ostream& os, const NumberCard& card);
		friend bool operator==(const NumberCard& lhs, const NumberCard& rhs);
		friend bool operator==(const NumberCard& lhs, const Card& rhs);

};

