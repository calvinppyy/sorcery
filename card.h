#ifndef CARD_H
#define CARD_H
#include "allCard.h"
#include <memory>
#include <string>
#include <vector>
#include "observer.h"
#include "subject.h"
#include "info.h"
#include "state.h"
#include "rng.h"
#include "trigger.h"

class Card
{      
    protected:
    std::string name;
    TriggerType triggerType;
    std::shared_ptr<Player> owner;

public:
    Card(std::string, std::shared_ptr<Player>);
    virtual void playCard() = 0;
    virtual void editAttack(int) = 0;
    virtual void editHealth(int) = 0;
    virtual void addEnchantment(std::shared_ptr<Enchantment>) = 0;
    virtual void popEnchantment() = 0;
    virtual void clearEnchantment() = 0;
    virtual void cast(std::shared_ptr<Player>, int ) = 0;
    virtual void inspect() = 0;
    virtual void print(bool) = 0;
    virtual std::string getDescription() = 0;
    virtual int getHealth() = 0;
    virtual void editHealth(int) = 0;
    virtual int getMagic() = 0;
    virtual void editMagic(int) = 0;
    virtual int getAttack() = 0;
    virtual void editAttack(int) = 0;
    virtual int getCost() = 0; //ritual, minion
    virtual void editCost(int) = 0; //ritual minion
    virtual int getUsage() = 0; //for ritual
    virtual void editUsage(int) = 0; //for ritual
    virtual bool died() = 0;
};

#endif
