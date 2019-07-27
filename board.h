#ifndef BOARD_H
#define BOARD_H
#include "player.h"
#include <memory>
#include "ascii_graphics.h"
#include "invalidCommandException.h"
#include <iostream>


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
    void endRound();
    void startRound();
    void checkTrigger(TriggerType );
    void printHand();
    ~Board();
};

#endif
