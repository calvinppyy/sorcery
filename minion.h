#ifndef MINION_H
#define MINION_H
#include "card.h"
#include "enchantment.h"

class Minion:public Card{
    int attack, health, healthCap;
    std::vector<std::unique_ptr<Enchantment>> buffs;
    //Ability ability;
public:
    virtual void editAttack(int value) = 0;
    virtual void editHealth(int value) = 0;
    virtual void addEnchantment(std::unique_ptr<Enchantment> enchantment) = 0;
    virtual void playCard() = 0;
};

#endif
