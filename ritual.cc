#include "ritual.h"
Ritual::Ritual(std::string name, std::shared_ptr<Player> owner):Card{name,owner}{
    if(name == "Dark Ritual"){
        playCost = 0;
        usage = 5;
        usageCap = 1;
    } else if(name == "Aura of Power"){
        playCost = 1;
        usage = 4;
        usageCap = 1;
    } else if(name == "Standstill"){
        playCost = 3;
        usage = 4;
        usageCap = 2;
    }
}

void Ritual::silence(bool silence){}

void Ritual::playCard(std::shared_ptr<Card> target){}

void Ritual::playCard(std::shared_ptr<Player> target, int index){}

void Ritual::addEnchantment(std::shared_ptr<Enchantment> echantment){}

void Ritual::popEnchantment(){}

void Ritual::clearEnchantment(){}

void Ritual::cast(std::shared_ptr<Card> target){
    if(name == "Aura of Power"){
        target->editAttack(1);
        target->editDefence(1);
        usage-=usageCap;
    }
}

void Ritual::cast(std::shared_ptr<Player> opponent, int index){
    if(name == "Dark Ritual"){
        opponent->editMagic(1);
        usage-=usageCap;
    } else if(name == "Standstill"){
        opponent->killMinion(index);
        usage-=usageCap;
    }
}

void Ritual::inspect(bool graphicsEnabled){}

void Ritual::print(bool graphicsEnabled){
    
}

int Ritual::getDefence(){}

void Ritual::editDefence(int defence){}

int Ritual::getPlayCost(){
    return playCost;
}

void Ritual::editPlayCost(int playCost){
    this->playCost+=playCost;
}

int Ritual::getAttack(){}

void Ritual::editAttack(int attack){}

int Ritual::getAbilityCost(){}

void Ritual::editAbilityCost(int ac){}

int Ritual::getUsage(){
    return usage;
}

void Ritual::editUsage(int uc){
    usage+=uc;
}

int Ritual::getAction(){}

void Ritual::editAction(int action){}

bool Ritual::died(){}

std::string Ritual::getDescription() {
    if (name == "Dark Ritual") {return "At the start of your turn, gain 1 mana";}
    if (name == "Aura of Power") {return "Whenever a minion enters play under your control, it gains +1/+1";}
    if (name == "Standstill") {return "Whenever a minion enters play, destroy it";}
    
}
