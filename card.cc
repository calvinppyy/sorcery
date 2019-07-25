#include "card.h"

Card::Card(std::string name, std::string description, int magic) : name{name}, description{description}, magic{magic} {}

//methods as subject
void setState(State newState) {
    this->state = newState;
} 

void attach(std::unique_ptr<Card> newOb) {
    this->observers.emplace_back(newOb);
}

void notifyObservers() {
    for (auto &ob : observers) ob->notify(*this);
}

State getState() const {
    return this->state;
}

//method as observer
void notify(Card & whoFrom) {
    
}
