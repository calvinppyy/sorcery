#include "board.h"

Board::Board(std::unique_ptr<Player> player1 = nullptr,std::unique_ptr<Player> player2 , bool testing):
player1{player1}, player2{player2}, testing{testing}{}

void Board::enterTesting(){
    testing = true;
}
