#include "card.h"

Card::Card(std::string name, std::string description, int magic) : name{name}, description{description}, magic{magic} {}

//methods as subject
void Card::setState(State newState) {
    this->state = newState;
} 

void Card::attach(std::unique_ptr<Card> newOb) {
    this->observers.emplace_back(newOb);
}

void Card::notifyObservers() {
    for (auto &ob : observers) ob->notify(*this);
}

State Card::getState() const {
    return this->state;
}

//method as observer, need to be moved to subclasses, specific case
void Card::notify(Card & whoFrom) {
    State subjectState = whoFrom.getState();
    if (subjectState.type == StateType::PlayCard && this->triggerType == TriggerType::minionEnter) {
        this->cast(nullptr, 0);
        return;
    } else if ((subjectState.type == StateType::Dying || subjectState.type == StateType::Dying) &&
    this->triggerType == TriggerType::minionLeave) {
        this->cast(nullptr, 0);
        return;
    } else if (subjectState.type == StateType::Attack) {
        if (subjectState.location == this->getInfo().location && subjectState.numInLocation == this->indexInLocation) {
            whoFrom.editHealth(-1*this->getAttack());
            this->editHealth(-1*whoFrom.getAttack());
            if(this->died()) {
                State newState = {false, StateType::Dying, LocationType::Graveyard, this->owner->graveyard.size()};
                this->setState(newState);
                this->notifyObservers();
                this->owner->killMinion(this->indexInLocation);
                this->owner->adjustMinionIndex();
            } 
        }
    }
}
