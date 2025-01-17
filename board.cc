#include "board.h"

using namespace std;

Board::Board(shared_ptr<Player> player1, shared_ptr<Player> player2) : player1{player1}, player2{player2}, currentPlayer{player1}, testing{false}, graphics{false} {}

void Board::init(std::string name1, std::string name2)
{
    this->player1->giveName(name1);
    this->player2->giveName(name2);
    this->player1->setOpponent(player2);
    this->player2->setOpponent(player1);
    if (!this->testing)
    {
        this->player1->shuffleDeck();
        this->player2->shuffleDeck();
    }
}

void Board::setCurrentPlayer(shared_ptr<Player> nextPlayer)
{
    this->currentPlayer = nextPlayer;
}

void Board::switchCurrentPlayer()
{
    currentPlayer = currentPlayer->getOpponent();
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
    if (!this->isOver())
        return nullptr;
    if (player1->died())
        return this->player2;
    return this->player1;
}

void Board::attack(int myMinion, int enemy)
{
    try
    {
        int damage = this->currentPlayer->getIthMinion(myMinion)->getAttack();
        this->currentPlayer->attack(myMinion, damage, enemy, 0);
    }
    catch (const out_of_range &e)
    {
        cerr << "Index exceeds the amount of minions the active player holds4" << endl;
    }
    catch(char e){
        cerr << "This Minion can not attack/use ability anymore this round" << endl;
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
        cerr << "Index exceeds the amount of cards the active player holds5" << endl;
    }
    catch(string e){
        cerr << e << endl;
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
        cerr << "Index exceeds the amount of cards the active player holds6" << endl;
    }
    catch (int e)
    {
        if(e == 1) cerr << "Not Enough Magic!" << endl;
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
        cerr << "Index exceeds the amount of cards the active player holds7" << endl;
    }
    catch (char e)
    {
        cerr << "Not Enough Magic!" << endl;
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
        cerr << "Index exceeds the amount of cards the active player holds8" << endl;
    }
    catch (char a)
    {
        cerr << "Not enough magic!" << endl;
    }
}

void Board::useAbility(int cardIndex, shared_ptr<Player> targetPlayer, int targetCard)
{
    try
    {
        this->currentPlayer->useAbility(cardIndex, *targetPlayer, targetCard, this->testing);
    }
    catch (const out_of_range &e)
    {
        cerr << "Index exceeds the amount of cards the active player holds1" << endl;
    }
    catch (char e)
    {
        cerr << "Not enough magic!" << endl;
    }
}

void Board::draw()
{
    if (this->testing)
    {
        try
        {
            this->currentPlayer->draw();
        }
        catch (int e)
        {
            throw e;
        }
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
            cerr << "Index exceeds the amount of cards the active player holds2" << endl;
        }
        return;
    }
    throw InvalidCommandException("discard");
}

void Board::inspect(int cardIndex)
{
    try
    {
        this->currentPlayer->inspect(cardIndex, testing);
    }
    catch (const out_of_range &e)
    {
        cerr << "Index exceeds the amount of minions the active player holds3" << endl;
    }
}

void Board::checkTrigger(TriggerType type)
{
    this->currentPlayer->checkTrigger(type, *currentPlayer, this->currentPlayer->countMinions());
}

void Board::printHand()
{
    this->currentPlayer->printCards(graphics, "hand");
}

void Board::print()
{
    if(!graphics){
        std::shared_ptr<Player> working = currentPlayer->getOpponent();
        std::cout << EXTERNAL_BORDER_CHAR_TOP_LEFT;
        for (int i = 0; i < (CENTRE_GRAPHIC.at(0).length() / EXTERNAL_BORDER_CHAR_LEFT_RIGHT.size()) - 2; ++i)
        {
            std::cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
        }
        std::cout << EXTERNAL_BORDER_CHAR_TOP_RIGHT << std::endl;
        working->printPlayer(graphics, false);
        working->printCards(graphics, "minion");
        for (auto s : CENTRE_GRAPHIC)
        {
            std::cout << s << std::endl;
        }
        working = currentPlayer;
        working->printCards(graphics, "minion");
        working->printPlayer(graphics, true);
        std::cout << EXTERNAL_BORDER_CHAR_BOTTOM_LEFT;
        for (int i = 0; i < (CENTRE_GRAPHIC.at(0).length() / EXTERNAL_BORDER_CHAR_LEFT_RIGHT.size()) - 2; ++i)
        {
            std::cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
        }
        std::cout << EXTERNAL_BORDER_CHAR_BOTTOM_RIGHT << std::endl;
    }
}

bool Board::isGraphics(){
    return graphics;
}

Board::~Board() {}

void Board::printGraphics(Xwindow &window){
    if(graphics){
        currentPlayer->getOpponent()->printGraphics(window, 71,41,false);
        currentPlayer->getOpponent()->printMinions(window, 71,166);
        currentPlayer->printMinions(window,71, 406);
        currentPlayer->printGraphics(window,71,531,true);
        currentPlayer->printHand(window, 71, 655);
    }
}
