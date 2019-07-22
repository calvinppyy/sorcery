#ifndef card_h
#define card_h
#include "allCard.h"
#include <memory>
#include <string>
#include <vector>

class Card{
    std::string name;
    std::string description;
    int magic;
public:
    Card(std::string name, std::string description, int magic);
};

#endif
