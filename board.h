#ifndef BOARD_H
#define BOARD_H
#include "player.h"
#include <memory>
#include "ascii_graphics.h"
#include "invalidCommandException.h"


class Board: public Observer<Info, State>{
    int round;
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;
    std::unique_ptr<Player> &currentPlayer;
    bool testing;
    bool graphics;
public:
    Board(std::unique_ptr<Player> player1 = nullptr, std::unique_ptr<Player> player2 = nullptr);
    void init(std::string, std::string);
    int getRound();
    void setCurrentPlayer(std::unique_ptr<Player>);
    bool isOver();
    std::string winner();
    void enterTesting();
    void enterGraphics();
    void attack(int, int);
    void attack(int);
    void play(int);
    void play(int, unique_ptr<Player>, int);
    void useAbility(int);
    void useAbility(int, unique_ptr<Player>, int);
    void draw();
    void discard(int);
    void inspect(int);
    ~Board();
};

#endif
