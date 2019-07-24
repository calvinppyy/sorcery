#ifndef STATE_H
#define STATE_H

enum class StateType { PlayCard, Dying, Return, Attack };
enum class LocationType { Hand, Minions, Rituals, Graveyard, NotOut };
enum class cardType { Minion, Ritual, Spell, Enchantment };

struct State {
    StateType type;
    LocationType location;
    int numInLocation;
    cardType cType;
};

#endif
