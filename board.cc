#include "board.h"

using namespace std;

Board::Board(shared_ptr<Player> player1, shared_ptr<Player> player2):
player1{player1}, player2{player2}, currentPlayer{player1}, testing{false}, graphics{false} {}

void Board::init(std::string name1, std::string name2)
{
    this->player1->giveName(name1);
    this->player2->giveName(name2);
    this->player1->setOpponent(player2);
    this->player2->setOpponent(player1);
    if (!this->testing)
    {
        this->player1->shuffle();
        this->player2->shuffle();
    }
}

void Board::setCurrentPlayer(shared_ptr<Player> nextPlayer)
{
    this->currentPlayer = nextPlayer;
}

void Board::enterTesting()
{
    testing = true;
}

void Board::enterGraphics()
{
    graphics = true;
}

bool Board::isOver()
{
    return player1->died() || player2->died();
}

shared_ptr<Player> Board::winner()
{   
    if (!this->isOver()) return nullptr;
    if (player1->died()) return this->player2;
    return this->player1;
}

void Board::attack(int myMinion, int enemy)
{
    try
    {
        this->currentPlayer->attack(myMinion, enemy，0);
    }
    catch (const out_of_range &e)
    {
        cerr << "Index exceeds the amount of minions the active player holds" << endl;
    }
}

void Board::attack(int myMinion)
{
    try
    {
        this->currentPlayer->attack(myMinion);
    }
    catch (const out_of_range &e)
    {
        cerr << "Index exceeds the amount of cards the active player holds" << endl;
    }
}

void Board::play(int cardIndex)
{
    try
    {
        this->currentPlayer->playCard(cardIndex, this->testing);
    }
    catch (const out_of_range &e)
    {
        cerr << "Index exceeds the amount of cards the active player holds" << endl;
    }
}

void Board::play(int cardIndex, shared_ptr<Player> targetPlayer, int targetCard)
{
    try
    {
        this->currentPlayer->playCard(cardIndex, targetPlayer, targetCard, this->testing);
    }
    catch (const out_of_range &e)
    {
        cerr << "Index exceeds the amount of cards the active player holds" << endl;
    }
}

void Board::useAbility(int cardIndex)
{
    try
    {
        this->currentPlayer->useAbility(cardIndex, this->testing);
    }
    catch (const out_of_range &e)
    {
        cerr << "Index exceeds the amount of cards the active player holds" << endl;
    }
}

void Board::useAbility(int cardIndex, shared_ptr<Player> targetPlayer, int targetCard)
{
    try
    {
        this->currentPlayer->useAbility(cardIndex, targetPlayer, targetCard, this->testing);
    }
    catch (const out_of_range &e)
    {
        cerr << "Index exceeds the amount of cards the active player holds" << endl;
    }
}

void Board::draw()
{
    if (this->testing)
    {
        this->currentPlayer->draw();
        return;
    }
    throw InvalidCommandException("draw");
}

void Board::discard(int cardIndex)
{
    if (this->testing)
    {
        try
        {
            this->currentPlayer->discard(cardIndex);
        }
        catch (const out_of_range &e)
        {
            cerr << "Index exceeds the amount of cards the active player holds" << endl;
        }
        return;
    }
    throw InvalidCommandException("discard");
}

void Board::inspect(int cardIndex)
{
    try
    {
        this->currentPlayer->inspect(cardIndex);
    }
    catch (const out_of_range &e)
    {
        cerr << "Index exceeds the amount of minions the active player holds" << endl;
    }
}

Board::~Board() {}
