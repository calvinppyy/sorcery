#include "minion.h"

void Minion::playCard(std::unique_ptr<Player> &player){
    setState({StateType::PlayCard, LocationType::Hand, 1, CardType::Minion});
    player
    this->notifyObservers();
}

void Minion::editAttack(int){
    
}

void Minion::editHealth(int){

}

void Minion::addEnchantment(&std::unique_ptr<Enchantment>){
    
}

void Minion::cast(&std::unique_ptr<Player>, &std::unique_ptr<Card>){

}

void Minion::addEnchantment(&std::unique_ptr<Enchantment>){
    
}

void Minion::inspect(){
    
}

void Minion::print(boolean){
    
}

std::string Minion::getDescription(){
    
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
