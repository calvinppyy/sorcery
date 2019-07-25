#ifndef SPELL_H
#define SPELL_H
#include "card.h"

class Spell:public Card{
    int magic;
public:
    void playCard(&std::unique_ptr<Player>) override;
    void editAttack(int) override;
    void editHealth(int) override;
    void addEnchantment(std::unique_ptr<Enchantment> &) override;
    void cast(std::unique_ptr<Player>&, int) override;
    void inspect() override;
    void print(bool) override;
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
    bool die() override;
    void notify() override;
};

#endif
