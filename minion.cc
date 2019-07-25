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
    if(name == "Bone Golem"){
        
    }
}

void Minion::startCast(std::unique_ptr<Player> &player, std::unique_ptr<Card> &card){
    
}

void Minion::endCast(std::unique_ptr<Player> &player, std::unique_ptr<Card> &card){
    
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

void Minion::notify(){
    
}
