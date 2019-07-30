#include "spell.h"

Spell::Spell(std::string name, std::weak_ptr<Player> owner):Card{name,owner}{
    if (name == "Banish") {playCost = 2;}
    else if (name == "Unsummon") {playCost = 1;}
    else if (name == "Recharge") {playCost = 1;}
    else if (name =="Disenchant") {playCost = 1;}
    else if (name == "Raise Dead") {playCost = 1;}
    else if (name == "Blizzard") {playCost = 3;}
    else if (name == "Steal") {playCost = 2;}
    else if (name == "Switch Hand") {playCost = 1;};
}

void Spell::silence(bool silence){}

void Spell::playCard(std::shared_ptr<Player> target, int index){
    if (name == "Recharge"){
        if (target->getRitual() == nullptr) throw "You do not have a ritual on board";
        target->getIthMinion(6)->editUsage(3);
    } else if (name =="Disenchant"){
        target->getIthMinion(index)->popEnchantment();
    } else if(name == "Unsummon"){
        target->unsummonCard(index);
    } else if (name == "Raise Dead"){
        try {
            target->reviveMinion();
        }
        catch (std::string e) {
            throw e;
        }
    } else if (name == "Blizzard"){
        target->allEditDefence(-2);
        target->getOpponent()->allEditDefence(-2);
    } else if(name == "Banish"){
        target->killMinion(index);
    } else if(name == "Steal"){
        target->stolenMinion(index);
    } else if(name == "Switch Hand"){
        target->switchHand(index);
    }
}

void Spell::addEnchantment(std::shared_ptr<Enchantment> echantment){}

void Spell::popEnchantment(){}

void Spell::clearEnchantment(){}

void Spell::cast(Player& opponent, int index){}

void Spell::inspect(bool graphicsEnabled){}

int Spell::getDefence(){return 0;}

void Spell::editDefence(int defence){}

int Spell::getPlayCost(){return 0;}

void Spell::editPlayCost(int playCost){}

int Spell::getAttack(){return 0;}

void Spell::editAttack(int attack){}

int Spell::getAbilityCost(){return 0;}

void Spell::editAbilityCost(int ac){}

int Spell::getUsage(){return 0;}

void Spell::editUsage(int){}

int Spell::getAction(){return 0;}

void Spell::editAction(int action){}

int Spell::getUsageCap(){
    return 0;
}

bool Spell::died(){return false;}

std::string Spell::getDescription() {
    if (name == "Banish") {return "Distroy target minion or ritual";}
    if (name == "Unsummon") {return "Return target minion to its owner's hand";}
    if (name == "Recharge") {return "Your ritual gains 3 charges";}
    if (name =="Disenchant") {return "Distroy the top enchantment on target minion";}
    if (name == "Raise Dead") {return "Resurrect the top minion in your graveyard and set its defence to 1";}
    if (name == "Blizzard") {return "Deal 2 damages to all minions";}
    if (name == "Steal") {return "Steal an enemy minion and take control of it";}
    if (name == "Switch Hand") {return "I like your hand more. Please give them to me";}
    else return "";
}

void Spell::setAction(int action){
}

void Spell::editActionCap(int action){
}

void Spell::checkTrigger(TriggerType trigger,Player& opponent, int index){}

int Spell::getDefenceCap(){return 0;}

int Spell::getActionCap(){return 0;}
