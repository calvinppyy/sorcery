#ifndef STATE_H
#define STATE_H

enum class StateType { PlayCard, Dying, Return, Attack, Ability };
enum class LocationType { Hand, Minions, Rituals, Graveyard, NotOut};
enum class CardType { Minion, Ritual, Spell, Enchantment };

struct State {
    bool willIDie;
    StateType type;
    LocationType location;
    int numInLocation;
};

#endif
