#ifndef __INFO_H__
#define __INFO_H__
#include "board.h"
#include "state.h"

struct Info {
    std::string player;
    std::string name;
    LocationType location;
    int numInLocation;
    CardType cType;
    Info(std::string player, std::string name, LocationType location, int numInLocation, CardType cType);
};

Info::Info(std::string player, std::string name, LocationType location, int numInLocation, CardType cType):
player{player}, name{name}, location{location}, numInLocation{numInLocation}, cType{cType}{}

#endif
