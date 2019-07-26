#include "spell.h"

Spell::Spell(std::string name, std::shared_ptr<Player> owner):Card{name,owner}{
    if (name == "Banish") {playCost = 2;}
    else if (name == "Unsummon") {playCost = 1;}
    else if (name == "Recharge") {playCost = 1;}
    else if (name =="Disenchant") {playCost = 1;}
    else if (name == "Raise Dead") {playCost = 1;}
    else if (name == "Blizzard") {playCost = 3;}
}

void Spell::silence(bool silence){}

void Spell::playCard(std::shared_ptr<Player> target, int index){
    if (name == "Recharge"){
        target->getIthMinion(6)->editUsage(3);
    } else if (name =="Disenchant"){
        target->getIthMinion(index)->popEnchantment();
    } else if(name == "Unsummon"){
        target->unsummonCard(index);
    } else if (name == "Raise Dead"){
        target->reviveMinion();
    } else if (name == "Blizzard"){
        target->allEditDefence(-1);
    }
}

void Spell::addEnchantment(std::shared_ptr<Enchantment> echantment){}

void Spell::popEnchantment(){}

void Spell::clearEnchantment(){}

void Spell::cast(std::shared_ptr<Player> opponent, int index){}

void Spell::inspect(bool graphicsEnabled){}

void Spell::print(bool graphicsEnabled){
    
}

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

bool Spell::died(){return false;}

std::string Spell::getDescription() {
    if (name == "Banish") {return "Distroy target minion or ritual";}
    if (name == "Unsummon") {return "Return target minion to its owner's hand";}
    if (name == "Recharge") {return "Your ritual gains 3 charges";}
    if (name =="Disenchant") {return "Distroy the top enchantment on target minion";}
    if (name == "Raise Dead") {return "Resurrect the top minion in your graveyard and set its defence to 1";}
    if (name == "Blizzard") {return "Deal 2 damages to all minions";}
    else return "";
}

void Spell::checkTrigger(TriggerType trigger,std::shared_ptr<Player> opponent, int index){}
