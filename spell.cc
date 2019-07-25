#include "spell.h"

Spell::Spell():{}

void Spell::playCard();

void Spell::editAttack(int i) {}

void Spell::editHealth(int i) {}

void Spell::addEnchantment(std::unique_ptr<Enchantment> &enchantment) {}

void Spell::cast(std::unique_ptr<Player> &player, int i);

void Spell::inspect();

void Spell::print(bool);

std::string Spell::getDescription() {
    if (name == "Banish") {return "Distroy target minion or ritual";}
    if (name == "Unsummon") {return "Return target minion to its owner's hand";}
    if (name == "Recharge") {return "Your ritual gains 3 charges";}
    if (name =="Disenchant") {return "Distroy the top enchantment on target minion";}
    if (name == "Raise Dead") {return "Resurrect the top minion in your graveyard and set its defence to 1";}
    if (name == "Blizzard") {return "Deal 2 damages to all minions";}
}

int Spell::getHealth() {return 0;}

void Spell::editHealth(int i) {}

int Spell::getMagic() {
    return magic;
}

void Spell::editMagic(int i) {
    magic += i;
}

int Spell::getAttack() {return 0;}

void Spell::editAttack(int i) {}

int Spell::getCost() {return 0;}

void Spell::editCost(int i) {}

int Spell::getUsage() {return 0;}

void Spell::editUsage(int i) {}

Info Spell::getInfo() ;

bool Spell::die();

void Spell::notify();
