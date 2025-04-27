#pragma once
#include "Card.h"

enum class Action
{
	REVERSE,
	SKIP
};

class SpecialCard : public Card
{
protected:
	Action action;

	void printAction(std::ostream& os) const;

public:
	SpecialCard(Color color, Action action);
	SpecialCard(int color, Action action);
	SpecialCard(Color color, int action);
	SpecialCard(int color, int action);

	friend std::ostream& operator<<(std::ostream& os, const SpecialCard& card);
};

