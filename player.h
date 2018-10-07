#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "card.h"

class Card;

class Player
{
    public:
    Player(int _number);
    void insertCard(Card* card);
    void showCards();
    int getPoints();
    int getNumber();

    private:
    std::vector <Card*> CardSet;
    int cardPoints;
    int number;
};

#endif // PLAYER_H
