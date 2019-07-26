#ifndef SPELL_H
#define SPELL_H
#include "card.h"

class Enchantment;
class Card;

class Spell:public Card{
    int playCost;
public:
    Spell(std::string name, std::shared_ptr<Player> owner);
    void silence(bool);
    void playCard(std::shared_ptr<Player> target, int index);
    void addEnchantment(std::shared_ptr<Enchantment> echantment);
    void popEnchantment();
    void clearEnchantment();
    void cast(std::shared_ptr<Player> opponent, int index);
    void inspect(bool graphicsEnabled);
    void print(bool graphicsEnabled);
    std::string getDescription();
    int getDefence();
    void editDefence(int defence);
    int getPlayCost();
    void editPlayCost(int playCost);
    int getAttack();
    void editAttack(int attack);
    int getAbilityCost(); //ritual, minion
    void editAbilityCost(int ac); //ritual minion
    int getUsage(); //for ritual
    void editUsage(int); //for ritual
    int getAction();
    void editAction(int action);
    bool died();
    void checkTrigger(TriggerType trigger,std::shared_ptr<Player> opponent, int index);
};

#endif
