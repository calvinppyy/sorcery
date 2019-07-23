#ifndef CARD_H
#define CARD_H
#include "allCard.h"
#include <memory>
#include <string>
#include <vector>
#include "player.h"

class Card{
    protected:
        std::string name;
        std::string description;
        int magic;
    public:
        Card(std::string name = "", std::string description = "", int magic = 0);
        virtual void playCard(Player* player) = 0; 
};

#endif
