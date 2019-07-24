#include "board.h"

using namespace std;

Board::Board(unique_ptr<Player> player1, unique_ptr<Player> player2) : round{0}, player1{player1}, player2{player2}, currentPlayer{player1}, testing{false} {}

int Board::getRound()
{
    return this->round;
}

unique_ptr<Player> Board::getPlayer1()
{
    return this->player1;
}

unique_ptr<Player> Board::getPlayer2()
{
    return this->player2;
}

unique_ptr<Player> Board::getCurrentPlayer()
{
    return this->currentPlayer;
}

void Board::setCurrentPlayer(unique_ptr<Player> nextPlayer)
{
    this->currentPlayer = nextPlayer;
}

bool Board::getTestingStatus()
{
    return this->testing;
}

bool Board::getGraphicsStatus()
{
    return this->graphics;
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

unique_ptr<Player> Board::winner()
{
    if (player1->died())
        return this->player2;
    return this->player1;
}

void Board::attack(int myMinion, int enemy)
{
    try
    {
    }
    catch (const out_of_range &e)
    {
        cerr << "Index exceeds the amount of cards the active player holds" << endl;
    }
    this->currentPlayer->attack(myMinion, enemy);
}

void Board::attack(int myMinion)
{
    try
    {
    }
    catch (const out_of_range &e)
    {
        cerr << "Index exceeds the amount of cards the active player holds" << endl;
    }
    this->currentPlayer->attack(myMinion);
}

void Board::play(int cardIndex)
{
    try
    {
    }
    catch (const out_of_range &e)
    {
        cerr << "Index exceeds the amount of cards the active player holds" << endl;
    }
    this->currentPlayer->play(cardIndex);
}

void Board::play(int cardIndex, unique_ptr<Player> targetPlayer, int targetCard)
{
    try
    {
    }
    catch (const out_of_range &e)
    {
        cerr << "Index exceeds the amount of cards the active player holds" << endl;
    }
    this->currentPlayer->Play(cardIndex, targetPlayer, targetCard);
}

void Board::useAbility(int cardIndex)
{
    try
    {this->currentPlayer->useAbility(cardIndex);
    }
    catch (const out_of_range &e)
    {
        cerr << "Index exceeds the amount of cards the active player holds" << endl;
    }    
}

void Board::useAbility(int cardIndex, unique_ptr<Player> targetPlayer, int targetCard)
{
    try
    {
        this->currentPlayer->useAbility(cardIndex, targetPlayer, targetCard);
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

void Board::inspect(int)
{
}

Board::~Board() {}
