#include "board.h"

Board::Board(std::unique_ptr<Player> player1, std::unique_ptr<Player> player2): player1{player1}, player2{player2}{}
