#ifndef GAME_H
#define GAME_H

#include <algorithm>

#include "iostream"
#include "carddeck.h"
#include "player.h"
#include "card.h"

class Player;
class CardDeck;
class Card;

enum class Suits
{
    CLUBS,      // крести
    DIAMONDS,   // бубны
    HEARTS,     // черви
    SPADES      // пики
};

enum class CardNames
{
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

class Game
{
    public:
    static Game* instance();
    void Start();
    void ProvideTrumpCard(CardDeck* card_deck);
    std::string GetTrumpSuit();
    void AddPlayers(int plr_count);
    void DealCards(CardDeck* card_deck);
    void ShowPlayerCards();
    void ProvideStrongestCardSet();

    private:
    Game();
    ~Game();
    Card* trump_card;
    std::vector<Player*> Players;
};

#define sGame Game::instance()

#endif // GAME_H
