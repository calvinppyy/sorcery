#ifndef cardprintmap_h
#define cardprintmap_h

#include <memory>
#include <map>

std::map<std::string, int> cardNameToFunc;

cardNameToFunc["Air Elemental"] = 0;
cardNameToFunc["Earth Elemental"] = 0;
cardNameToFunc["Bone Golem"] = 0;
cardNameToFunc["Fire Elemental"] = 0;
cardNameToFunc["Potion Seller"] = 0;
cardNameToFunc["Novice Pyromancer"] = 1;
cardNameToFunc["Apprentice Summoner"] = 1;
cardNameToFunc["Master Summoner"] = 1;
cardNameToFunc["Banish"] = 2;
cardNameToFunc["Unsummon"] = 2;
cardNameToFunc["Recharge"] = 2;
cardNameToFunc["Disenchant"] = 2;
cardNameToFunc["Raise Dead"] = 2;
cardNameToFunc["Blizzard"] = 2;
cardNameToFunc["Dark Ritual"] = 5;
cardNameToFunc["Aura of Power"] = 5;
cardNameToFunc["Standstill"] = 5;
cardNameToFunc["Giant Strength"] = 3;
cardNameToFunc["Enrage"] = 3;
cardNameToFunc["Haste"] = 4;
cardNameToFunc["Magic Fatigue"] = 4;
cardNameToFunc["Silence"] = 4;

#endif
