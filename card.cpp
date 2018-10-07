#include <iostream>
#include "card.h"

Card::Card(int _suit, int _name, int _point) : point(_point)
{
    std::string text_s[] = { "clubs", "diamonds", "hearts", "spades" };
    std::string text_n[] = { "six", "seven", "eight", "nine", "ten", "jack", "queen", "king", "ace" };

    suit = text_s[_suit];
    name = text_n[_name];
}

std::string Card::getSuit()
{
    return suit;
}

std::string Card::getName()
{
    return name;
}

int Card::getPoint()
{
    return point;
}

void Card::AddTrumpPoint()
{
    point+=9;
}
