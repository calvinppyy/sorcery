#include "board.h"

Board::Board(std::unique_ptr<Player> player1 = nullptr,std::unique_ptr<Player> player2 ):
player1{player1}, player2{player2}, testing{testing}{}

void Board::enterTesting(){
    testing = true;
}

void Board::enterGraphocs(){
    graphics = true;
}

void Board::setOb(std::unique_ptr<Observer<Info, State>> ob = nullptr){
    this->ob = std::move(ob);
}

bool Board::isOver(){
    return player1->died()||player2->died();
}

std::string Board::winner(){
    if (player1->died()) return player2->name;
    return player1->name;
}

Board::~Board(){}
