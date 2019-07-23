#ifndef CARD_H
#define CARD_H
#include "allCard.h"
#include <memory>
#include <string>
#include <vector>

class Card{
    protected:
        std::string name;
        std::string description;
        int magic;
    public:
        Card(std::string name = "", std::string description = "", int magic = 0);
        virtual void playCard(Player) = 0; 
};

#endif
