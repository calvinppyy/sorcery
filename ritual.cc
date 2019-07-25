#include "ritual.h"

void Ritual::playCard() ;
void Ritual::editAttack(int i) {}
void Ritual::editHealth(int i) {}
void Ritual::addEnchantment(std::unique_ptr<Enchantment> &enchantment) ;
void Ritual::cast(std::unique_ptr<Player> &player, int i) ;
void Ritual::inspect() ;
void Ritual::print(bool);
std::string Ritual::getDescription() {
    if (name == "Dark Ritual") {return "At the start of your turn, gain 1 mana"};
    if (name == "Aura of Power") {return "Whenever a minion enters play under your control, it gains +1/+1"};
    if (name == "Standstill") {return "Whenever a minion enters play, destroy it"};
    
}

int Ritual::getHealth() ;
void Ritual::editHealth(int i) ;
int Ritual::getMagic() {
    return magic;
}

void Ritual::editMagic(int i) {
    magic += i
}

int Ritual::getAttack() ;
void Ritual::editAttack(int i) ;
int Ritual::getCost() {
    return cost;
}

void Ritual::editCost(int i) {
    cost += i;
}

int Ritual::getUsage() {
    return usage;
}

void Ritual::editUsage(int i) {
    usage += i;
}

Info Ritual::getInfo() ;
bool Ritual::died() ;
