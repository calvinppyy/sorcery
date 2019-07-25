#ifndef MINION_H
#define MINION_H
#include "card.h"

class Enchantment, Card;

class Minion:public Card{
    int attack, health, playCost, abilityCost, action, actionCap;
    bool silenced;
    std::vector<std::shared_ptr<Enchantment>> enchantments;
    
public:
    Minion(std::string name, std::string owner, LocationType location,
    int numInLocation, int attack, int health, int magic, int cost);
    void playCard() override;
    void editAttack(int) override;
    void editHealth(int) override;
    void addEnchantment(std::shared_ptr<Enchantment>&) override;
    void startCast(std::shared_ptr<Player>&, std::shared_ptr<Card>&) override;
    void endCast(std::shared_ptr<Player>&, std::shared_ptr<Card>&) override;
    void cast(std::shared_ptr<Player>&, std::shared_ptr<Card>&) override;
    void addEnchantment(std::shared_ptr<Enchantment>&) override;
    void inspect() override;
    void print(boolean) override;
    std::string getDescription() override;
    int getHealth() override;
    void editHealth(int) override;
    int getMagic() override;
    void editMagic(int) override;
    int getAttack() override;
    void editAttack(int) override;
    int getCost() override;
    void editCost(int) override;
    Info getInfo() override;
    void notify(<std::shared_ptr<Card> &whoFrom) override;
    void attack();
    void attack(std::shared_ptr<Player>&, int);
};

#endif
