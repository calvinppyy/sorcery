#ifndef BOARD_H
#define BOARD_H
#include <memory>
#include <iostream>
#include "player.h"
#include "ascii_graphics.h"
#include "invalidCommandException.h"

class Board {
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    std::shared_ptr<Player> currentPlayer;
    bool testing;
    bool graphics;
public:
    Board(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2);
    void init(std::string, std::string);
    void setCurrentPlayer(std::shared_ptr<Player>);
    void switchCurrentPlayer();
    bool isOver();
    std::shared_ptr<Player> winner();
    void enterTesting();
    void enterGraphics();
    void attack(int, int);
    void attack(int);
    void play(int);
    void play(int, std::shared_ptr<Player>, int);
    void useAbility(int);
    void useAbility(int, std::shared_ptr<Player>, int);
    void draw();
    void discard(int);
    void inspect(int);
    void print();
    void checkTrigger(TriggerType );
    void printHand();
    bool isGraphics();
    void printGraphics(Xwindow &window);
    ~Board();
};

#endif
