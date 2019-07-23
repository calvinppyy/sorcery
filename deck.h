#ifndef DECK_H
#define DECK_H
#include "card.h"

class Deck{
    std::vector<std::unique_ptr<Card>> deck;
    int limit;
public:
    Deck(int limit = -1);
    void pushCard(std::unique_ptr<Card> card);
    std::unique_ptr<Card> getCard();
    void Empty();
};

#endif
