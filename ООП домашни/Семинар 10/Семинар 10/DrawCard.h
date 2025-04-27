#pragma once
#include "Card.h"

class DrawCard : public Card
{
protected:
	unsigned drawAmount;
public:
	DrawCard(Color color, unsigned drawAmount);
	DrawCard(int color, unsigned drawAmount);

	friend std::ostream& operator<<(std::ostream& os, const DrawCard& card);
};

