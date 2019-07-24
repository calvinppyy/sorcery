#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"

using namespace std;

class Player{
    string name;
    vector<unique_ptr<Card>> hand;
    vector<unique_ptr<Card>> minions;
    unique_ptr<Card>i ritual;
    vector<unique_ptr<Card>> graveyard;
    vector<unique_ptr<Card>> notOut;
    int health;
    int healthCap;
    int magic;
    int magicCap;
public:
    Player(string name = "", vector<unique_ptr<Deck>> notOut);
    void giveName(string name);
    void giveDeck(unique_ptr<Deck> &deck, string what);
    bool died();
    unique_ptr<Card> getIthMinion();
    void playCard(int i);
};

#endif
