#include "card.h"

Card::Card(std::string name, std::shared_ptr<Player> owner) : name{name}, triggerType{TriggerType::noTrigger}, owner{owner} {}

std::string Card::getName(){
    return name;
}
