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

class Card: public Subject<Info, State>, public Observer<Info, State> {
protected:
    std::string name;
    std::string description;
    int magic;
    Info info;
    State state;
public:
    Card(std::string name = "", std::string description = "", int magic = 0);
    virtual void playCard(Player* player) = 0;
    virtual void editAttack(int value) = 0;
    virtual void editHealth(int value) = 0;
    virtual void addEnchantment(std::unique_ptr<Enchantment> enchantment) = 0;
};

#endif
