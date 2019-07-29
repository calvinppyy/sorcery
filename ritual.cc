#include "ritual.h"
Ritual::Ritual(std::string name, std::shared_ptr<Player> owner):Card{name,owner}{
    if(name == "Dark Ritual"){
        playCost = 0;
        usage = 5;
        usageCap = 1;
        triggerType = TriggerType::startOfTurn;
    } else if(name == "Aura of Power"){
        playCost = 1;
        usage = 4;
        usageCap = 1;
        triggerType = TriggerType::allyEnter;
    } else if(name == "Standstill"){
        playCost = 3;
        usage = 4;
        usageCap = 2;
        triggerType = TriggerType::noTrigger;
    }
}

void Ritual::silence(bool silence){}

void Ritual::playCard(std::shared_ptr<Player> target, int index){}

void Ritual::addEnchantment(std::shared_ptr<Enchantment> echantment){}

void Ritual::popEnchantment(){}

void Ritual::clearEnchantment(){}

void Ritual::cast(Player& opponent, int index){
    if(name == "Aura of Power"){
        opponent.getIthMinion(index)->editAttack(1);
        opponent.getIthMinion(index)->editDefence(1);
        usage-=usageCap;
    } else if(name == "Dark Ritual"){
        opponent.editMagic(1);
        usage-=usageCap;
    } else if(name == "Standstill"){
        opponent.killMinion(index);
        usage-=usageCap;
    }
}

void Ritual::inspect(bool graphicsEnabled){}

int Ritual::getDefence(){return 0;}

void Ritual::editDefence(int defence){}

int Ritual::getPlayCost(){
    return playCost;
}

void Ritual::editPlayCost(int playCost){
    this->playCost+=playCost;
}

int Ritual::getAttack(){return 0;}

void Ritual::editAttack(int attack){}

int Ritual::getAbilityCost(){return 0;}

void Ritual::editAbilityCost(int ac){}

int Ritual::getUsage(){
    return usage;
}

int Ritual::getUsageCap(){
    return usageCap;
}

void Ritual::editUsage(int uc){
    usage+=uc;
}

int Ritual::getAction(){return 0;}

void Ritual::editAction(int action){}

bool Ritual::died(){return false;}

std::string Ritual::getDescription() {
    if (name == "Dark Ritual") {return "At the start of your turn, gain 1 mana";}
    if (name == "Aura of Power") {return "Whenever a minion enters play under your control, it gains +1/+1";}
    if (name == "Standstill") {return "Whenever a minion enters play, destroy it";}
    else return "";
}

void Ritual::checkTrigger(TriggerType trigger, Player& opponent, int index){
    if (usage == 0) {
        std::string e = "The ritual has used up its usage";
        throw e;
    }
    if(name == "Standstill" && (trigger == TriggerType::allyEnter || trigger == TriggerType::enemyEnter)){
        cast(opponent,index);
    }
    if(trigger == triggerType){
        cast(opponent,index);
    }
}

void Ritual::setAction(int action){
}

void Ritual::editActionCap(int action){
}

int Ritual::getDefenceCap(){
    return 0;
}

int Ritual::getActionCap(){
    return 0;
}
