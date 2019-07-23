#include "deck.h"

Deck::Deck(int limit): deck{nullptr}, limit{limit}{}

void Deck::pushCard(std::unique_ptr<Card> card){
    deck.emplace_back(*card);
}

std::unique_ptr<Card> Deck::getCard(){
    std::unique_ptr<Card> temp = std::make_unique<Card>(deck.back());
    deck.pop_back();
    return temp;
}

 void Deck::Empty(){
     if(deck.empty()) return;
     deck.clear();
}
