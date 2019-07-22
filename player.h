#ifndef PLAYER_H
#define PLAYER_H
#include "deck.h"

class Player{
    std::string name;
    std::unique_ptr<Deck> hand;
    std::unique_ptr<Deck> minions;
    std::unique_ptr<Deck> rituals;
    std::unique_ptr<Deck> graveyard;
    std::unique_ptr<Deck> notOut;
    int health;
    int healthCap;
    int magic;
    int magicCap;
public:
    Player(std::string name = "", std::unique_ptr<Deck> notOut = nullptr);
};

#endif
