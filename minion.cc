#include "minion.h"

Minion::Minion(std::string name, std::string owner, LocationType location,
               int numInLocation, int attack, int health, int magic, int cost):
name{name}, owner{owner}, locaton{location}, numInLocation{numInLocation},
attack{attack}, health{health}, magic{magic}, cost{cost}, action{0}, actionLimit{1},
silenced{false}, enchantments{std::vector<Enchantment>}{}

void Minion::playCard(){
    setState({StateType::PlayCard, LocationType::Hand, 1, CardType::Minion});
    notifyObservers();
}

void Minion::editAttack(int i){
    attack+=i;
}

void Minion::editHealth(int i){
    health+=i;
}



void Minion::cast(std::unique_ptr<Player> &player, std::unique_ptr<Card> &card){
    if(action == actionLimit) return;
    if(name == "Novice Pyromancer"){
        card->editHealth(-1);
        action++;
    }
    if(name == "Apprentice Summoner"){
        action++;
    }
    if(name == "Master Summoner"){
        action++;
    }
}

void Minion::startCast(std::unique_ptr<Player> &player, std::unique_ptr<Card> &card){
    if(action == actionLimit) return;
    
}

void Minion::endCast(std::unique_ptr<Player> &player, std::unique_ptr<Card> &card){
    if(action == actionLimit) return;
    if(name == "Potion Seller"){
        action++;
    }
}

void Minion::addEnchantment(std::unique_ptr<Enchantment> &enchantment){
    enchantments.emplace_back(enchantment);
    if(enchantment->name == "Giant Strength"){
        editHealth(2);
        editAttack(2);
    }
    if(enchantment->name == "Enrage"){
        int health = getHealth();
        int attack = getAttack();
        editHealth(health);
        editAttack(attack);
    }
    if(enchantment->name == "Haste"){
        actionLimit++;
    }
    if(enchantment->name == "Magic Fatigue"){
        cost+=2;
    }
    if(enchantment->name == "Silence"){
        silenced = true;
    }
}

void Minion::inspect(){
    
}

void Minion::print(boolean){
    
}

std::string Minion::getDescription(){
    if(name == "Bone Golem") return "Gain +1/+1 whenever a minion leaves play.";
    if(name == "Fire Elemental") return "Whenever an opponent's minion enters play, deal 1 damage to it.";
    if(name == "Potion Seller") return "At the end of your turn, all your minions gain +0/+1.";
    if(name == "Novice Pyromancer") return "Deal 1 damage to target minion";
    if(name == "Apprentice Summoner") return "Summon a 1/1 air elemental";
    if(name == "Master Summoner") return "Summon up to three 1/1 air elementals";
}

int Minion::getHealth(){
    return health;
}

void Minion::editHealth(int i){
    health+=i;
}

int Minion::getMagic(){
    return magic;
}

void Minion::editMagic(int i){
    magic+=i;
}

int Minion::getAttack(){
    return attack;
}

void Minion::editAttack(int i){
    attack+=i;
}

int Minion::getCost(){
    return cost;
}

void Minion::editCost(int i){
    cost+=i;
}

Info Minion::getInfo(){
    return {owner, name, location, numInLocation, CardType::Minion};
}

void Minion::notify(std::unique_ptr<Card> &whoFrom){
    
}
