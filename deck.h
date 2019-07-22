#ifndef deck_h
#define deck_h
#include "card.h"

class Deck{
    std::vector<std::unique_ptr<Card>> deck;
};

#endif
