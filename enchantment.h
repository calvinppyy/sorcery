#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H
#include "card.h"
#include <memory>
#include <string>
#include <vector>

class Card;

class Enchantment : public Card{
    int attack;
    int defense;
    int abilityCost;
    bool silenced;
    int action;
    int playCost;
    std::shared_ptr<Card> target;
public:
    Enchantment(std::string name, std::shared_ptr<Player> owner);
    void silence(bool);
    void playCard(std::shared_ptr<Card> target);
    void playCard(std::shared_ptr<Player> target, int index);
    void addEnchantment(std::shared_ptr<Enchantment> echantment);
    void popEnchantment();
    void clearEnchantment();
    void cast(std::shared_ptr<Card> target);
    void cast(std::shared_ptr<Player> opponent, int index);
    void inspect(bool graphicsEnabled);
    void print(bool graphicsEnabled);
    std::string getDescription();
    int getDefence();
    void editDefence(int defence);
    int getPlayCost();
    void editPlayCost(int playCost);
    int getAttack();
    void editAttack(int attack);
    int getAbilityCost(); //ritual, minion
    void editAbilityCost(int ac); //ritual minion
    int getUsage(); //for ritual
    void editUsage(int); //for ritual
    int getAction();
    void editAction(int action);
    bool died();
};

#endif
