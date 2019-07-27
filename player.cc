#include "player.h"

using namespace std;

Player::Player(vector<shared_ptr<Card>> notOut, string name)
{
    this->name = name;
    this->notOut = notOut;
    health = 20;
    magic = 1;
    magicCap = 1;
}

Player::~Player() {}

void Player::giveName(string name)
{
    this->name = name;
}

void Player::setOpponent(shared_ptr<Player> opponent)
{
    this->opponent = opponent;
}

void Player::giveDeck(vector<shared_ptr<Card>> deck)
{
    this->notOut = deck;
}

bool Player::died()
{
    return this->health <= 0;
}

shared_ptr<Card> &Player::getIthMinion(int index)
{
    if (index == 6)
        return this->ritual;
    return this->minions.at(index - 1);
}

void Player::playCard(int index, bool testing)
{
    if (testing)
    {
        if (this->magic < this->hand.at((index - 1))->getPlayCost())
            this->editMagic(0);
        else
            this->editMagic(-1 * this->hand.at((index - 1))->getPlayCost());
    }
    else
    {
        if (this->magic < this->hand.at((index - 1))->getPlayCost())
            return;
        else
            this->editMagic(-1 * this->hand.at((index - 1))->getPlayCost());
    }
    if (dynamic_pointer_cast<Enchantment>(this->hand.at((index - 1))) == nullptr && //bug
        dynamic_pointer_cast<Spell>(this->hand.at((index - 1))) == nullptr)
    { //bug
        if (dynamic_pointer_cast<Ritual>(this->hand.at((index - 1))) == nullptr)
        { //bug
            if (this->minions.size() < 5)
            {
                this->minions.emplace_back(this->hand.at((index - 1)));
                this->minions.erase(this->minions.begin() + (index - 1));
                this->checkTrigger(TriggerType::minionEnter, make_shared<Player>(*this), this->minions.size());
                this->opponent->checkTrigger(TriggerType::minionEnter, make_shared<Player>(*this), this->minions.size());
            }
        }
        else
        {
            if (this->ritual == nullptr)
                this->ritual = this->hand.at((index - 1));
            this->minions.erase(this->minions.begin() + (index - 1));
        }
    }
    else
        this->hand.at((index - 1))->playCard(make_shared<Player>(*this), 0);
} //bool is for testing mode

void Player::playCard(int index, shared_ptr<Player> target, int targetIndex, bool testing)
{
    if (testing)
    {
        if (this->magic < this->hand.at((index - 1))->getPlayCost())
            this->editMagic(0);
        else
            this->editMagic(-1 * this->hand.at((index - 1))->getPlayCost());
    }
    else
    {
        if (this->magic < this->hand.at((index - 1))->getPlayCost())
            return;
        else
            this->editMagic(-1 * this->hand.at((index - 1))->getPlayCost());
    }
    if (dynamic_pointer_cast<Enchantment>(this->hand.at((index - 1))) == nullptr && //'shared_ptr<Enchantment> is not a reference or pointer
        dynamic_pointer_cast<Spell>(this->hand.at((index - 1))) == nullptr)
    { //same as above
        if (dynamic_pointer_cast<Ritual>(this->hand.at((index - 1))) == nullptr)
        { //same as above
            if (this->minions.size() < 5)
            {
                this->minions.emplace_back(this->hand.at((index - 1)));
                this->minions.erase(this->minions.begin() + (index - 1));
                this->checkTrigger(TriggerType::minionEnter, make_shared<Player>(*this), this->minions.size());
                this->opponent->checkTrigger(TriggerType::minionEnter, make_shared<Player>(*this), this->minions.size());
            }
        }
        else
        {
            if (this->ritual == nullptr)
                this->ritual = this->hand.at((index - 1));
            this->hand.erase(this->hand.begin() + (index - 1));
        }
    }
    else
        this->hand.at((index - 1))->playCard(target, targetIndex);
}

void Player::useAbility(int index, bool testing){
    int tmp;
    if (testing)
    {
        if (this->magic < this->hand.at((index - 1))->getPlayCost())
        {
            tmp = this->magic;
            this->editMagic(0);
        }
        else
        {
            tmp = this->hand.at((index - 1))->getPlayCost();
            this->editMagic(-1 * this->hand.at((index - 1))->getPlayCost());
        }
    }
    else
    {
        if (this->magic < this->hand.at((index - 1))->getPlayCost())
            return;
        else
            this->editMagic(-1 * this->hand.at((index - 1))->getPlayCost());
    }
    try
    {
        this->minions.at((index - 1))->cast(make_shared<Player>(*this), 0);
    }
    catch (string e)
    {
        if (testing)
            this->editMagic(tmp);
        else
            this->editMagic(this->hand.at((index - 1))->getPlayCost());
    }
} //bool is for testing mode

void Player::useAbility(int index, shared_ptr<Player> target, int targetIndex, bool testing)
{
    if (testing)
    {
        if (this->magic < this->hand.at((index - 1))->getPlayCost())
            this->editMagic(0);
        else
            this->editMagic(-1 * this->hand.at((index - 1))->getPlayCost());
    }
    else
    {
        if (this->magic < this->hand.at((index - 1))->getPlayCost())
            return;
        else
            this->editMagic(-1 * this->hand.at((index - 1))->getPlayCost());
    }
    this->minions.at((index - 1))->cast(target, targetIndex);
}

void Player::draw()
{
    if (this->notOut.empty())
        throw "There is no more card in the deck";
    this->hand.emplace_back(this->notOut.back());
    this->notOut.pop_back();
}

void Player::discard(int index)
{
    if (index == 6)
        this->ritual = nullptr;
    this->hand.erase(this->hand.begin() + (index - 1));
}

void Player::inspect(int index, bool testing)
{
    this->minions.at(index - 1)->inspect(testing);
}

void Player::shuffleDeck()
{
    auto rng = default_random_engine{};
    shuffle(this->notOut.begin(), this->notOut.end(), rng); //DELETE THE RNG CLASS IF THIS WORKS, USED <algorithm> && <random>, INCLUDED IN player.h
}

void Player::takeAttack(int damage)
{
    this->health -= damage;
} //agianst player

void Player::attack(int index)
{
    this->opponent->takeAttack(this->minions.at(index - 1)->getAttack());
} // against player

void Player::takeAttack(int enemyIndex, int damage, int index, int attackType)
{
    this->minions.at(index - 1)->editDefence(-1 * damage);
    if (this->minions.at(index - 1)->getDefence() <= 0)
    {
        this->killMinion((index - 1));
        this->checkTrigger(TriggerType::minionLeave, make_shared<Player>(*this), this->minions.size());
    }
    if (attackType == 0)
    {
        this->attack(index, this->minions.at(index - 1)->getAttack(), enemyIndex, 1);
    }
} // against minion, attackType indicates if the minion is actively attacking or counter-attack

void Player::attack(int index, int damage, int enemyIndex, int attackType)
{
    this->opponent->takeAttack(index, this->minions.at(index - 1)->getAttack(), enemyIndex, 0);
} // against minion, the 3rd int indicates if the minion is actively attacking or counter-attack

void Player::killMinion(int index)
{
    this->graveyard.emplace_back(this->minions.at(index - 1));
    this->minions.erase(this->minions.begin() + (index - 1));
}

void Player::reviveMinion()
{
    if (this->minions.size() < 5)
    {
        this->minions.emplace_back(this->graveyard.back());
        this->minions.back()->editDefence((-1) * this->minions.back()->getDefence());
        this->minions.back()->editDefence(1);
    }
    this->graveyard.pop_back();
}

void Player::allEditDefence(int value)
{
    for (int i = 0; i < this->minions.size(); i++)
    {
        this->minions.at(i)->editDefence(value);
    }
}

void Player::checkTrigger(TriggerType type, std::shared_ptr<Player> player, int index)
{
    for (int i = 0; i < this->minions.size(); i++)
    {
        this->minions.at(i)->checkTrigger(type, player, index);
    }
    this->ritual->checkTrigger(type, player, index);
}

void Player::summonCard(int count, string name)
{
    for (int i = 0; i < count; i++)
    {
        if (this->minions.size() == 5)
            return;
        this->minions.emplace_back(make_shared<Minion>(name, make_shared<Player>(*this)));
    }
}

shared_ptr<Player> &Player::getOpponent()
{
    return this->opponent;
}

void Player::editMagic(int value)
{
    this->magic += value;
    if (this->magic > this->magicCap)
        this->magic = this->magicCap;
}

void Player::unsummonCard(int index)
{
    this->hand.emplace_back(this->minions.at(index - 1));
    this->minions.erase(this->minions.begin() + (index - 1));
}

void Player::editRitualUsage(int value)
{
    if (this->ritual == nullptr)
        return;
    this->ritual->editUsage(value);
}

int Player::countMinions()
{
    return this->minions.size();
}

void Player::printHand(bool graphics){
    for(int i = 0; i<hand.size(); i++){
        hand[i]->print(graphics);
    }
}
