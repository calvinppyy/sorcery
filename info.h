#ifndef __INFO_H__
#define __INFO_H__
#include "board.h"
#include "state.h"

struct Info {
    Player player;
    std::string name;
    LocationType location;
    CardType cType;
};

#endif
