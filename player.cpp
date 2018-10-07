#include <iostream>

#include "card.h"
#include "player.h"

using namespace std;

Player::Player(int _number) : cardPoints(0), number(_number)
{

}

void Player::insertCard(Card* card)
{
    CardSet.push_back(card);
    cardPoints+=card->getPoint();
}

void Player::showCards()
{
    for (Card* card : CardSet)
        cout << card->getSuit() << " " << card->getName() << endl;
    cout << endl;
}

int Player::getPoints()
{
    return cardPoints;
}

int Player::getNumber()
{
    return number;
}
