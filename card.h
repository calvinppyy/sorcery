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

class Card: public Subject<Info, State>, public Observer<Info, State> {
public:
    virtual void playCard(&std::unique_ptr<Player>)=0;
    virtual void editAttack(int)=0;
    virtual void editHealth(int)=0;
    virtual void addEnchantment(&std::unique_ptr<Enchantment>)=0;
    virtual void cast(&std::unique_ptr<Player>, &std::unique_ptr<Card>)=0;
    virtual void startCast(&std::unique_ptr<Player>, &std::unique_ptr<Card>)=0;
    virtual void endCast(&std::unique_ptr<Player>, &std::unique_ptr<Card>)=0;
    virtual void addEnchantment(&std::unique_ptr<Enchantment>)=0;
    virtual void inspect()=0;
    virtual void print(boolean)=0;
    virtual std::string getDescription()=0;
    virtual int getHealth()=0;
    virtual void editHealth(int)=0;
    virtual int getMagic()=0;
    virtual void editMagic(int)=0;
    virtual int getAttack()=0;
    virtual void editAttack(int)=0;
    virtual int getCost()=0;
    virtual void editCost(int)=0;
    virtual int getUsage()=0;
    virtual void editUsage(int)=0;
    virtual Info getInfo()=0;
};

#endif
