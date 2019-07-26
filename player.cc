#include "player.h"

using namespace std;

Player::Player(vector<shared_ptr<Card>> notOut, string name = ""):
name{name}, minions{vector<shared_ptr<Card>>}, rituals{vector<shared_ptr<Card>>}, graveyard{vector<shared_ptr<Card>>}, notOut{notOut},
health{20}, magic{1}, magicCap{1} {}

Player::~Player() {}

void Player::giveName(string name) {
    this->name = name;
}

void Player::setOpponent(shared_ptr<Player> opponent) {
    this->opponent = opponent;
}

void Player::giveDeck(vector<shared_ptr<Card>> deck) {
    this->notOut = deck;
}

bool Player::died() {
    return this->health <= 0;
}

shared_ptr<Card> Player::getIthMinion(int index) {
    return this->minions.at(index);
}

void Player::playCard(int index, bool testing) {
    if (testing) {
        if (this->magic < this->hand.at(index)->getPlayCost()) this->editMagic(0);
        else this->editMagic(-1*this->hand.at(index)->getPlayCost());
    } else {
        if (this->magic < this->hand.at(index)->getPlayCost()) return;
        else this->editMagic(-1*this->hand.at(index)->getPlayCost());
    }       
    this->hand.at(index)->playCard();
        if (dynamic_cast<shared_ptr<Enchantment>>(this->hand.at(index)) == nullptr &&
            dynamic_cast<shared_ptr<Spell>>(this->hand.at(index)) == nullptr) {
            if (dynamic_cast<shared_ptr<Ritual>>(this->hand.at(index)) == nullptr) {
                if (this->minions.size() < 5) {
                    this->minions.emplace_back(this->hand.at(index));
                    this->minions.erase(this->minions.begin() + index);
                }
            } else {
                if (this->ritual == nullptr) this->ritual = this->hand.at(index);
                this->minions.erase(this->minions.begin() + index);
            }
        } else this->hand.at(index)->playCard();
} //bool is for testing mode

void Player::playCard(int index, shared_ptr<Player> target, int targetIndex, bool testing) {
    if (testing) {
        if (this->magic < this->hand.at(index)->getPlayCost()) this->editMagic(0);
        else this->editMagic(-1*this->hand.at(index)->getPlayCost());
    } else {
        if (this->magic < this->hand.at(index)->getPlayCost()) return;
        else this->editMagic(-1*this->hand.at(index)->getPlayCost());
    }       
    this->hand.at(index)->playCard(target, targetIndex);
        if (dynamic_cast<shared_ptr<Enchantment>>(this->hand.at(index)) == nullptr &&
            dynamic_cast<shared_ptr<Spell>>(this->hand.at(index)) == nullptr) {
            if (dynamic_cast<shared_ptr<Ritual>>(this->hand.at(index)) == nullptr) {
                if (this->minions.size() < 5) {
                    this->minions.emplace_back(this->hand.at(index));
                    this->minions.erase(this->minions.begin() + index);
                }
            } else {
                if (this->ritual == nullptr) this->ritual = this->hand.at(index);
                this->hand.erase(this->hand.begin() + index);
            }
        } else this->hand.at(index)->playCard(target, targetIndex);
}
void Player::useAbility(int index, bool testing) {
    if (testing) {
        if (this->magic < this->hand.at(index)->getPlayCost()) this->editMagic(0);
        else this->editMagic(-1*this->hand.at(index)->getPlayCost());
    } else {
        if (this->magic < this->hand.at(index)->getPlayCost()) return;
        else this->editMagic(-1*this->hand.at(index)->getPlayCost());
    }   
    this->minions.at(index)->cast(???);
} //bool is for testing mode
void Player::useAbility(int index, shared_ptr<Player> target, int targetIndex, bool testing) {
    if (testing) {
        if (this->magic < this->hand.at(index)->getPlayCost()) this->editMagic(0);
        else this->editMagic(-1*this->hand.at(index)->getPlayCost());
    } else {
        if (this->magic < this->hand.at(index)->getPlayCost()) return;
        else this->editMagic(-1*this->hand.at(index)->getPlayCost());
    }
    this->minions.at(index)->cast(target, targetIndex);   
}
void Player::draw();
void Player::discard();
void Player::inspect(int);
void Player::shuffle();
void Player::takeAttack(int damage);                            //agianst player
void Player::attack(int index);                                 // against player
void Player::takeAttack(int damage, int index, int attackType); // against minion, attackType indicates if the minion is actively attacking or counter-attack
void Player::attack(int, int, int);                             // against minion, the 3rd int indicates if the minion is actively attacking or counter-attack
void Player::killMinion(int);
void Player::reviveMinion(int);
void Player::allEditDefense(int);
void Player::checkTrigger(TriggerType);
void Player::summonCard(int count, string name);
shared_ptr<Player> Player::getOpponent();
void Player::editMagic(int );