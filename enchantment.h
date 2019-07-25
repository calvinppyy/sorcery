#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H
#include "card.h"

class Enchantment : public Card{
    int attack;
    int defense;
    int abilityCost;
    bool silence;
    int action;
    std::shared_ptr<Card> target;
public:
    virtual void playCard() = 0;
    virtual void editAttack(int) = 0;
    virtual void editHealth(int) = 0;
    virtual void addEnchantment(std::unique_ptr<Enchantment> &) = 0;
    virtual void cast(std::unique_ptr<Player> &, int ) = 0;
    virtual void inspect() = 0;
    virtual void print(boolean) = 0;
    virtual std::string getDescription() = 0;
    virtual int getHealth() = 0;
    virtual void editHealth(int) = 0;
    virtual int getMagic() = 0;
    virtual void editMagic(int) = 0;
    virtual int getAttack() = 0;
    virtual void editAttack(int) = 0;
    virtual int getCost() = 0;
    virtual void editCost(int) = 0;
    virtual int getUsage() = 0;
    virtual void editUsage(int) = 0;
    virtual Info getInfo() = 0;
    virtual bool died() = 0;
    void notify() override;
};

#endif
