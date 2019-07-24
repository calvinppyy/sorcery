#ifndef BOARD_H
#define BOARD_H
#include "player.h"

class Board: public Observer<Info, State>{
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;
    bool testing;
    bool graphics;
    std::unique_ptr<Observer<Info, State>> ob;
public:
    Board(std::unique_ptr<Player> player1 = nullptr, std::unique_ptr<Player> player2 = nullptr);
    bool isOver();
    std::string winner();
    void enterTesting();
    void enterGraphocs();
    void setOb(std::unique_ptr<Observer<Info, State>> ob);
    ~Board();
};

#endif
