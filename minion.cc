#include "minion.h"

void Minion::playCard(std::unique_ptr<Player> &player){
    setState({StateType::PlayCard, LocationType::Hand, 1, CardType::Minion});
    this->notifyObservers();
}

void Minion::editAttack(int i){
    attack+=i;
}

void Minion::editHealth(int i){
    health+=i;
}



void Minion::cast(std::unique_ptr<Player> &player, std::unique_ptr<Card> &card){
    if(name == "Novice Pyromancer"){
        card->editHealth(-1);
    }
    if(name == "Apprentice Summoner"){
        
    }
    if(name == "Master Summoner"){
        
    }
}

void Minion::startCast(std::unique_ptr<Player> &player, std::unique_ptr<Card> &card){
    
}

void Minion::endCast(std::unique_ptr<Player> &player, std::unique_ptr<Card> &card){
    if(name == "Potion Seller"){
        
    }
}

void Minion::addEnchantment(std::unique_ptr<Enchantment> &enchantment){
    enchantments.emplace_back(enchantment);
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
    
}

void Minion::editHealth(int){
    
}

int Minion::getMagic(){
    
}

void Minion::editMagic(int){
    
}

int Minion::getAttack(){
    
}

void Minion::editAttack(int){
    
}

int Minion::getCost(){
    
}

void Minion::editCost(int){
    
}

int Minion::getUsage(){
    
}

void Minion::editUsage(int){
    
}

Info Minion::getInfo(){
    
}

void Minion::notify(){
    
}
