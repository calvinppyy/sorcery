#ifndef ABILITIES_H
#define ABILITIES_H
#include "card.h"

class Ability{
public:
    virtual void triggerAbility(std::unique_ptr<Card> card) = 0;
}

class BoGolem: public Ability{
    std::string description = "Gain +1/+1 whenever a minion leaves a play";
public:
    std::string getDescription(){ return description;}
    void triggerAbility(std::unique_ptr<Card> card){
        card->editHealth(1);
        card->editAttack(1);
    }
}


#endif
