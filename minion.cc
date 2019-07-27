#include "minion.h"

Minion::Minion(std::string name, std::shared_ptr<Player> owner):Card{name,owner}{
    if(name == "Air Elemental"){
        attack = 1;
        defence = 1;
        playCost = 0;
        abilityCost = 0;
        action = 0;
        actionCap = 1;
        defenceCap = 1;
        silenced = false;
    } else if(name == "Earth Elemental"){
        attack = 4;
        defence = 4;
        playCost = 3;
        abilityCost = 0;
        action = 0;
        actionCap = 1;
        defenceCap = 4;
        silenced = false;
    } else if(name == "Bone Golem"){
        triggerType = TriggerType::minionLeave;
        attack = 1;
        defence = 3;
        playCost = 2;
        abilityCost = 0;
        action = 0;
        actionCap = 1;
        defenceCap = 3;
        silenced = false;
    } else if(name == "Fire Elemental"){
        triggerType = TriggerType::minionEnter;
        attack = 2;
        defence = 2;
        playCost = 2;
        abilityCost = 0;
        action = 0;
        actionCap = 1;
        defenceCap = 2;
        silenced = false;
    } else if(name == "Potion Seller"){
        triggerType = TriggerType::endOfTurn;
        attack = 1;
        defence = 3;
        playCost = 2;
        abilityCost = 0;
        action = 0;
        actionCap = 1;
        defenceCap = 3;
        silenced = false;
    } else if(name == "Novice Pyromancer"){
        attack = 0;
        defence = 1;
        playCost = 1;
        abilityCost = 1;
        action = 0;
        actionCap = 1;
        defenceCap = 1;
        silenced = false;
    } else if(name == "Apprentice Summoner"){
        attack = 1;
        defence = 1;
        playCost = 1;
        abilityCost = 1;
        action = 0;
        actionCap = 1;
        defenceCap = 1;
        silenced = false;
    } else if(name == "Master Summoner"){
        attack = 2;
        defence = 3;
        playCost = 3;
        abilityCost = 2;
        action = 0;
        actionCap = 1;
        defenceCap = 3;
        silenced = false;
    }
}

void Minion::playCard(std::shared_ptr<Player> target, int index){}

void Minion::addEnchantment(std::shared_ptr<Enchantment> enchantment){
    enchantments.emplace_back(enchantment);
}
     
void Minion::popEnchantment(){
    enchantments.pop_back();
}

void Minion::clearEnchantment(){
    enchantments.clear();
}

void Minion::silence(bool silenced){
    this->silenced = silenced;
}

void Minion::cast(std::shared_ptr<Player> opponent, int index){
    if(name == "Novice Pyromancer"){
        opponent->takeAttack(1,1, index, 1);
    } else if(name == "Apprentice Summoner"){
        if (opponent->countMinions() == 5) throw "no minion spot"; // when there are already 5 minions
        opponent->summonCard(1, "Air Elemental");
    } else if(name == "Master Summoner"){
        if (opponent->countMinions() == 5) throw "no minion spot"; //when there are already 5 minions
        opponent->summonCard(3, "Air Elemental");
    }
}
     
void Minion::inspect(bool graphicsEnabled){
    if(!graphicsEnabled){
        
    }
}
     
int Minion::getDefence(){
    int defence = this->defence;
    for(int i = 0; i<enchantments.size(); i++){
        defence += enchantments.at(i)->getDefence();
    }
    return defence;
}
     
void Minion::editDefence(int damage){
    int temp = damage;
    for(int i = enchantments.size()-1; i>=0; i--){
        if(temp == 0) break;
        if(temp>=enchantments.at(i)->getDefence()){
            temp += enchantments.at(i)->getDefence();
            enchantments.at(i)->editDefence(-1*enchantments.at(i)->getDefence());
        } else {
            enchantments.at(i)->editDefence(temp);
            temp = 0;
        }
    }
    if(temp!=0){
        defence+=temp;
    }
}
     
int Minion::getPlayCost(){
    return playCost;
}
     
void Minion::editPlayCost(int playCost){
    this->playCost+=playCost;
}
     
int Minion::getAttack(){
    int attack = this->attack;
    for(int i = 0; i<enchantments.size(); i++){
        attack += enchantments.at(i)->getAttack();
    }
    return attack;
}
     
void Minion::editAttack(int attack){
    this->attack += attack;
}
     
int Minion::getAbilityCost(){
    int abilityCost = this->abilityCost;
    for(int i = 0; i<enchantments.size(); i++){
        abilityCost += enchantments.at(i)->getAbilityCost();
    }
    return abilityCost;
}
     
void Minion::editAbilityCost(int ac){
    this->abilityCost += ac;
}
     
int Minion::getUsage(){
    return 0;
}

void Minion::editUsage(int){}

int Minion::getAction(){
    int action = this->action;
    for(int i = 0; i<enchantments.size(); i++){
        action += enchantments.at(i)->getAction();
    }
    return action;
}

void Minion::editAction(int action){
    this->action += action;
}

bool Minion::died(){
    return defence<=0;
}

int Minion::getUsageCap(){
    return 0;
}

std::string Minion::getDescription(){
    if(name == "Bone Golem") return "Gain +1/+1 whenever a minion leaves play.";
    if(name == "Fire Elemental") return "Whenever an opponent's minion enters play, deal 1 damage to it.";
    if(name == "Potion Seller") return "At the end of your turn, all your minions gain +0/+1.";
    if(name == "Novice Pyromancer") return "Deal 1 damage to target minion";
    if(name == "Apprentice Summoner") return "Summon a 1/1 air elemental";
    if(name == "Master Summoner") return "Summon up to three 1/1 air elementals";
    else return "";
}

void Minion::checkTrigger(TriggerType trigger, std::shared_ptr<Player> opponent, int index){
    if(trigger == triggerType){
        cast(opponent,index);
    }
}

int Minion::getDefenceCap(){
    return defenceCap;
}
