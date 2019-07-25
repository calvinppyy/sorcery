#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"

using namespace std;

class Player{
    string name;
    std::unique_ptr<Player> &opponent;
    vector<unique_ptr<Card>> hand;
    vector<unique_ptr<Card>> minions;
    unique_ptr<Card>i ritual;
    vector<unique_ptr<Card>> graveyard;
    vector<unique_ptr<Card>> notOut;
    int health;
    int magic;
    int magicCap;
public:
    void giveName(string name);
    void setOpponent(std::unique_ptr<Player> &);
    void giveDeck(vector<unique_ptr<Card>> &deck, string what);
    bool died();
    unique_ptr<Card> getIthMinion();
    void playCard(int, bool);
    void playCard(int, unique_ptr<Player>, int, bool);
    void useAbility(int, bool);
    void useAbility(int, unique_ptr<Player>, int, bool);
    void draw();
    void discard();
    void inspect(int);
};

#endif
