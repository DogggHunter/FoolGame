#ifndef CARDDECK_H
#define CARDDECK_H

#include <vector>
#include "card.h"

class Card;

class CardDeck
{
    public:
        CardDeck();
        ~CardDeck();

        void Shuffle();
        Card* GetRandomCard();
        void UpdateCardPoint();
        Card* GetCard();
        void RemoveCardFromDeck();

    private:
        std::vector<Card*> Deck;

};

#endif // CARDDECK_H
