#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "trigger.h"
#include "ascii_graphics.h"

class Player;
class Enchantment;
class Minion;
class Spell;
class Ritual;

class Card{
    protected:
    std::string name;
    TriggerType triggerType;
    std::shared_ptr<Player> owner;

public:
    Card(std::string, std::shared_ptr<Player>);
    virtual void silence(bool) = 0;
    virtual void playCard(std::shared_ptr<Player> target, int index) = 0;
    virtual void addEnchantment(std::shared_ptr<Enchantment>) = 0;
    virtual void popEnchantment() = 0;
    virtual void clearEnchantment() = 0;
    virtual void cast(Player&, int ) = 0;
    virtual void inspect(bool) = 0;
    virtual std::string getDescription() = 0;
    virtual int getDefence() = 0;
    virtual void editDefence(int) = 0;
    virtual int getAbilityCost() = 0;
    virtual void editAbilityCost(int) = 0;
    virtual int getAttack() = 0;
    virtual void editAttack(int) = 0;
    virtual int getPlayCost() = 0; //ritual, minion
    virtual void editPlayCost(int) = 0; //ritual minion
    virtual int getUsage() = 0; //for ritual
    virtual void editUsage(int) = 0; //for ritual
    virtual int getAction() = 0;
    virtual void editAction(int) = 0;
    virtual int getUsageCap() = 0;
    virtual bool died() = 0;
    virtual void checkTrigger(TriggerType, Player&, int) = 0;
    virtual int getDefenceCap() = 0;
    virtual ~Card(){}
    std::string getName();
};



#endif
