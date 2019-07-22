#ifndef BOARD_H
#define BOARD_H
#include "player.h"

class Board{
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;
public:
    Board(std::unique_ptr<Player> player1 = nullptr, std::unique_ptr<Player> player2 = nullptr);
};

#endif
