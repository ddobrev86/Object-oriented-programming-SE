#include "PlayingHand.h"
#include <stdlib.h>

const size_t PlayingHand::INITIAL_CAPACITY = 5;

void PlayingHand::free()
{
	for (size_t i = 0; i < drawCardsSize; i++)
		delete[] drawCards[i];

	for (size_t i = 0; i < numberCardsSize; i++)
		delete[] numberCards[i];

	for (size_t i = 0; i < specialCardsSize; i++)
		delete[] specialCards[i];

	delete[] numberCards;
	delete[] drawCards;
	delete[] specialCards;

	numberCards = nullptr;
	drawCards = nullptr;
	specialCards = nullptr;
}

void PlayingHand::copyFrom(const PlayingHand& other)
{
	drawCardsCapacity = other.drawCardsCapacity;
	drawCardsSize = other.drawCardsSize;

	numberCardsCapacity = other.numberCardsCapacity;
	numberCardsSize = other.numberCardsSize;

	specialCardsCapacity = other.specialCardsCapacity;
	specialCardsSize = other.specialCardsSize;

	drawCards = new DrawCard * [drawCardsCapacity] {nullptr};
	numberCards = new NumberCard * [numberCardsCapacity] { nullptr };
	specialCards = new SpecialCard * [specialCardsCapacity] {nullptr};

	for (size_t i = 0; i < drawCardsSize; i++)
		drawCards[i] = new DrawCard(*(other.drawCards[i]));

	for (size_t i = 0; i < numberCardsSize; i++)
		numberCards[i] = new NumberCard(*(other.numberCards[i]));

	for (size_t i = 0; i < specialCardsSize; i++)
		specialCards[i] = new SpecialCard(*(other.specialCards[i]));
}

void PlayingHand::moveFrom(PlayingHand&& other)
{
	drawCardsCapacity = other.drawCardsCapacity;
	drawCardsSize = other.drawCardsSize;

	numberCardsCapacity = other.numberCardsCapacity;
	numberCardsSize = other.numberCardsSize;

	specialCardsCapacity = other.specialCardsCapacity;
	specialCardsSize = other.specialCardsSize;

	drawCards = other.drawCards;
	other.drawCards = nullptr;

	numberCards = other.numberCards;
	other.numberCards = nullptr;

	specialCards = other.specialCards;
	specialCards = nullptr;
}

size_t PlayingHand::calculateNewCapacity(size_t neededCapacity) const
{
	size_t result = neededCapacity;
	size_t mask = INITIAL_CAPACITY;
	
	while (result & mask)
	{
		result ^= mask;
		mask <<= 1;
	}

	result ^= mask;

	return result;
}

void PlayingHand::resizeDraw()
{
	drawCardsCapacity = calculateNewCapacity(drawCardsCapacity);

	DrawCard** temp = new DrawCard * [drawCardsCapacity] {nullptr};
	for (size_t i = 0; i < drawCardsSize; i++)
	{
		temp[i] = drawCards[i];
		drawCards[i] = nullptr;
	}

	delete[] drawCards;
	drawCards = temp;
	temp = nullptr;
}

void PlayingHand::resizeNumber()
{
	numberCardsCapacity = calculateNewCapacity(numberCardsCapacity);

	NumberCard** temp = new NumberCard * [numberCardsCapacity] {nullptr};
	for (size_t i = 0; i < numberCardsSize; i++)
	{
		temp[i] = numberCards[i];
		numberCards[i] = nullptr;
	}

	delete[] numberCards;
	numberCards = temp;
}

void PlayingHand::resizeSpecial()
{
	specialCardsCapacity = calculateNewCapacity(specialCardsCapacity);

	SpecialCard** temp = new SpecialCard * [specialCardsCapacity] {nullptr};
	for (size_t i = 0; i < specialCardsSize; i++)
	{
		temp[i] = specialCards[i];
		specialCards[i] = nullptr;
	}

	delete[] specialCards;
	specialCards = temp;
}

PlayingHand::PlayingHand()
{
	drawCardsCapacity = INITIAL_CAPACITY;
	drawCardsSize = 0;

	numberCardsCapacity = INITIAL_CAPACITY;
	numberCardsSize = 0;

	specialCardsCapacity = INITIAL_CAPACITY;
	specialCardsSize = 0;

	drawCards = new DrawCard * [drawCardsCapacity] {nullptr};
	numberCards = new NumberCard * [numberCardsCapacity] {nullptr};
	specialCards = new SpecialCard * [specialCardsCapacity] {nullptr};
}

PlayingHand::PlayingHand(const PlayingHand& other)
{
	copyFrom(other);
}

PlayingHand& PlayingHand::operator = (const PlayingHand & other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

PlayingHand::PlayingHand(PlayingHand&& other) noexcept
{
	moveFrom(std::move(other));
}

PlayingHand& PlayingHand::operator = (PlayingHand && other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

PlayingHand::~PlayingHand()
{
	free();
}

void PlayingHand::drawCard()
{
	int cardType = rand() % 3;
	int color = rand() % 4;


	unsigned cardNumber;
	int speialCardType;
	unsigned drawAmount;

	switch (cardType)
	{
		case 0:
			if (numberCardsSize >= numberCardsCapacity)
				resizeNumber();

			cardNumber = rand() % 10;
			numberCards[numberCardsSize++] = new NumberCard(color, cardNumber);
			break;
		case 1:
			if (specialCardsSize >= specialCardsCapacity)
				resizeSpecial();

			speialCardType = rand() % 2;
			specialCards[specialCardsSize++] = new SpecialCard(color, cardType);
			break;
		case 2:
			if (drawCardsSize >= drawCardsCapacity)
				resizeDraw();

			drawAmount = 4 + (rand() % 2) * 2;
			drawCards[drawCardsSize++] = new DrawCard(color, drawAmount);
			break;
	}
}

int findMatchingCard(Card** cards, size_t& size, const NumberCard& givenCard)
{
	for (size_t i = 0; i < size; i++)
	{
		if (givenCard == *(cards[i]))
		{

			std::swap(cards[i], cards[size - 1]);
			size--;
			return true;
		}
	}
	
	return -1;
}

void PlayingHand::removeCard(const NumberCard& givenCard)
{
	for (size_t i = 0; i < numberCardsSize; i++)
	{
		if (givenCard == *(numberCards[i]))
		{
			std::swap(numberCards[i], numberCards[numberCardsSize - 1]);
			numberCardsSize--;
			return;
		}
	}

	for (size_t i = 0; i < specialCardsSize; i++)
	{
		if (givenCard == *(specialCards[i]))
		{
			std::swap(specialCards[i], specialCards[specialCardsSize - 1]);
			specialCardsSize--;
			return;
		}
	}

	for (size_t i = 0; i < drawCardsSize; i++)
	{
		if (givenCard == *(drawCards[i]))
		{
			std::swap(drawCards[i], drawCards[drawCardsSize - 1]);
			drawCardsSize--;
			return;
		}
	}

	drawCard();
}

std::ostream& operator<<(std::ostream& os, const PlayingHand& hand)
{
	for (size_t i = 0; i < hand.numberCardsSize; i++)
		os << *(hand.numberCards[i]) << '\n';

	for (size_t i = 0; i < hand.specialCardsSize; i++)
		os << *(hand.specialCards[i]) << '\n';

	for (size_t i = 0; i < hand.drawCardsSize; i++)
		os << *(hand.drawCards[i]) << '\n';

	return os;
}
