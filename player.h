#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"

class Player{
    std::string name;
    std::shared_ptr<Player> opponent;
    vector<std::shared_ptr<Card>> hand;
    vector<std::shared_ptr<Card>> minions;
    std::shared_ptr<Card> ritual;
    vector<std::shared_ptr<Card>> graveyard;
    vector<std::shared_ptr<Card>> notOut;
    int health;
    int magic;
    int magicCap;
public:
    void giveName(string name);
    void setOpponent(std::shared_ptr<Player> &);
    void giveDeck(vector<std::shared_ptr<Card>> deck);
    bool died();
    std::shared_ptr<Card> getIthMinion();
    void playCard(int, bool);
    void playCard(int, std::shared_ptr<Player>, int, bool);
    void useAbility(int, bool);
    void useAbility(int, std::shared_ptr<Player>, int, bool);
    void draw();
    void discard();
    void inspect(int);
    void shuffle();
    void takeAttack(int damage); //agianst player
    void attack(int index); // against player
    void takeAttack(int damage,int index); // against minion
    void attack(int, int); // against minion
    void killMinion(int );
    void reviveMinion(int );
    void allEditDefense(int );
    void checkTrigger(TriggerType );
    void summonCard(int count, std::string name);
    std::shared_ptr<Player> getOpponent();
};

#endif
