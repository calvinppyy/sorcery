#include "player.h"

Player::Player(std::string name, std::unique_ptr<Deck> notOut): name{name}, minions{nullptr},
rituals{nullptr},graveyard{nullptr}, notOut{std::move(notOut)},
health{20}, healthCap{20}, magic{1}, magicCap{1}{}
