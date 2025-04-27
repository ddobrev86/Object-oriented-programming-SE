#pragma once
#include "Card.h"
#include "DrawCard.h"
#include "NumberCard.h"
#include "SpecialCard.h"

class PlayingHand
{
private:
	static const size_t INITIAL_CAPACITY;

	DrawCard** drawCards;
	NumberCard** numberCards;
	SpecialCard** specialCards;

	size_t drawCardsSize;
	size_t drawCardsCapacity;

	size_t numberCardsSize;
	size_t numberCardsCapacity;

	size_t specialCardsSize;
	size_t specialCardsCapacity;

	void free();
	void copyFrom(const PlayingHand& other);
	void moveFrom(PlayingHand&& other);
	size_t calculateNewCapacity(size_t neededCapacity) const;

	void resizeDraw();
	void resizeNumber();
	void resizeSpecial();

public:
	PlayingHand();
	PlayingHand(const PlayingHand& other);
	PlayingHand& operator=(const PlayingHand& other);
	PlayingHand(PlayingHand&& other) noexcept;
	PlayingHand& operator=(PlayingHand&& other) noexcept;
	~PlayingHand();

	void drawCard();
	void removeCard(const NumberCard& givenCard);
	friend std::ostream& operator<<(std::ostream& os, const PlayingHand& hand);
};

