#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"
#include "minion.h"
#include "spell.h"
#include "enchantment.h"
#include "ritual.h"
#include <algorithm>
#include <random>
#include <map>

class Card;

class Player{
    std::string name;
    std::shared_ptr<Player> opponent;
    std::vector<std::shared_ptr<Card>> hand;
    std::vector<std::shared_ptr<Card>> minions;
    std::shared_ptr<Card> ritual;
    std::vector<std::shared_ptr<Card>> graveyard;
    std::vector<std::shared_ptr<Card>> notOut;
    int health;
    int magic;
    int magicCap;
public:
    Player(std::vector<std::shared_ptr<Card>>, std::string name = "");
    ~Player();
    void giveName(std::string );
    void setOpponent(std::shared_ptr<Player> );
    void giveDeck(std::vector<std::shared_ptr<Card>> );
    bool died();
    std::shared_ptr<Card> &getIthMinion(int );
    void playCard(int, bool); //bool is for testing mode
    void playCard(int, std::shared_ptr<Player>, int, bool);
    void useAbility(int, bool); //bool is for testing mode
    void useAbility(int, std::shared_ptr<Player>, int, bool);
    void draw();
    void discard(int);
    void inspect(int,bool);
    void shuffleDeck();
    void takeAttack(int ); //agianst player
    void attack(int ); // against player
    void takeAttack(int ,int, int , int ); // against minion, attackType indicates if the minion is actively attacking or counter-attack
    void attack(int, int, int, int); // against minion, the 3rd int indicates if the minion is actively attacking or counter-attack
    void killMinion(int );
    void reviveMinion( );
    void allEditDefence(int );
    void checkTrigger(TriggerType, std::shared_ptr<Player>, int);
    void summonCard(int , std::string );
    std::shared_ptr<Player> &getOpponent();
    void editMagic(int );
    void unsummonCard(int );
    void editRitualUsage(int );
    int countMinions();
    void printCards(bool graphics, std::string w);
};

std::map<std::string, int> whichFunc();

#endif
