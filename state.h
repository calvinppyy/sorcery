#ifndef STATE_H
#define STATE_H

enum class StateType { PlayCard, Dying, Attack, Ability };
enum class LocationType { Hand, Minions, Rituals, Graveyard, NotOut};
enum class CardType { Minion, Ritual, Spell, Enchantment };

struct State {
    bool willIDie;
    StateType type;
    LocationType location;
    int numInLocation;
    CardType cType;
    State(bool willIDie, StateType type, LocationType location, int numInlocation CardType cType);
};

State::State(bool willIDie, StateType type, LocationType location, int numInlocation CardType cType):
willIDie{willIDie}, type{type}, location{location}, numInLocation{numInLocation}, cType{cType}{}

#endif
