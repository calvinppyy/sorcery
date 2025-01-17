#include "enchantment.h"

Enchantment::Enchantment(std::string name) :Card{ name} {
	if (name == "Giant Strength") {
		attack = 2;
		defense = 2;
		abilityCost = 0;
		silenced = false;
		action = 0;
		playCost = 1;
		target = nullptr;
	}
	else if (name == "Enrage") {
		attack = 0;
		defense = 0;
		abilityCost = 0;
		silenced = false;
		action = 0;
		playCost = 2;
		target = nullptr;
	}
	else if (name == "Haste") {
		attack = 0;
		defense = 0;
		abilityCost = 0;
		silenced = false;
		action = 1;
		playCost = 1;
		target = nullptr;
	}
	else if (name == "Magic Fatigue") {
		attack = 0;
		defense = 0;
		abilityCost = 2;
		silenced = false;
		action = 0;
		playCost = 0;
		target = nullptr;
	}
	else if (name == "Silence") {
		attack = 0;
		defense = 0;
		abilityCost = 0;
		silenced = true;
		action = 0;
		playCost = 1;
		target = nullptr;
	}
}

void Enchantment::silence(bool silenced) {
	this->silenced = silenced;
}

void Enchantment::playCard(std::shared_ptr<Player> target, int index) {
	if (name == "Enrage") {
		attack = target->getIthMinion(index)->getAttack();
		defense = target->getIthMinion(index)->getDefence();
	}
	else if (name == "Silence") {
		target->getIthMinion(index)->silence(true);
	} else if (name == "Magic Fatigue" &&
               (target->getIthMinion(index)->getName() == "Air Elemental" ||
                target->getIthMinion(index)->getName() == "Earth Elemental")){
		throw "You do not have a ritual on board to apply Recharge";
    } else if(name == "Haste"){
        target->getIthMinion(index)->editActionCap(1);
    }
	target->getIthMinion(index)->addEnchantment(std::make_shared<Enchantment>(*this));
	this->target = target->getIthMinion(index);
}


void Enchantment::addEnchantment(std::shared_ptr<Enchantment> echantment) {}

void Enchantment::popEnchantment() {}

void Enchantment::clearEnchantment() {}

void Enchantment::cast(Player& opponent, int index) {}

void Enchantment::inspect(bool graphicsEnabled) {}

int Enchantment::getDefence() {
	return defense;
}

void Enchantment::editDefence(int defence) {
	this->defense += defence;
}

int Enchantment::getPlayCost() {
	return playCost;
}

void Enchantment::editPlayCost(int playCost) {
	this->playCost += playCost;
}

int Enchantment::getAttack() {
	return attack;
}

void Enchantment::editAttack(int attack) {
	this->attack += attack;
}

int Enchantment::getAbilityCost() {
	return abilityCost;
}

void Enchantment::editAbilityCost(int ac) {
	this->abilityCost += ac;
}

int Enchantment::getUsage() { return 0; }

void Enchantment::editUsage(int) {}

int Enchantment::getAction() {
	return action;
}

int Enchantment::getUsageCap() {
	return 0;
}

void Enchantment::editAction(int action) {
	this->action += action;
}

bool Enchantment::died() { return false; }

std::string Enchantment::getDescription() {
	if (name == "Giant Strength") { return ""; }
	if (name == "Enrage") { return ""; }
	if (name == "Haste") { return "Enchanted minion gains +1 action each turn"; }
	if (name == "Magic Fatigue") { return "Enchanted minion's activated ability costs 2 more"; }
	if (name == "Silence") { return "Enchanted minion cannot use abilities"; }
	return "";
}

void Enchantment::setAction(int action){
}

void Enchantment::editActionCap(int action){
}

void Enchantment::checkTrigger(TriggerType trigger, Player& opponent, int index) {}

int Enchantment::getDefenceCap() {
	return 0;
}

int Enchantment::getActionCap(){
    return 0;
}
