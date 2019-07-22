#ifndef board_hpp
#define board_hpp
#include "player.h"

class Board{
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;
public:
    Board(std::unique_ptr<Player> player1, std::unique_ptr<Player> player2);
};

#endif
