#include "enchantment.h"

void Enchantment::playCard() ;
void Enchantment::editAttack(int i) {}
void Enchantment::editHealth(int i) {}
void Enchantment::addEnchantment(std::unique_ptr<Enchantment> &enchantment) ;
void Enchantment::cast(std::unique_ptr<Player> &player, int i) ;
void Enchantment::inspect() ;
void Enchantment::print(bool) ;
std::string Enchantment::getDescription() {
    if (name == "Giant Strength") {return ""};
    if (name == "Enrage") {return ""};
    if (name == "Haste ") {return "Enchanted minion gains +1 action each turn"};
    if (name == "Magic Fatigue") {return "Enchanted minion's activated ability costs 2 more"};
    if (name == "Silence") {return "Enchanted minion cannot use abilities"};
}

int Enchantment::getHealth() ;
void Enchantment::editHealth(int i) ;
int Enchantment::getMagic() {
    return magic;
}

void Enchantment::editMagic(int i) {
    magic += i
}

int Enchantment::getAttack() ;
void Enchantment::editAttack(int i) ;
int Enchantment::getCost() ;
void Enchantment::editCost(int i) ;
int Enchantment::getUsage() ;
void Enchantment::editUsage(int i) ;
Info Enchantment::getInfo() ;
bool Enchantment::died() ;
