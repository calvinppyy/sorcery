#include "enchantment.h"

Enchantment::Enchantment():{}

void Enchantment::playCard() ;

void Enchantment::editAttack(int i) {}

void Enchantment::editHealth(int i) {}

void Enchantment::addEnchantment(std::unique_ptr<Enchantment> &enchantment) {}

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

int Enchantment::getHealth() {return 0;}

void Enchantment::editHealth(int i) {}

int Enchantment::getMagic() {
    return magic;
}

void Enchantment::editMagic(int i) {
    magic += i
}

int Enchantment::getAttack() {return 0;}

void Enchantment::editAttack(int i) {}

int Enchantment::getCost() {return 0;}

void Enchantment::editCost(int i) {}

int Enchantment::getUsage() {return 0;}

void Enchantment::editUsage(int i) {}

Info Enchantment::getInfo() ;

bool Enchantment::died() ;

void Enchantment::notify();
