#ifndef MINION_H
#define MINION_H
#include "card.h"

class Enchantment, Card;

class Minion:public Card{
    std::string name;
    int attack, health, healthCap, magic, cost;
    std::vector<std::unique_ptr<Enchantment>> enchantments;
public:
    void playCard(&std::unique_ptr<Player>) override;
    void editAttack(int) override;
    void editHealth(int) override;
    void addEnchantment(&std::unique_ptr<Enchantment>) override;
    void startCast(&std::unique_ptr<Player>, &std::unique_ptr<Card>) override;
    void endCast(&std::unique_ptr<Player>, &std::unique_ptr<Card>) override;
    void cast(&std::unique_ptr<Player>, &std::unique_ptr<Card>) override;
    void addEnchantment(&std::unique_ptr<Enchantment>) override;
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
    int getUsage() override;
    void editUsage(int) override;
    Info getInfo() override;
    void notify();
};

#endif
