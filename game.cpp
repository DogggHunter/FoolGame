#include <ctime>
#include <iostream>
#include <string>

#include "game.h"

using namespace std;

Game::Game()
{

}

Game::~Game()
{
    for (Player* plr : Players)
        delete plr;
}

Game* Game::instance()
{
    static Game instance;
    return &instance;
}

void Game::Start()
{
    string str;
    int n = 0;

    while(true)
    {
        cout << "Enter the number of players: ";
        cin >> str;

        // exception "invalid_argument" if string not a number
        try{
            n = stoi(str);
        }
        catch (const invalid_argument& ia) {
            cerr << "The count of players must be a number" << endl;
            continue;
        }

        if (n > 6 || n < 2)
            cout << "The number of players must vary from 2 to 6" << endl << endl;
        else break;
    }

    AddPlayers(n); // add new players

    srand(time(0)); // automatic randomization

    CardDeck* card_deck = new CardDeck(); // create new Card Deck
    card_deck->Shuffle(); // shuffling a deck of cards

    ProvideTrumpCard(card_deck); // provide a random trump card
    card_deck->UpdateCardPoint(); // update point for trump cards
    DealCards(card_deck); // deal cards for players
    ShowPlayerCards();
    ProvideStrongestCardSet();

    delete card_deck; // memory release

    return;
}

void Game::ProvideTrumpCard(CardDeck* card_deck)
{
    trump_card = card_deck->GetRandomCard();
    cout << "Trump suit is: " << trump_card->getSuit() << endl << endl;

    return;
}

string Game::GetTrumpSuit()
{
    return trump_card->getSuit();
}

void Game::AddPlayers(int plr_count)
{
    for (int i = 0; i < plr_count; i++)
    {
        Player* plr = new Player(i+1);
        Players.push_back(plr);
    }

    return;
}

void Game::DealCards(CardDeck* card_deck)
{
    for (int i = 0; i < 6; i++) // 6 card for one player
    {
        for (Player* plr : Players)
        {
           plr->insertCard(card_deck->GetCard()); // add a card to the player set
           card_deck->RemoveCardFromDeck(); // remove card from the deck
        }
    }

    return;
}

void Game::ShowPlayerCards()
{
    for (Player* plr : Players)
    {
        cout << "Player number " << plr->getNumber() << " has such a set of cards:" << endl;
        plr->showCards(); // show player cards to the console
    }

    return;
}

void Game::ProvideStrongestCardSet()
{
    int plr_points[Players.size()];

    for (int i = 0; i < Players.size(); i++)
        plr_points[i] = Players[i]->getPoints();

    int max_points = *max_element(plr_points, plr_points+Players.size());

    for (Player* plr : Players)
        if (plr->getPoints() == max_points)
        {
            cout << "The strongest set of cards has Player number: " << plr->getNumber() << " with " << max_points << " points";
            break;
        }

    return;
}
