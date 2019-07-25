#include "spell.h"

void Spell::playCard();
void Spell::editAttack(int i) {}
void Spell::editHealth(int i) {}
void Spell::addEnchantment(std::unique_ptr<Enchantment> &enchantment) {}
void Spell::startCast(std::unique_ptr<Player> &player, std::unique_ptr<Card> &card);
void Spell::endCast(std::unique_ptr<Player> &player, std::unique_ptr<Card> &card);
void Spell::cast(std::unique_ptr<Player> &player, std::unique_ptr<Card> &card);
void Spell::removeEnchantment(std::unique_ptr<Enchantment> &enchantment) {}
void Spell::inspect();
void Spell::print(bool);

std::string Spell::getDescription() {
    if (name = "Banish") {return "Distroy target minion or ritual"};
    if (name = "Unsummon") {return "Return target minion to its owner's hand"};
    if (name = "Recharge") {return "Your ritual gains 3 charges"};
    if (name = "Disenchant") {return "Distroy the top enchantment on target minion"};
    if (name = "Raise Dead") {return "Resurrect the top minion in your graveyard and set its defence to 1"};
    if (name = "Blizzard") {return "Deal 2 damages to all minions"};
}

int Spell::getHealth() {}
void Spell::editHealth(int i) {}
int Spell::getMagic() {
    return magic;
}

void Spell::editMagic(int i) {
    magic += i;
}

int Spell::getAttack() {}
void Spell::editAttack(int i) {}
int Spell::getCost();
void Spell::editCost(int i);
int Spell::getUsage();
void Spell::editUsage(int i);
Info Spell::getInfo() ;
void Spell::notify();
