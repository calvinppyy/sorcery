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

//method as observer
void Card::notify(Card & whoFrom) {
    State = whoFrom.getState();
    if (state.type == StateType::PlayCard) {
        if (this->triggerType == TriggerType::minionEnter) this->cast()
    }
}
