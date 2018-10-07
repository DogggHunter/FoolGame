#ifndef CARD_H
#define CARD_H

#include <string>

#include "game.h"

class Card
{
    public:
    Card(int _suit, int _name, int _point);
    std::string getSuit();
    std::string getName();
    int getPoint();
    void AddTrumpPoint();

    private:
    std::string suit;
    std::string name;
    int point;
};

#endif // CARD_H
