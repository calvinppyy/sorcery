#include "player.h"

Player::Player(std::string name, std::unique_ptr<Deck> notOut): name{name}, minions{nullptr},
rituals{nullptr},graveyard{nullptr}, notOut{std::move(notOut)},
health{20}, healthCap{20}, magic{1}, magicCap{1}{}

void Player::giveName(std::string name){
    this->name = name;
}

void Player::giveDeck(std::unique_ptr<Deck> &deck, std::string what){
    if(what == "hand") hand = std::move(deck);
    if(what == "minions") minions = std::move(deck);
    if(what == "rituals") rituals = std::move(deck);
    if(what == "graveyard") graveyard = std::move(deck);
    if(what == "notOut") notOut = std::move(deck);
}
