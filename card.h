#ifndef CARD_H
#define CARD_H
#include "allCard.h"
#include <memory>
#include <string>
#include <vector>

class Card{
    std::string name;
    std::string description;
    int magic;
public:
    Card(std::string name = "", std::string description = "", int magic = 0);
};

#endif
