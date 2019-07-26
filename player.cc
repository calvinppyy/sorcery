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
    if (index == 6) return this->ritual;
    return this->minions.at(index - 1);
}

void Player::playCard(int index, bool testing) {
    if (testing) {
        if (this->magic < this->hand.at((index - 1))->getPlayCost()) this->editMagic(0);
        else this->editMagic(-1*this->hand.at((index - 1))->getPlayCost());
    } else {
        if (this->magic < this->hand.at((index - 1))->getPlayCost()) return;
        else this->editMagic(-1*this->hand.at((index - 1))->getPlayCost());
    }       
    this->hand.at((index - 1))->playCard();
        if (dynamic_cast<shared_ptr<Enchantment>>(this->hand.at((index - 1))) == nullptr &&
            dynamic_cast<shared_ptr<Spell>>(this->hand.at((index - 1))) == nullptr) {
            if (dynamic_cast<shared_ptr<Ritual>>(this->hand.at((index - 1))) == nullptr) {
                if (this->minions.size() < 5) {
                    this->minions.emplace_back(this->hand.at((index - 1)));
                    this->minions.erase(this->minions.begin() + (index - 1);
                    this->checkTrigger(TriggerType::minionEnter);
                    this->opponent->checkTrigger(TriggerType::minionEnter);
                }
            } else {
                if (this->ritual == nullptr) this->ritual = this->hand.at((index - 1));
                this->minions.erase(this->minions.begin() + (index - 1);
            }
        } else this->hand.at((index - 1))->playCard(this, 0);
} //bool is for testing mode

void Player::playCard(int index, shared_ptr<Player> target, int targetIndex, bool testing) {
    if (testing) {
        if (this->magic < this->hand.at((index - 1))->getPlayCost()) this->editMagic(0);
        else this->editMagic(-1*this->hand.at((index - 1))->getPlayCost());
    } else {
        if (this->magic < this->hand.at((index - 1))->getPlayCost()) return;
        else this->editMagic(-1*this->hand.at((index - 1))->getPlayCost());
    }       
    this->hand.at((index - 1))->playCard(target, targetIndex);
        if (dynamic_cast<shared_ptr<Enchantment>>(this->hand.at((index - 1))) == nullptr &&
            dynamic_cast<shared_ptr<Spell>>(this->hand.at((index - 1))) == nullptr) {
            if (dynamic_cast<shared_ptr<Ritual>>(this->hand.at((index - 1))) == nullptr) {
                if (this->minions.size() < 5) {
                    this->minions.emplace_back(this->hand.at((index - 1)));
                    this->minions.erase(this->minions.begin() + (index - 1);
                    this->checkTrigger(TriggerType::minionEnter, this, this->minion.size());
                    this->opponent->checkTrigger(TriggerType::minionEnter, this, this->minion.size());
                }
            } else {
                if (this->ritual == nullptr) this->ritual = this->hand.at((index - 1));
                this->hand.erase(this->hand.begin() + (index - 1));
            }
        } else this->hand.at((index - 1))->playCard(target, targetIndex);
}

void Player::useAbility(int index, bool testing) {
    if (testing) {
        if (this->magic < this->hand.at((index - 1))->getPlayCost()) this->editMagic(0);
        else this->editMagic(-1*this->hand.at((index - 1))->getPlayCost());
    } else {
        if (this->magic < this->hand.at((index - 1))->getPlayCost()) return;
        else this->editMagic(-1*this->hand.at((index - 1))->getPlayCost());
    }   
    this->minions.at((index - 1))->cast(this, 0);
} //bool is for testing mode

void Player::useAbility(int index, shared_ptr<Player> target, int targetIndex, bool testing) {
    if (testing) {
        if (this->magic < this->hand.at((index - 1))->getPlayCost()) this->editMagic(0);
        else this->editMagic(-1*this->hand.at((index - 1))->getPlayCost());
    } else {
        if (this->magic < this->hand.at((index - 1))->getPlayCost()) return;
        else this->editMagic(-1*this->hand.at((index - 1))->getPlayCost());
    }
    this->minions.at((index - 1))->cast(target, targetIndex);   
}

void Player::draw() {
    if (this->notOut.empty()) throw "There is no more card in the deck";
    this->hand.emplace_back(this->notOut.back());
    this->notOut.pop_back();
}

void Player::discard(int index) {
    if (index == 6) this->ritual = nullptr;
    this->hand.erase(this->hand.begin()+(index-1));
}

void Player::inspect(int index) {
    this->minion.at(index - 1)->inspect();
} 

void Player::shuffle() {

}

void Player::takeAttack(int damage) {
    this->health -= damage;
}                            //agianst player

void Player::attack(int index) {
    this->opponent->takeAttack(this->minions.at(index - 1)->getAttack());
}                                 // against player

void Player::takeAttack(int enemyIndex, int damage, int index, int attackType) {
    this->minions.at(index - 1)->editDefence(-1*damage);
    if (this->minions.at(index - 1)->getDefense() <= 0) {
        this->killMinion((index - 1));
        this->checkTrigger(TriggerType::minionLeave);
    }
    if (attackType == 0) {
        this->attack(index, this->minions.at(index - 1)->getAttack(), enemyIndex, 1);
    }
} // against minion, attackType indicates if the minion is actively attacking or counter-attack

void Player::attack(int index, int enemyIndex, int attackType) {
    this->opponent->takeAttack(index, this->minions.at(index - 1)->getAttack(), enemyIndex, 0);
}                             // against minion, the 3rd int indicates if the minion is actively attacking or counter-attack

void Player::killMinion(int index) {
    this->graveyard.emplace_back(this->minions.at(index - 1));
    this->minions.erase(this->minions.begin() + (index - 1));
}

void Player::reviveMinion() {
    if (this->minions.size() < 5) {
        this->minions.emplace_back(this->graveyard.back());
        this->minions.back()->editDefence((-1)*this->minions.back()->getDefence())
        this->minions.back()->editDefence(1);
    }
    this->graveyard.pop_back();
}

void Player::allEditDefence(int value) {
    for (int i = 0; i < this->minions.size(); i++) {
        this->minions.at(i)->editDefence(value);
    }
}

void Player::checkTrigger(TriggerType type) {
    for (int i = 0; i < this->minions.size(); i++) {
        this->minions.at(i)->checkTrigger(type);
    }
    this->ritual->checkTrigger(type);
}

void Player::summonCard(int count, string name) {
    for (int i = 0; i < count ; i++) {
        if (this->minions.size() == 5) return;

    }
}

shared_ptr<Player> Player::getOpponent() {
    return this->opponent;
}

void Player::editMagic(int value) {
    this->magic += value;
    if (this->magic > this->magicCap) this->magic = this->magicCap;
}

void Player::unsummonCard(int index) {

}

void Player::editRitualUsage(int value) {
    if (this->ritual == nullptr) return;
    this->ritual->editUsage(value);
}

////////////////////////////////shuffle and summon and unsummon are not finished