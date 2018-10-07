#include "carddeck.h"
#include "game.h"

CardDeck::CardDeck()
{
    for (int i = int(Suits::CLUBS); i <= int(Suits::SPADES); i++) // 4 suits
        for(int j = int(CardNames::SIX); j <= int(CardNames::ACE); j++) // 9 card names of each suit
        {
            Card* card = new Card(i, j, 6+j);
            Deck.push_back(card); // insert card to the deck
        }
}

CardDeck::~CardDeck()
{
    for (Card* card : Deck)
        delete card;
}

void CardDeck::Shuffle()
{
    for(int i = 0; i < 3; i++)
        std::random_shuffle(Deck.begin(), Deck.end());
}

Card* CardDeck::GetRandomCard()
{
    int random = rand() % 36; // get random card index
    return Deck[random];
}

void CardDeck::UpdateCardPoint()
{
    for (Card* card : Deck)
        if (card->getSuit() == sGame->GetTrumpSuit())
            card->AddTrumpPoint();
}

Card* CardDeck::GetCard()
{
    return Deck[0];
}

void CardDeck::RemoveCardFromDeck()
{
    Deck.erase(Deck.begin());
}
